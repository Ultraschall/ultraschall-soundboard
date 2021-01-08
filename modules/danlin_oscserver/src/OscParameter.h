/*
  ==============================================================================

    OscParameter.h
    Created: 22 Jan 2015 11:11:46pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef OSCPARAMETER_H_INCLUDED
#define OSCPARAMETER_H_INCLUDED

#include <regex>

class OscParameter;

class OscParameterMessage : public Message {
public:
    OscParameterMessage(OscParameter* parameter)
        : parameter(parameter)
    {
    }
    ~OscParameterMessage() {}
    OscParameter* parameter;
};

class OscParameterListener : public MessageListener {
    virtual void handleOscParameterMessage(OscParameter* parameter) = 0;

    void handleMessage(const Message& message) override
    {
        const OscParameterMessage& receivedOscParameterMessage = dynamic_cast<const OscParameterMessage&>(message);
        handleOscParameterMessage(receivedOscParameterMessage.parameter);
    }
};

class OscParameter : public ChangeBroadcaster {
public:
    OscParameter(String address)
        : oscAddress(address)
    {
    }
    virtual ~OscParameter()
    {
        removeAllChangeListeners();
        listeners.clear();
    }

    bool addressMatch(String regex)
    {
	    try {
		    std::regex check(regex.toStdString());
		    return std::regex_match(oscAddress.toStdString(), check);
	    } catch (std::regex_error& e) {
		    std::cerr << regex << " ";
		    if (e.code() == std::regex_constants::error_collate)
       		    std::cerr << "The expression contained an invalid collating element name.\n";
		    else if (e.code() == std::regex_constants::error_ctype)
       		    std::cerr << "The expression contained an invalid character class name.\n";
		    else if (e.code() == std::regex_constants::error_escape)
       			std::cerr << "The expression contained an invalid escaped character, or a trailing escape.\n";
		    else if (e.code() == std::regex_constants::error_backref)
       			std::cerr << "he expression contained an invalid back reference.\n";
		    else if (e.code() == std::regex_constants::error_brack)
       			std::cerr << "The expression contained mismatched brackets ([ and ]).\n";
		    else if (e.code() == std::regex_constants::error_paren)
       			std::cerr << "The expression contained mismatched parentheses (( and )).\n";
		    else if (e.code() == std::regex_constants::error_brace)
       			std::cerr << "The expression contained mismatched braces ({ and }).\n";
		    else if (e.code() == std::regex_constants::error_badbrace)
       			std::cerr << "The expression contained an invalid range between braces ({ and }).\n";
		    else if (e.code() == std::regex_constants::error_range)
       			std::cerr << "The expression contained an invalid character range.\n";
		    else if (e.code() == std::regex_constants::error_space)
       			std::cerr << "There was insufficient memory to convert the expression into a finite state machine.\n";
		    else if (e.code() == std::regex_constants::error_badrepeat)
       			std::cerr << "The expression contained a repeat specifier (one of *?+{) that was not preceded by a valid regular expression.\n";
		    else if (e.code() == std::regex_constants::error_complexity)
       			std::cerr << "The complexity of an attempted match against a regular expression exceeded a pre-set level.\n";
		    else if (e.code() == std::regex_constants::error_stack)
       			std::cerr << "There was insufficient memory to determine whether the regular expression could match the specified character sequence.\n";
		    else std::cerr << "Some other regex exception happened. (" << e.code() << ")\n";

            return false;
	    }
    }
    String getAddress() const
    {
        return oscAddress;
    }

    virtual var getValue()
    {
        return oscValue;
    }
    enum OscParameterNotificationType
    {
        dontSendNotification = 0,
        sendNotification = 1,
        dontSendParameterNotification = 2,
        dontSendOscNotification = 3,
    };
    virtual void setValue(var value, OscParameterNotificationType notificationType = OscParameterNotificationType::sendNotification)
    {
        if (!oscValue.equals(value)) {
            oscValue = value;
            if (notificationType == OscParameterNotificationType::sendNotification
                    || notificationType != OscParameterNotificationType::dontSendOscNotification) {
                sendChangeMessage();
            }
            if (notificationType == OscParameterNotificationType::sendNotification
                    || notificationType != OscParameterNotificationType::dontSendParameterNotification) {
                sendParameterMessage();
            }
        }
    }

    void sendParameterMessage()
    {
        for (int index = 0; index <= listeners.size(); index++) {
            listeners[index]->postMessage(new OscParameterMessage(this));
        }
    }

    void addOscParameterListener(OscParameterListener* const listenerToAdd)
    {
        jassert(listenerToAdd != nullptr);

        if (listenerToAdd != nullptr)
            listeners.addIfNotAlreadyThere(listenerToAdd);
    }

    void removeOscParameterListener(OscParameterListener* const listenerToRemove)
    {
        jassert(listenerToRemove != nullptr);

        listeners.removeFirstMatchingValue(listenerToRemove);
    }
    virtual var getDefaultValue() = 0;
    virtual void appendOscMessageToStream(osc::OutboundPacketStream& stream) = 0;
private:
    Array<OscParameterListener*> listeners;
    var oscValue;
    String oscAddress;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscParameter)
};

#endif // OSCPARAMETER_H_INCLUDED
