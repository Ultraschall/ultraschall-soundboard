/*
  ==============================================================================

    OscProcessor.h
    Created: 22 Jan 2015 10:56:59pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef OSCPROCESSOR_H_INCLUDED
#define OSCPROCESSOR_H_INCLUDED

#include "OscParameter.h"
#include "OscServer.h"

class OscManager
    : private OscMessageListener,
      private ChangeListener {
public:
    OscManager();
    ~OscManager();

    // OscMessageListener
    void handleOscMessage(osc::ReceivedPacket packet) override;

    // ChangeListener
    void changeListenerCallback(ChangeBroadcaster* source) override;

    // Osc Parameter
    void addOscParameter(OscParameter* parameter, bool internal = false);
    void removeOscParameter(OscParameter* p);
    void removeOscParameter(String regex);
    OscParameter* getOscParameter(String address);
    Array<OscParameter*> getAllOscParameter(String regex);
    Array<OscParameter*> getAllOscParameter();
    void dumpOscParameters();

    // Osc Parameter Values
    var getOscParameterValue(String address);
    void setOscParameterValue(String address, var value, OscParameter::OscParameterNotificationType notificationType = OscParameter::sendNotification);

    // Osc Parameter Listener
    void addOscParameterListener(OscParameterListener* listener, OscParameter* parameter);
    void addOscParameterListener(OscParameterListener* listener, String regex);
    void removeOscParameterListener(OscParameterListener* listener);

    // Osc Parser
    void parseOscPacket(osc::ReceivedPacket packet);
    void parseOscMessage(osc::ReceivedMessage message);
    void parseOscBundle(osc::ReceivedBundle bundle);

    OscServer* getOscServer();

private:
    OscServer oscServer;
    int oscReceived;
    int oscSent;

    OwnedArray<OscParameter> managedOscParameters;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscManager)
};

#endif // OSCPROCESSOR_H_INCLUDED
