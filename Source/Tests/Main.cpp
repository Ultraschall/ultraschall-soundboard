#include "../JuceLibraryCode/JuceHeader.h"

class UnitTestApplication : public JUCEApplication
{
public:
    UnitTestApplication()
    {
    }

    const String getApplicationName() override
    {
        return ProjectInfo::projectName;
    }

    const String getApplicationVersion() override
    {
        return ProjectInfo::versionString;
    }

    bool moreThanOneInstanceAllowed() override
    {
        return true;
    }

    void initialise(const String & commandLine) override
    {
        Array<UnitTest*>& allTests = UnitTest::getAllTests();
        int numTestsPassed = 0;
        int numTestsFailed = 0;

        if (commandLine == "--list")
        {   // just list the names of all available UnitTests and quit
            for (int i=0; i<allTests.size(); i++)
            {
                std::cout << allTests[i]->getName() << "\n";
            }
            JUCEApplication::quit();
            return;
        }

        UnitTestRunner runner;
        if (commandLine.isEmpty())
        {  // run all tests defined in the includes files
            runner.runAllTests(true);   
        }
        else
        {   // parse names of the tests to run from the command line (separated by blanks)
            StringArray namesInCmdLine;
            namesInCmdLine.addTokens(commandLine, " ", "\"");         
            for (int i=0; i<namesInCmdLine.size(); i++)
            {   // test can be surrounded with quotation marks
                namesInCmdLine.set(i, namesInCmdLine[i].unquoted());
            }

            // find the tests specified in the command line
            Array<UnitTest*> testsToRun;
            for (int i=0; i<allTests.size(); i++)
            {
                int indexInCmdLine = namesInCmdLine.indexOf(allTests[i]->getName());
                if (indexInCmdLine >= 0)
                {
                    testsToRun.add(allTests[i]);
                    namesInCmdLine.remove(indexInCmdLine);
                }
            }

            // if there still names left in the list...
            if (namesInCmdLine.size() > 0)
            {   // ...mark them as failed because the test class could not be found
                std::cout << "Invalid unit-test(s) specified in command line: " << namesInCmdLine.joinIntoString(" ") << "\n";
                numTestsFailed += namesInCmdLine.size();
            }

            // run only the specified tests
            runner.runTests(testsToRun, true);
        }

        // iterate over all results
        for (int i=0; i<runner.getNumResults(); i++)
        {
            const UnitTestRunner::TestResult* result = runner.getResult(i);

            // count total passes and failures
            numTestsPassed += result->passes;
            numTestsFailed += result->failures;

            // print messages for those tests that failed
            StringArray messages = result->messages;
            for (int j=0; j<messages.size(); j++)
            {
                std::cout << result->unitTestName << ": [" << result->subcategoryName << "] " << messages[j] << "\n";
            }
        }

        if (numTestsFailed > 0)
        {   // return the number of failed tests
            JUCEApplication::getInstance()->setApplicationReturnValue(numTestsFailed);
            std::cout << numTestsFailed << " tests failed, and " << numTestsPassed << " tests were succesfull.\n";
        }
        else
        {
            std::cout << "all " << numTestsPassed << " tests passed.\n";
        }

        JUCEApplication::getInstance()->quit();

    }

    void shutdown() override
    {
    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted(const String & /*commandLine*/) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }
};


START_JUCE_APPLICATION (UnitTestApplication)