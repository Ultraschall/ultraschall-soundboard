/*
  ==============================================================================

    OscServer.cpp
    Created: 30 Nov 2014 10:28:31am
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "OscServer.h"

OscServer::OscServer(OscMessageListener* listener)
    : Thread("OscServer")
    , listener(listener)
{
    logger = nullptr;
    receivePortNumber = 8050;

    remoteEnabled = false;
    remoteHostname = "localhost";
    remotePortNumber = 9050;
    remoteChanged = true;

    bridgeEnabled = false;
    bridgeHostname = "localhost";
    bridgePortNumber = 8000;
    bridgeChanged = true;
}

OscServer::~OscServer()
{
    signalThreadShouldExit();
    stopThread(500);
    receiveDatagramSocket = nullptr;
    remoteDatagramSocket = nullptr;
}

void OscServer::setLocalPortNumber(int portNumber)
{
    receivePortNumber = portNumber;
}

int OscServer::getLocalPortNumber()
{
    return receivePortNumber;
}

const String& OscServer::getLocalHostname()
{
    
    return String::empty;
}

void OscServer::setRemoteHostname(String hostname)
{
    remoteHostname = hostname;
    remoteChanged = true;
}

String OscServer::getRemoteHostname()
{
    return remoteHostname;
}

void OscServer::setRemotePortNumber(int portNumber)
{
    remotePortNumber = portNumber;
    remoteChanged = true;
}

int OscServer::getRemotePortNumber()
{
    return remotePortNumber;
}

bool OscServer::isRemoteEnabled()
{
    return remoteEnabled;
}

void OscServer::setRemoteEnabled(bool enable)
{
    remoteEnabled = enable;
}

void OscServer::setBridgeHostname(String hostname)
{
    bridgeHostname = hostname;
    bridgeChanged = true;
}

String OscServer::getBridgeHostname()
{
    return bridgeHostname;
}

void OscServer::setBridgePortNumber(int portNumber)
{
    bridgePortNumber = portNumber;
    bridgeChanged = true;
}

int OscServer::getBridgePortNumber()
{
    return bridgePortNumber;
}

bool OscServer::isBridgeEnabled()
{
    return bridgeEnabled;
}

void OscServer::setBridgeEnabled(bool enable)
{
    bridgeEnabled = enable;
}

void OscServer::listen()
{
    if (isThreadRunning()) {
        signalThreadShouldExit();
        stopThread(500);
        receiveDatagramSocket = nullptr;
    }
    startThread(3);
}

void OscServer::stopListening()
{
    if (isThreadRunning()) {
        signalThreadShouldExit();
        stopThread(500);
        receiveDatagramSocket = nullptr;
    }
}

void OscServer::run()
{
    receiveDatagramSocket = new DatagramSocket();
    if (!receiveDatagramSocket->bindToPort(receivePortNumber)) {
        Logger::outputDebugString("error port " + String(receivePortNumber) + "already is bound");
        Logger::writeToLog("error port " + String(receivePortNumber) + "already is bound");
        return;
    }
    
    MemoryBlock buffer(bufferSize, true);
    while (!threadShouldExit()) {
        if (receiveDatagramSocket->getBoundPort() == -1) {
            if (!receiveDatagramSocket->bindToPort(receivePortNumber)) {
                Logger::outputDebugString("error port " + String(receivePortNumber) + "already is bound");
                Logger::writeToLog("error port " + String(receivePortNumber) + "already is bound");
                return;
            }
        }
        switch (receiveDatagramSocket->waitUntilReady(true, 100)) {
            case 1:
            {
                int size = receiveDatagramSocket->read(buffer.getData(), buffer.getSize(), false);
                if (threadShouldExit()) {
                    return;
                }
                try {
                    osc::ReceivedPacket packet((const char*)buffer.getData(), size);
                    if (listener != nullptr) {
                        MessageManagerLock mml(Thread::getCurrentThread());
                        if (!mml.lockWasGained()) {
                            return;
                        }
                        if (logger != nullptr) {
                            logger->postMessage(new OscMessage(packet));
                        }
                        listener->postMessage(new OscMessage(packet));
                        routePackage(buffer, size);
                    }
                } catch (osc::Exception& e) {
                    Logger::outputDebugString("error while parsing packet");
                    Logger::writeToLog("error while parsing packet");
                }
                break;
            }
            case -1:
            {
                Logger::outputDebugString("socket error");
                Logger::writeToLog("socket error");
                break;
            }
        }
    }
}

bool OscServer::routePackage(MemoryBlock packet, int size)
{
    if (bridgeEnabled) {
        if (!bridgeDatagramSocket || bridgeChanged) {
            bridgeChanged = false;
            bridgeDatagramSocket = new DatagramSocket(0);
        }

        if (bridgeDatagramSocket->waitUntilReady(false, 100)) {
            if (bridgeDatagramSocket->write(bridgeHostname, bridgePortNumber, packet.getData(), size) > 0) {
                return true;
            }
        }
    }
    return false;
}

bool OscServer::sendMessage(osc::OutboundPacketStream stream)
{
    if (!remoteEnabled)
        return false;

    if (!stream.IsReady()) {
        return false;
    }

    if (!remoteDatagramSocket || remoteChanged) {
        remoteChanged = false;
        remoteDatagramSocket = new DatagramSocket(0);
    }

    if (remoteDatagramSocket->waitUntilReady(false, 100)) {
        if (remoteDatagramSocket->write(remoteHostname, remotePortNumber, stream.Data(), stream.Size()) > 0) {
            return true;
        }
    }

    return false;
}