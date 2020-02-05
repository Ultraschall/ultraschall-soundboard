/*
  ==============================================================================

    OscParameters.h
    Created: 22 Jan 2015 10:57:48pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef OSCPARAMETERS_H_INCLUDED
#define OSCPARAMETERS_H_INCLUDED

#include "OscParameter.h"

class OscFloatParameter : public OscParameter {
public:
    OscFloatParameter(String address)
        : OscParameter(address)
    {
        setValue(getDefaultValue());
    }

    ~OscFloatParameter()
    {
    }

    var getDefaultValue() override
    {
        return var(0.0f);
    }

    void appendOscMessageToStream(osc::OutboundPacketStream& stream) override
    {
        stream << osc::BeginMessage(getAddress().toRawUTF8()) << static_cast<float>(getValue()) << osc::EndMessage;
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscFloatParameter)
};

class OscBooleanParameter : public OscParameter {
public:
    OscBooleanParameter(String address)
        : OscParameter(address)
    {
        setValue(getDefaultValue());
    }
    ~OscBooleanParameter()
    {
    }

    var getDefaultValue() override
    {
        return var(false);
    }

    void appendOscMessageToStream(osc::OutboundPacketStream& stream) override
    {
        stream << osc::BeginMessage(getAddress().toRawUTF8()) << static_cast<bool>(getValue()) << osc::EndMessage;
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscBooleanParameter)
};

class OscIntegerParameter : public OscParameter {
public:
    OscIntegerParameter(String address)
        : OscParameter(address)
    {
        setValue(getDefaultValue());
    }
    ~OscIntegerParameter()
    {
    }

    var getDefaultValue() override
    {
        return var(0);
    }

    void appendOscMessageToStream(osc::OutboundPacketStream& stream) override
    {
        stream << osc::BeginMessage(getAddress().toRawUTF8()) << static_cast<int>(getValue()) << osc::EndMessage;
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscIntegerParameter)
};

class OscStringParameter : public OscParameter {
public:
    OscStringParameter(String address)
        : OscParameter(address)
    {
        setValue(getDefaultValue());
    }

    ~OscStringParameter()
    {
    }

    var getDefaultValue() override
    {
        return var("");
    }

    void appendOscMessageToStream(osc::OutboundPacketStream& stream) override
    {
        stream << osc::BeginMessage(getAddress().toRawUTF8()) << getValue().toString().toRawUTF8() << osc::EndMessage;
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscStringParameter)
};

#endif // OSCPARAMETERS_H_INCLUDED
