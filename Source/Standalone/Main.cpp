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
        return false;
    }

    void initialise(const String & /*commandLine*/) override
    {
        mainWindow = new StandaloneFilterWindow(getApplicationName(), Colours::black, new PropertySet(), true);
        mainWindow->setResizable(true, true);
        mainWindow->setResizeLimits(520, 120, INT_MAX, INT_MAX);
        mainWindow->setVisible(true);
        mainWindow->setUsingNativeTitleBar(true);
    }

    void shutdown() override
    {
        mainWindow = nullptr; // (deletes our window)
        deviceManager = nullptr;
    }

    void systemRequestedQuit() override
    {
        quit();
    }

private:
    ScopedPointer<StandaloneFilterWindow> mainWindow;
};

START_JUCE_APPLICATION (SoundboardApplication)
