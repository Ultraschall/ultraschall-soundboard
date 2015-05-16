#include "JuceHeader.h"
#include "StandaloneFilterWindow.h"

Component *createMainContentComponent();

ScopedPointer<AudioDeviceManager> deviceManager = new AudioDeviceManager();

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
        mainWindow->setResizable(true, true);
        mainWindow->setResizeLimits(480, 320, INT_MAX, INT_MAX);
        mainWindow->setVisible(true);
        mainWindow->setUsingNativeTitleBar(true);
    }

    void shutdown() override
    {
        mainWindow = nullptr; // (deletes our window)
        deviceManager = nullptr;
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
