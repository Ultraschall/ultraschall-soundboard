#include "JuceHeader.h"
#include "StandaloneFilterWindow.h"

Component *createMainContentComponent();

class SoundboardApplication : public JUCEApplication
{
public:
    SoundboardApplication()
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

    void initialise(const String & /*commandLine*/) override
    {
        mainWindow = new StandaloneFilterWindow(getApplicationName(), Colours::black, new PropertySet(), true);
        mainWindow->setResizeLimits(380, 320, 1024, 768);
        mainWindow->setUsingNativeTitleBar(true);
        mainWindow->setResizable(true, true);
        mainWindow->setVisible(true);
    }

    void shutdown() override
    {
        mainWindow = nullptr; // (deletes our window)
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

private:
    ScopedPointer<StandaloneFilterWindow> mainWindow;
};

START_JUCE_APPLICATION (SoundboardApplication)
