#ifndef __DANLIN_OSCSERVER_HEADER__
#define __DANLIN_OSCSERVER_HEADER__

/*******************************************************************************
 The block below describes the properties of this module, and is read by
 the Projucer to automatically generate project code that uses it.
 For details about the syntax and how to create or use a module, see the
 JUCE Module Format.txt file.


 BEGIN_JUCE_MODULE_DECLARATION

  ID:               danlin_oscserver
  vendor:           danlin
  version:          0.8.0
  name:             Simple Osc Server
  description:      Simple Osc Server.
  website:          https://github.com/danlin/danlin_modules
  license:          The MIT License (MIT)

  dependencies:     juce_core juce_events danlin_oscpack

 END_JUCE_MODULE_DECLARATION

*******************************************************************************/

#include "juce_core/juce_core.h"
#include "juce_events/juce_events.h"

using namespace juce;

#include "danlin_oscpack/danlin_oscpack.h"

#include "src/OscServer.h"
#include "src/OscParameter.h"
#include "src/OscParameters.h"
#include "src/OscManager.h"

#endif // __DANLIN_OSCSERVER_HEADER__
