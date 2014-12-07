/*
  ==============================================================================

    OscSettings.h
    Created: 30 Nov 2014 9:59:12am
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef OSCSETTINGS_H_INCLUDED
#define OSCSETTINGS_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "LookAndFeel.h"

static const Identifier OscReciveEnabledIdentifier("OscReciveEnabled");
static const Identifier OscRecivePortNumberIdentifier("OscRecivePortNumber");

static const Identifier OscRemoteEnabledIdentifier("OscRemoteEnabled");
static const Identifier OscRemoteHostnameIdentifier("OscRemoteHostname");
static const Identifier OscRemotePortNumberIdentifier("OscRemotePortNumber");
static const Identifier OscRemoteIsTouchOscIdentifier("OscRemoteIsTouchOsc");

//==============================================================================
/*
*/
class OscSettings : public Component,
                    public Button::Listener,
                    public TextEditor::Listener,
                    public OscMessageLogger,
                    public ListBoxModel {
public:
    OscSettings(PropertiesFile* pf, OscServer* s)
        : propertiesFile(pf)
        , oscServer(s)
    {
        addAndMakeVisible(topBar = new Bar());
        addAndMakeVisible(titleLabel = new Label());
        titleLabel->setText("OSC Einstellungen", NotificationType::dontSendNotification);
        titleLabel->setColour(Label::ColourIds::textColourId, Colours::grey);
        titleLabel->setFont(Font(24.0 * 0.6));

        addAndMakeVisible(seperator = new Bar());

        addAndMakeVisible(receiveEnabled = new ToggleButton("receiveEnabled"));
        receiveEnabled->setButtonText(TRANS("Receive on port:"));
        receiveEnabled->addListener(this);
        receiveEnabled->setColour(ToggleButton::ColourIds::textColourId,
                                  Colours::grey);
        receiveEnabled->setToggleState(
            propertiesFile->getBoolValue(OscRecivePortNumberIdentifier.toString()),
            NotificationType::dontSendNotification);

        addAndMakeVisible(sendEnabled = new ToggleButton("sendEnabledButton"));
        sendEnabled->setButtonText(TRANS("Send on port:"));
        sendEnabled->addListener(this);
        sendEnabled->setColour(ToggleButton::ColourIds::textColourId,
                               Colours::grey);
        sendEnabled->setToggleState(
            propertiesFile->getBoolValue(OscRemoteEnabledIdentifier.toString()),
            NotificationType::dontSendNotification);

        addAndMakeVisible(oscLoggerEnabled = new ToggleButton("oscLoggerEnabled"));
        oscLoggerEnabled->setButtonText(TRANS("OSC Logger"));
        oscLoggerEnabled->addListener(this);
        oscLoggerEnabled->setColour(ToggleButton::ColourIds::textColourId,
                                    Colours::grey);

        addAndMakeVisible(oscLogger = new ListBox("oscLogger"));
        oscLogger->setColour(ListBox::ColourIds::backgroundColourId, Colour::fromRGB(44, 44, 44));
        oscLogger->setColour(ListBox::ColourIds::outlineColourId, Colour::fromRGB(44, 44, 44));
        oscLogger->setColour(ListBox::ColourIds::textColourId, Colours::whitesmoke);
        oscLogger->setModel(this);

        addAndMakeVisible(receivePortNumber = new TextEditor("receivePortNumber"));
        receivePortNumber->setMultiLine(false);
        receivePortNumber->setReturnKeyStartsNewLine(false);
        receivePortNumber->setReadOnly(receiveEnabled->getToggleState());
        receivePortNumber->setScrollbarsShown(true);
        receivePortNumber->setCaretVisible(true);
        receivePortNumber->setPopupMenuEnabled(true);
        receivePortNumber->setText(
            propertiesFile->getValue(OscRecivePortNumberIdentifier.toString(), ""));
        receivePortNumber->addListener(this);
        receivePortNumber->setColour(TextEditor::ColourIds::textColourId,
                                     Colours::black);
        receivePortNumber->setColour(TextEditor::ColourIds::backgroundColourId,
                                     Colours::grey.brighter());
        receivePortNumber->setColour(TextEditor::ColourIds::focusedOutlineColourId,
                                     Colours::grey.brighter().brighter());
        receivePortNumber->setColour(TextEditor::ColourIds::outlineColourId,
                                     Colours::grey);

        addAndMakeVisible(remotePortNumber = new TextEditor("sendPortNumber"));
        remotePortNumber->setMultiLine(false);
        remotePortNumber->setReturnKeyStartsNewLine(false);
        remotePortNumber->setReadOnly(sendEnabled->getToggleState());
        remotePortNumber->setScrollbarsShown(true);
        remotePortNumber->setCaretVisible(true);
        remotePortNumber->setPopupMenuEnabled(true);
        remotePortNumber->setText(
            propertiesFile->getValue(OscRemotePortNumberIdentifier.toString(), ""));
        remotePortNumber->addListener(this);
        remotePortNumber->setColour(TextEditor::ColourIds::textColourId,
                                    Colours::black);
        remotePortNumber->setColour(TextEditor::ColourIds::backgroundColourId,
                                    Colours::grey.brighter());
        remotePortNumber->setColour(TextEditor::ColourIds::focusedOutlineColourId,
                                    Colours::grey.brighter().brighter());
        remotePortNumber->setColour(TextEditor::ColourIds::outlineColourId,
                                    Colours::grey);

        addAndMakeVisible(receiveHostLabel = new Label("receiveHostLabel", TRANS("Host:\n")));
        receiveHostLabel->setFont(Font(15.00f, Font::plain));
        receiveHostLabel->setJustificationType(Justification::centredLeft);
        receiveHostLabel->setEditable(false, false, false);
        receiveHostLabel->setColour(Label::textColourId, Colours::grey);

        addAndMakeVisible(receiveHonstname = new TextEditor("receiveHonstname"));
        receiveHonstname->setMultiLine(false);
        receiveHonstname->setReturnKeyStartsNewLine(false);
        receiveHonstname->setReadOnly(true);
        receiveHonstname->setScrollbarsShown(true);
        receiveHonstname->setCaretVisible(true);
        receiveHonstname->setPopupMenuEnabled(true);
        receiveHonstname->setText(SystemStats::getComputerName());
        receiveHonstname->setColour(TextEditor::ColourIds::textColourId,
                                    Colours::black);
        receiveHonstname->setColour(TextEditor::ColourIds::backgroundColourId,
                                    Colours::grey.brighter());
        receiveHonstname->setColour(TextEditor::ColourIds::focusedOutlineColourId,
                                    Colours::grey.brighter().brighter());
        receiveHonstname->setColour(TextEditor::ColourIds::outlineColourId,
                                    Colours::grey);

        addAndMakeVisible(remoteHonstname = new TextEditor("sendHonstname"));
        remoteHonstname->setMultiLine(false);
        remoteHonstname->setReturnKeyStartsNewLine(false);
        remoteHonstname->setReadOnly(sendEnabled->getToggleState());
        remoteHonstname->setScrollbarsShown(true);
        remoteHonstname->setCaretVisible(true);
        remoteHonstname->setPopupMenuEnabled(true);
        remoteHonstname->setText(
            propertiesFile->getValue(OscRemoteHostnameIdentifier.toString(), ""));
        remoteHonstname->addListener(this);
        remoteHonstname->setColour(TextEditor::ColourIds::textColourId,
                                   Colours::black);
        remoteHonstname->setColour(TextEditor::ColourIds::backgroundColourId,
                                   Colours::grey.brighter());
        remoteHonstname->setColour(TextEditor::ColourIds::focusedOutlineColourId,
                                   Colours::grey.brighter().brighter());
        remoteHonstname->setColour(TextEditor::ColourIds::outlineColourId,
                                   Colours::grey);

        addAndMakeVisible(remoteHostLabel = new Label("sendHostLabel", TRANS("Device:\n")));
        remoteHostLabel->setFont(Font(15.00f, Font::plain));
        remoteHostLabel->setJustificationType(Justification::centredLeft);
        remoteHostLabel->setEditable(false, false, false);
        remoteHostLabel->setColour(Label::textColourId, Colours::grey);

        addAndMakeVisible(buttomBar = new Bar());
        addAndMakeVisible(closeButton = new AwesomeButton(FA_CHECK));

        closeButton->setButtonText(TRANS("Ok"));
        closeButton->addListener(this);

        setSize(600, 400);
    }

    ~OscSettings()
    {
        receiveEnabled = nullptr;
        sendEnabled = nullptr;
        oscLoggerEnabled = nullptr;
        oscLogger = nullptr;
        receivePortNumber = nullptr;
        remotePortNumber = nullptr;
        receiveHostLabel = nullptr;
        receiveHonstname = nullptr;
        remoteHonstname = nullptr;
        remoteHostLabel = nullptr;
        closeButton = nullptr;
    }

    void paint(Graphics& g)
    {
        g.fillAll(Colour::fromRGB(62, 62, 62)); // clear the background
    }

    void resized()
    {
        topBar->setBounds(0, 0, getWidth(), 32);
        titleLabel->setBounds(3, 5, 250, 24);

        receiveEnabled->setBounds(8, 38, 136, 24);
        sendEnabled->setBounds(8, 65, 136, 24);

        receivePortNumber->setBounds(152, 38, 48, 24);
        remotePortNumber->setBounds(152, 65, 48, 24);

        receiveHostLabel->setBounds(208, 38, 56, 24);
        receiveHonstname->setBounds(272, 38, 150, 24);

        remoteHonstname->setBounds(272, 65, 150, 24);
        remoteHostLabel->setBounds(208, 65, 56, 24);

        oscLoggerEnabled->setBounds(8, 96, getWidth() - 16, 24);
        seperator->setBounds(0, 94, getWidth(), 28);

        oscLogger->setBounds(0, 123, getWidth(), getHeight() - 123 - 32);

        closeButton->setBounds(getWidth() - 123, getHeight() - 27, 120, 24);
        buttomBar->setBounds(0, getHeight() - 32, getWidth(), 32);
    }

    void buttonClicked(Button* buttonThatWasClicked)
    {
        if (buttonThatWasClicked == receiveEnabled) {
            receivePortNumber->setReadOnly(receiveEnabled->getToggleState());
            propertiesFile->setValue(OscReciveEnabledIdentifier.toString(),
                                     receiveEnabled->getToggleState());
        }
        else if (buttonThatWasClicked == sendEnabled) {
            remoteHonstname->setReadOnly(sendEnabled->getToggleState());
            remotePortNumber->setReadOnly(sendEnabled->getToggleState());
            propertiesFile->setValue(OscRemoteEnabledIdentifier.toString(),
                                     sendEnabled->getToggleState());
        }
        else if (buttonThatWasClicked == closeButton) {
            oscServer->removeLogger();
            this->getParentComponent()->removeChildComponent(this);
        }
        else if (buttonThatWasClicked == oscLoggerEnabled) {
            if (oscLoggerEnabled->getToggleState()) {
                oscServer->setLogger(this);
            }
            else {
                oscServer->removeLogger();
            }
        }
    }

    void textEditorTextChanged(TextEditor& editor)
    {
        if (&editor == receivePortNumber) {
            propertiesFile->setValue(OscRecivePortNumberIdentifier.toString(),
                                     receivePortNumber->getText().getIntValue());
        }
        else if (&editor == remotePortNumber) {
            propertiesFile->setValue(OscRemotePortNumberIdentifier.toString(),
                                     remotePortNumber->getText().getIntValue());
        }
        else if (&editor == remoteHonstname) {
            propertiesFile->setValue(OscRemoteHostnameIdentifier.toString(),
                                     remoteHonstname->getText());
        }
    }

    void logOscMessage(juce::String message)
    {
        oscLoggerBuffer.add(message);
        if (oscLoggerBuffer.size() >= 50)
            oscLoggerBuffer.remove(0);
        oscLogger->updateContent();
        oscLogger->scrollToEnsureRowIsOnscreen(oscLoggerBuffer.size());
        oscLogger->repaint();
    }

    int getNumRows() { return oscLoggerBuffer.size(); }

    void paintListBoxItem(int rowNumber, Graphics& g, int width, int height,
                          bool rowIsSelected)
    {
        g.setColour(Colours::grey);
        g.drawText(oscLoggerBuffer[rowNumber], 0, 0, width, height,
                   Justification::centredLeft);
    }

private:
    ScopedPointer<Label> titleLabel;
    ScopedPointer<ToggleButton> receiveEnabled;
    ScopedPointer<ToggleButton> sendEnabled;
    ScopedPointer<ToggleButton> oscLoggerEnabled;
    ScopedPointer<ListBox> oscLogger;
    ScopedPointer<TextEditor> receivePortNumber;
    ScopedPointer<TextEditor> remotePortNumber;
    ScopedPointer<Label> receiveHostLabel;
    ScopedPointer<TextEditor> receiveHonstname;
    ScopedPointer<TextEditor> remoteHonstname;
    ScopedPointer<Label> remoteHostLabel;
    StringArray oscLoggerBuffer;

    ScopedPointer<AwesomeButton> closeButton;
    ScopedPointer<Bar> buttomBar;
    ScopedPointer<Bar> topBar;
    ScopedPointer<Bar> seperator;

    PropertiesFile* propertiesFile;
    OscServer* oscServer;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscSettings)
};

#endif // OSCSETTINGS_H_INCLUDED
