#ifndef __DANLIN_OSCPACK_HEADER__
#define __DANLIN_OSCPACK_HEADER__

/*******************************************************************************
 The block below describes the properties of this module, and is read by
 the Projucer to automatically generate project code that uses it.
 For details about the syntax and how to create or use a module, see the
 JUCE Module Format.txt file.


 BEGIN_JUCE_MODULE_DECLARATION

  ID:               danlin_oscpack
  vendor:           danlin
  version:          1.1.0
  name:             Oscpack
  description:      Open Sound Control (OSC) packet manipulation library.
  website:          https://github.com/danlin/danlin_modules
  license:          The MIT License (MIT)

  dependencies:     juce_core

 END_JUCE_MODULE_DECLARATION

*******************************************************************************/

#include "juce_core/juce_core.h"

#include "src/OscTypes.h"
#include "src/OscException.h"
#include "src/OscHostEndianness.h"
#include "src/OscReceivedElements.h"
#include "src/OscPrintReceivedElements.h"
#include "src/OscOutboundPacketStream.h"

#endif   // __DANLIN_OSCPACK_HEADER__
