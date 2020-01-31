#if defined (__DANLIN_OSCPACK_HEADER__) && ! JUCE_AMALGAMATED_INCLUDE
 /* When you add this cpp file to your project, you mustn't include it in a file where you've
    already included any other headers - just put it inside a file on its own, possibly with your config
    flags preceding it, but don't include anything else. That also includes avoiding any automatic prefix
    header files that the compiler may be using.
 */
 #error "Incorrect use of JUCE cpp file"
#endif

// Your project must contain an AppConfig.h file with your project-specific settings in it,
// and your header search path must make it accessible to the module's files.
#include "AppConfig.h"

#include "danlin_oscpack.h"

#include "src/OscTypes.cpp"
#include "src/OscReceivedElements.cpp"
#include "src/OscPrintReceivedElements.cpp"    
#include "src/OscOutboundPacketStream.cpp"
