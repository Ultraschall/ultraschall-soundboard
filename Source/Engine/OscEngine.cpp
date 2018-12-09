#include "OscEngine.h"

OSCEngine::OSCEngine(Engine &engine) : engine(engine) {
    if (!connect(9001))
        showConnectionErrorMessage("Error: could not connect to UDP port 9001.");

    addListener(this, "/ultraschall/soundboard/gain");
}

void OSCEngine::oscMessageReceived(const OSCMessage &message) {

}

void OSCEngine::showConnectionErrorMessage(const String &messageText) {
    AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon,
        "Connection error",
        messageText,
        "OK");
}
