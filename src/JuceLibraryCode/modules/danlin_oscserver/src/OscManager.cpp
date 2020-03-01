/*
  ==============================================================================

    OscProcessor.cpp
    Created: 22 Jan 2015 10:56:59pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "OscManager.h"

OscManager::OscManager()
    : oscServer(this)
{
}

OscManager::~OscManager()
{
    managedOscParameters.clear();
}

void OscManager::handleOscMessage(osc::ReceivedPacket packet)
{
    parseOscPacket(packet);
}

void OscManager::changeListenerCallback(ChangeBroadcaster* source)
{
    OscParameter* parameter = static_cast<OscParameter*>(source);
    if (parameter) {
        char buffer[1024];
        osc::OutboundPacketStream packet(buffer, 1024);
        parameter->appendOscMessageToStream(packet);
        oscServer.sendMessage(packet);
    }
}

void OscManager::addOscParameter(OscParameter* parameter, bool internal)
{
    if (parameter) {
        managedOscParameters.add(parameter);
        if (!internal) {
            parameter->addChangeListener(this);
        }
    }
}

void OscManager::removeOscParameter(OscParameter* p)
{
    managedOscParameters.removeObject(p);
}

void OscManager::removeOscParameter(String regex)
{
    Array<OscParameter*> toRemove;
    for (int index = 0; index < managedOscParameters.size(); index++) {
        if (managedOscParameters[index]->addressMatch(regex)) {
            toRemove.add(managedOscParameters[index]);
        }
    }
    for (int index = 0; index < toRemove.size(); index++) {
        managedOscParameters.removeObject(toRemove[index]);
    }
}

Array<OscParameter*> OscManager::getAllOscParameter(String regex)
{
    Array<OscParameter*> parameters;
    for (int index = 0; index < managedOscParameters.size(); index++) {
        if (managedOscParameters[index]->addressMatch(regex)) {
            parameters.add(managedOscParameters[index]);
        }
    }
    return parameters;
}

OscParameter* OscManager::getOscParameter(String address)
{
    for (int index = 0; index < managedOscParameters.size(); index++) {
        if (managedOscParameters[index]->getAddress() == address) {
            return managedOscParameters[index];
        }
    }
    return nullptr;
}

Array<OscParameter*> OscManager::getAllOscParameter()
{
    Array<OscParameter*> parameters;
    for (int index = 0; index < managedOscParameters.size(); index++) {
        parameters.add(managedOscParameters[index]);
    }
    return parameters;
}

void OscManager::dumpOscParameters()
{
    for (int index = 0; index < managedOscParameters.size(); index++) {
        char buffer[1024];
        osc::OutboundPacketStream packet(buffer, 1024);
        managedOscParameters[index]->appendOscMessageToStream(packet);
        oscServer.sendMessage(packet);
    }
}

var OscManager::getOscParameterValue(String address)
{
    for (int index = 0; index < managedOscParameters.size(); index++) {
        if (managedOscParameters[index]->getAddress() == address) {
            return var(managedOscParameters[index]->getValue());
        }
    }
    return var();
}

void OscManager::setOscParameterValue(String address, var value, OscParameter::OscParameterNotificationType notificationType)
{
    for (int index = 0; index < managedOscParameters.size(); index++) {
        if (managedOscParameters[index]->getAddress() == address) {
            managedOscParameters[index]->setValue(value, notificationType);
            return;
        }
    }
    Logger::outputDebugString("setOscParameterValue: address " + address + " not found!");
}

void OscManager::addOscParameterListener(OscParameterListener* listener, OscParameter* parameter)
{
    parameter->addOscParameterListener(listener);
}

void OscManager::addOscParameterListener(OscParameterListener* listener, String regex)
{
    auto parameters = getAllOscParameter(regex);
    for (int index = 0; index < parameters.size(); index++) {
        parameters[index]->addOscParameterListener(listener);
    }
}

void OscManager::removeOscParameterListener(OscParameterListener* listener)
{
    auto parameters = getAllOscParameter();
    for (int index = 0; index < parameters.size(); index++) {
        parameters[index]->removeOscParameterListener(listener);
    }
}

void OscManager::parseOscPacket(osc::ReceivedPacket packet)
{
    if (packet.Size()) {
        if (packet.IsBundle()) {
            osc::ReceivedBundle bundle(packet);
            parseOscBundle(bundle);
        }
        else {
            osc::ReceivedMessage message(packet);
            parseOscMessage(message);
        }
    }
}

void OscManager::parseOscMessage(osc::ReceivedMessage message)
{
    String address(message.AddressPattern());
    OscParameter* parameter = getOscParameter(address);
    if (parameter) {
        osc::ReceivedMessage::const_iterator arg = message.ArgumentsBegin();
        while (arg != message.ArgumentsEnd()) {
            if (arg->IsFloat()) {
                parameter->setValue(var(arg->AsFloat()));
            }
            else if (arg->IsBool()) {
                parameter->setValue(var(arg->IsBool()));
            }
            else if (arg->IsInt32()) {
                parameter->setValue(var(arg->AsInt32()));
            }
            else if (arg->IsChar()) {
                parameter->setValue(var(String(arg->AsChar())));
            }
            else if (arg->IsDouble()) {
                parameter->setValue(var(arg->AsDouble()));
            }
            else if (arg->IsString()) {
                parameter->setValue(var(String(arg->AsString())));
            }
            else if (arg->IsSymbol()) {
                parameter->setValue(var(String(arg->AsSymbol())));
            }
            arg++;
        }
    }
}

void OscManager::parseOscBundle(osc::ReceivedBundle bundle)
{
    osc::ReceivedBundleElementIterator initiator = bundle.ElementsBegin();
    for (int i = 0; i < bundle.ElementCount(); i++) {
        initiator++;
        if (initiator->IsBundle()) {
            osc::ReceivedBundle bundle(*initiator);
            parseOscBundle(bundle);
        }
        else {
            osc::ReceivedMessage message(*initiator);
            parseOscMessage(message);
        }
    }
}

OscServer* OscManager::getOscServer()
{
    return &oscServer;
}
