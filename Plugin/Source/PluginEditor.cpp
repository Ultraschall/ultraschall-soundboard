/*
 ==============================================================================

 PluginEditor.cpp
 Author:  Daniel Lindenfelser

 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

SoundboardAudioProcessorEditor::SoundboardAudioProcessorEditor(SoundboardAudioProcessor &p)
        : AudioProcessorEditor(&p), processor(p), mPauseState(true), mTimerState(true)
{
    addAndMakeVisible(topBar = new Bar());

    addAndMakeVisible(loadDirectoryButton = new TextButton());
    loadDirectoryButton->setButtonText(FontAwesome_Folder_Open_O);
    loadDirectoryButton->setLookAndFeel(awesomeLookAndFeel);
    loadDirectoryButton->addListener(this);

    addAndMakeVisible(listButton = new TextButton());
    listButton->setLookAndFeel(awesomeLookAndFeel);
    listButton->setButtonText(FontAwesome_List);
    listButton->addListener(this);
    listButton->setConnectedEdges(TextButton::ConnectedOnRight);

    addAndMakeVisible(gridButton = new TextButton());
    gridButton->setLookAndFeel(awesomeLookAndFeel);
    gridButton->setButtonText(FontAwesome_Th);
    gridButton->addListener(this);
    gridButton->setConnectedEdges(TextButton::ConnectedOnLeft | TextButton::ConnectedOnRight);

    addAndMakeVisible(settingsButton = new TextButton());
    settingsButton->setLookAndFeel(awesomeLookAndFeel);
    settingsButton->setButtonText(FontAwesome_Cog);
    settingsButton->addListener(this);
    settingsButton->setConnectedEdges(TextButton::ConnectedOnLeft);

    addAndMakeVisible(table = new SoundboardTableComponent(p));
    listButton->setEnabled(false);

    addAndMakeVisible(grid = new SoundboardGridComponent(p));
    grid->setVisible(false);
    grid->toBack();
    addAndMakeVisible(settings = new SoundboardSettingsComponent(p));
    settings->setVisible(false);
    settings->toBack();

    if (processor.wrapperType != AudioProcessor::wrapperType_Standalone)
    {
        addAndMakeVisible(resizableCornerComponent = new ResizableCornerComponent(this, &resizeLimits));
        resizeLimits.setSizeLimits(380, 320, 1024, 768);
    }

    refresh();

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(processor.getWindowWidth(), processor.getWindowHeight());

    startTimer(TimerIdBlink, static_cast<int>(1000 * 0.5));
    startTimer(TimerIdUpdate, 50);
    startTimer(TimerIdRefresh, static_cast<int>(1000 * 0.5));
}

SoundboardAudioProcessorEditor::~SoundboardAudioProcessorEditor()
{
    stopTimer(TimerIdBlink);
    stopTimer(TimerIdUpdate);
    stopTimer(TimerIdRefresh);
    topBar              = nullptr;
    loadDirectoryButton = nullptr;
    table               = nullptr;
    grid                = nullptr;
    resizableCornerComponent = nullptr;
    settingsButton      = nullptr;
    gridButton          = nullptr;
}

void SoundboardAudioProcessorEditor::paint(Graphics &g)
{
    g.fillAll(ThemeBackground1);
}

void SoundboardAudioProcessorEditor::resized()
{
    topBar->setBounds(0, 0, getWidth(), 32);

    loadDirectoryButton->setBounds(5, 5, 60, 24);

    listButton->setBounds(getWidth() - 185, 5, 60, 24);
    gridButton->setBounds(getWidth() - 125, 5, 60, 24);
    settingsButton->setBounds(getWidth() - 65, 5, 60, 24);

    table->setBounds(0, 32, getWidth(), getHeight() - 32);
    grid->setBounds(0, 32, getWidth(), getHeight() - 32);
    settings->setBounds(0, 32, getWidth(), getHeight() - 32);

    if (resizableCornerComponent)
    {
        resizableCornerComponent->setBounds(getWidth() - 16, getHeight() - 16, 16, 16);
    }

    processor.storeWindowWidth(getWidth());
    processor.storeWindowHeight(getHeight());
}

void SoundboardAudioProcessorEditor::buttonClicked(Button *buttonThatWasClicked)
{
    if (loadDirectoryButton == buttonThatWasClicked)
    {
        FileChooser chooser("Open...");
        if (chooser.browseForDirectory())
        {
            auto directory = chooser.getResult();
            if (directory.isDirectory())
            {
                processor.openDirectory(directory);
                table->updateContent();
                grid->updateContent();
            }
        }
    }
    else if (settingsButton == buttonThatWasClicked)
    {
        settingsButton->setEnabled(false);
        listButton->setEnabled(true);
        gridButton->setEnabled(true);

        table->setVisible(false);
        grid->setVisible(false);
        settings->setVisible(true);
        settings->toFront(true);
        if (resizableCornerComponent)
        {
            resizableCornerComponent->toFront(false);
        }
    }
    else if (gridButton == buttonThatWasClicked)
    {
        gridButton->setEnabled(false);
        listButton->setEnabled(true);
        settingsButton->setEnabled(true);

        settings->setVisible(false);
        table->setVisible(false);
        grid->setVisible(true);
        grid->toFront(true);
        if (resizableCornerComponent)
        {
            resizableCornerComponent->toFront(false);
        }
    }
    else if (listButton == buttonThatWasClicked)
    {
        listButton->setEnabled(false);
        gridButton->setEnabled(true);
        settingsButton->setEnabled(true);

        settings->setVisible(false);
        grid->setVisible(false);
        table->setVisible(true);
        table->toFront(true);
        if (resizableCornerComponent)
        {
            resizableCornerComponent->toFront(false);
        }
    }
}

void SoundboardAudioProcessorEditor::timerCallback(int timerID)
{
    if (timerID == TimerIdUpdate)
    {
    }
    else if (timerID == TimerIdRefresh)
    {
        refresh();
    }
}

void SoundboardAudioProcessorEditor::refresh()
{
    if (!processor.isLoocked())
    {
        table->updateContent();
    }
}

void SoundboardAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    auto index = slider->getName().getIntValue();
    processor.setGain(index, static_cast<float>(slider->getValue()));
}
