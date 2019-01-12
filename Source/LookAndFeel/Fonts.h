#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Common.h"

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

    const Font H1(){return Font(Typefaces::getInstance()->H1).withHeight(px(96.0f));}
    const Font H2(){return Font(Typefaces::getInstance()->H2).withHeight(px(60.0f));}
    const Font H3(){return Font(Typefaces::getInstance()->H3).withHeight(px(48.0f));}
    const Font H4(){return Font(Typefaces::getInstance()->H4).withHeight(px(34.0f));}
    const Font H5(){return Font(Typefaces::getInstance()->H5).withHeight(px(24.0f));}
    const Font H6(){return Font(Typefaces::getInstance()->H6).withHeight(px(20.0f)).withExtraKerningFactor(0.05f);}
    const Font Body1(){return Font(Typefaces::getInstance()->Body1).withHeight(px(16));}
    const Font Body2(){return Font(Typefaces::getInstance()->Body2).withHeight(px(14));}
    const Font Subtitle1(){return Font(Typefaces::getInstance()->Subtitle1).withHeight(px(16));}
    const Font Subtitle2(){return Font(Typefaces::getInstance()->Subtitle2).withHeight(px(14));}
    const Font Button(){return Font(Typefaces::getInstance()->Button).withHeight(px(14));}
    const Font Caption(){return Font(Typefaces::getInstance()->Caption).withHeight(px(12));}
    const Font Overline(){return Font(Typefaces::getInstance()->Overline).withHeight(px(12));}
};
} // namespace Material
