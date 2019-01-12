/*
  ==============================================================================

    Common.h
    Created: 30 May 2018 1:20:22pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

template <typename T>
inline T px(T dp)
{
  return T(std::round(dp * 0.75));
}

//enum DensityQualifier {
//    ldpi = 120,
//    mdpi = 160,
//    hdpi = 240,
//    xhdpi = 320,
//    xxhdpi = 480,
//    xxxhdpi = 640,
//    nodpi = 0,
//    tvdpi = 213
//};
//
//template<typename T>
//static T convertDpToPixel(T dp) {
//    //const auto display = Desktop::getInstance().getDisplays().getDisplayContaining(TopLevelWindow::getTopLevelWindow(0)->getScreenBounds().getCentre());
//    //auto screenDensity = display.totalArea.getWidth() / display.totalArea.getHeight();
//    //const double px = (dp * (display.dpi / ldpi));
//    //return T(std::round(px));
//#if JUCE_LINUX || JUCE_WINDOWS || JUCE_MAC
//    //const auto display = Desktop::getInstance().getDisplays().getDisplayContaining(TopLevelWindow::getTopLevelWindow(0)->getScreenBounds().getCentre());
//    return T(std::round(dp) * 0.75);
//#else
//    return T(std::round(dp));
//#endif
//}
