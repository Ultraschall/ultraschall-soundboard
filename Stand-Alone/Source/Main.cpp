/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "JuceHeader.h"
#include "StandaloneFilterWindow.h"

Component* createMainContentComponent();

//==============================================================================
class SoundboardApplication  : public JUCEApplication
{
public:
    //==============================================================================
    SoundboardApplication() {}

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return true; }

    //==============================================================================
    void initialise (const String& /*commandLine*/) override
    {
        // This method is where you should put your application's initialisation code..

        mainWindow = new StandaloneFilterWindow (getApplicationName(),
                                                 Colours::black,
                                                 new PropertySet(),
                                                 true);
        mainWindow->setResizeLimits (380, 320, 1024, 768);
        mainWindow->setUsingNativeTitleBar (true);
        mainWindow->setResizable (true, true);
        mainWindow->setVisible (true);
    }

    void shutdown() override
    {
        // Add your application's shutdown code here..

        mainWindow = nullptr; // (deletes our window)
    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void anotherInstanceStarted (const String& /*commandLine*/) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

private:
    ScopedPointer<StandaloneFilterWindow> mainWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (SoundboardApplication)
