#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

namespace Material
{
class Typefaces
{
  public:
    Typefaces() = default;

    ~Typefaces()
    {
        // this ensures that no dangling pointers are left when the
        // singleton is deleted.
        clearSingletonInstance();
    }

    JUCE_DECLARE_SINGLETON(Typefaces, false)

    const Typeface::Ptr H1{Typeface::createSystemTypefaceFor(BinaryData::RobotoLight_ttf, BinaryData::RobotoLight_ttfSize)};
    const Typeface::Ptr H2{Typeface::createSystemTypefaceFor(BinaryData::RobotoLight_ttf, BinaryData::RobotoLight_ttfSize)};
    const Typeface::Ptr H3{Typeface::createSystemTypefaceFor(BinaryData::RobotoRegular_ttf, BinaryData::RobotoRegular_ttfSize)};
    const Typeface::Ptr H4{Typeface::createSystemTypefaceFor(BinaryData::RobotoRegular_ttf, BinaryData::RobotoRegular_ttfSize)};
    const Typeface::Ptr H5{Typeface::createSystemTypefaceFor(BinaryData::RobotoRegular_ttf, BinaryData::RobotoRegular_ttfSize)};
    const Typeface::Ptr H6{Typeface::createSystemTypefaceFor(BinaryData::RobotoMedium_ttf, BinaryData::RobotoMedium_ttfSize)};
    const Typeface::Ptr Body1{Typeface::createSystemTypefaceFor(BinaryData::RobotoRegular_ttf, BinaryData::RobotoRegular_ttfSize)};
    const Typeface::Ptr Body2{Typeface::createSystemTypefaceFor(BinaryData::RobotoRegular_ttf, BinaryData::RobotoRegular_ttfSize)};
    const Typeface::Ptr Subtitle1{Typeface::createSystemTypefaceFor(BinaryData::RobotoBlack_ttf, BinaryData::RobotoRegular_ttfSize)};
    const Typeface::Ptr Subtitle2{Typeface::createSystemTypefaceFor(BinaryData::RobotoMedium_ttf, BinaryData::RobotoMedium_ttfSize)};
    const Typeface::Ptr Button{Typeface::createSystemTypefaceFor(BinaryData::RobotoMedium_ttf, BinaryData::RobotoMedium_ttfSize)};
    const Typeface::Ptr Caption{Typeface::createSystemTypefaceFor(BinaryData::RobotoBlack_ttf, BinaryData::RobotoRegular_ttfSize)};
    const Typeface::Ptr Overline{Typeface::createSystemTypefaceFor(BinaryData::RobotoMedium_ttf, BinaryData::RobotoMedium_ttfSize)};
};

class Fonts
{
  public:
    Fonts() = default;

    ~Fonts()
    {
        // this ensures that no dangling pointers are left when the
        // singleton is deleted.
        clearSingletonInstance();
    }

    JUCE_DECLARE_SINGLETON(Fonts, false)

    const Font H1{Font(Typefaces::getInstance()->H1).withHeight(96)};
    const Font H2{Font(Typefaces::getInstance()->H2).withHeight(60)};
    const Font H3{Font(Typefaces::getInstance()->H3).withHeight(48)};
    const Font H4{Font(Typefaces::getInstance()->H4).withHeight(34)};
    const Font H5{Font(Typefaces::getInstance()->H5).withHeight(24)};
    const Font H6{Font(Typefaces::getInstance()->H6).withHeight(20).withExtraKerningFactor(0.05f)};
    const Font Body1{Font(Typefaces::getInstance()->Body1).withHeight(16)};
    const Font Body2{Font(Typefaces::getInstance()->Body2).withHeight(14)};
    const Font Subtitle1{Font(Typefaces::getInstance()->Subtitle1).withHeight(16)};
    const Font Subtitle2{Font(Typefaces::getInstance()->Subtitle2).withHeight(14)};
    const Font Button{Font(Typefaces::getInstance()->Button).withHeight(14)};
    const Font Caption{Font(Typefaces::getInstance()->Caption).withHeight(12)};
    const Font Overline{Font(Typefaces::getInstance()->Overline).withHeight(12)};
};
} // namespace Material
