#ifndef JUCE_STANDALONEFILTERWINDOW_H_INCLUDED
#define JUCE_STANDALONEFILTERWINDOW_H_INCLUDED

extern AudioProcessor *JUCE_CALLTYPE createPluginFilter();
extern ScopedPointer<AudioDeviceManager> deviceManager;

class StandalonePluginHolder
{
public:
    StandalonePluginHolder(PropertySet *settingsToUse, bool takeOwnershipOfSettings)
        : settings(settingsToUse, takeOwnershipOfSettings)
    {
        createPlugin();
        setupAudioDevices();
        reloadPluginState();
        startPlaying();
    }

    ~StandalonePluginHolder()
    {
        deletePlugin();
        shutDownAudioDevices();
    }

    void createPlugin()
    {
        AudioProcessor::setTypeOfNextNewPlugin(AudioProcessor::wrapperType_Standalone);
        processor = createPluginFilter();
        jassert (processor != nullptr); // Your createPluginFilter() function must return a valid object!
        AudioProcessor::setTypeOfNextNewPlugin(AudioProcessor::wrapperType_Undefined);

        processor->setPlayConfigDetails(0, 2, 44100, 512);
    }

    void deletePlugin()
    {
        stopPlaying();
        processor = nullptr;
    }

    static String getFilePatterns(const String &fileSuffix)
    {
        if (fileSuffix.isEmpty())
            return String();

        return (fileSuffix.startsWithChar('.') ? "*" : "*.") + fileSuffix;
    }

    File getLastFile() const
    {
        File f;

        if (settings != nullptr)
            f = File(settings->getValue("lastStateFile"));

        if (f == File::nonexistent)
            f = File::getSpecialLocation(File::userDocumentsDirectory);

        return f;
    }

    void setLastFile(const FileChooser &fc)
    {
        if (settings != nullptr)
            settings->setValue("lastStateFile", fc.getResult().getFullPathName());
    }

    /** Pops up a dialog letting the user save the processor's state to a file. */
    void askUserToSaveState(const String &fileSuffix = String())
    {
        FileChooser fc(TRANS("Save current state"), getLastFile(), getFilePatterns(fileSuffix));

        if (fc.browseForFileToSave(true))
        {
            setLastFile(fc);

            MemoryBlock data;
            processor->getStateInformation(data);

            if (! fc.getResult().replaceWithData(data.getData(), data.getSize()))
                AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                            TRANS("Error whilst saving"),
                                            TRANS("Couldn't write to the specified file!"));
        }
    }

    /** Pops up a dialog letting the user re-load the processor's state from a file. */
    void askUserToLoadState(const String &fileSuffix = String())
    {
        FileChooser fc(TRANS("Load a saved state"), getLastFile(), getFilePatterns(fileSuffix));

        if (fc.browseForFileToOpen())
        {
            setLastFile(fc);

            MemoryBlock data;

            if (fc.getResult().loadFileAsData(data))
                processor->setStateInformation(data.getData(), static_cast<int>(data.getSize()));
            else
                AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                            TRANS("Error whilst loading"),
                                            TRANS("Couldn't read from the specified file!"));
        }
    }

    void startPlaying()
    {
        player.setProcessor(processor);
    }

    void stopPlaying()
    {
        player.setProcessor(nullptr);
    }

    void saveAudioDeviceState()
    {
        if (settings != nullptr)
        {
            ScopedPointer<XmlElement> xml(deviceManager->createStateXml());
            settings->setValue("audioSetup", xml);
        }
    }

    void reloadAudioDeviceState()
    {
        ScopedPointer<XmlElement> savedState;

        if (settings != nullptr)
            savedState = settings->getXmlValue("audioSetup");

        deviceManager->initialise(processor->getNumInputChannels(), processor->getNumOutputChannels(), savedState, true);
    }

    void savePluginState()
    {
        if (settings != nullptr && processor != nullptr)
        {
            MemoryBlock data;
            processor->getStateInformation(data);

            settings->setValue("filterState", data.toBase64Encoding());
        }
    }

    void reloadPluginState()
    {
        if (settings != nullptr)
        {
            MemoryBlock data;

            if (data.fromBase64Encoding(settings->getValue("filterState")) && data.getSize() > 0)
                processor->setStateInformation(data.getData(), static_cast<int>(data.getSize()));
        }
    }

    OptionalScopedPointer<PropertySet> settings;
    ScopedPointer<AudioProcessor>      processor;
    AudioProcessorPlayer               player;

private:
    void setupAudioDevices()
    {
        deviceManager->addAudioCallback(&player);
        deviceManager->addMidiInputCallback(String::empty, &player);

        reloadAudioDeviceState();
    }

    void shutDownAudioDevices()
    {
        saveAudioDeviceState();

        deviceManager->removeMidiInputCallback(String::empty, &player);
        deviceManager->removeAudioCallback(&player);
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StandalonePluginHolder)
};

class StandaloneFilterWindow : public DocumentWindow
{
public:
    StandaloneFilterWindow(const String &title,
                           Colour backgroundColour,
                           PropertySet *settingsToUse,
                           bool takeOwnershipOfSettings) : DocumentWindow(title, backgroundColour, minimiseButton | closeButton | maximiseButton)
    {
        pluginHolder = new StandalonePluginHolder(settingsToUse, takeOwnershipOfSettings);

        createEditorComp();

        if (PropertySet *props = pluginHolder->settings)
        {
            const auto x = props->getIntValue("windowX", -100);
            const auto y = props->getIntValue("windowY", -100);

            if (x != -100 && y != -100)
                setBoundsConstrained(Rectangle<int>(x, y, getWidth(), getHeight()));
            else
                centreWithSize(getWidth(), getHeight());
        }
        else
        {
            centreWithSize(getWidth(), getHeight());
        }
    }

    ~StandaloneFilterWindow()
    {
        if (PropertySet *props = pluginHolder->settings)
        {
            props->setValue("windowX", getX());
            props->setValue("windowY", getY());
        }

        pluginHolder->stopPlaying();
        deleteEditorComp();
        pluginHolder = nullptr;
    }

    AudioProcessor *getAudioProcessor() const noexcept
    {
        return pluginHolder->processor;
    }

    void createEditorComp()
    {
        setContentOwned(getAudioProcessor()->createEditorIfNeeded(), true);
    }

    void deleteEditorComp()
    {
        if (auto ed = dynamic_cast<AudioProcessorEditor *>(getContentComponent()))
        {
            pluginHolder->processor->editorBeingDeleted(ed);
            clearContentComponent();
        }
    }

    void resetToDefaultState()
    {
        pluginHolder->stopPlaying();
        deleteEditorComp();
        pluginHolder->deletePlugin();

        if (PropertySet *props = pluginHolder->settings)
            props->removeValue("filterState");

        pluginHolder->createPlugin();
        createEditorComp();
        pluginHolder->startPlaying();
    }

    void closeButtonPressed() override
    {
        if (ModalComponentManager::getInstance()->getNumModalComponents() > 0) {
            return;
        }
        JUCEApplicationBase::quit();
    }

    ScopedPointer<StandalonePluginHolder> pluginHolder;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StandaloneFilterWindow)
};

#endif // JUCE_STANDALONEFILTERWINDOW_H_INCLUDED
