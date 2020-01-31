/*
  ==============================================================================

    FontAwesome.h
    Created: 13 Jul 2014 12:19:09pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef FONTAWESOME_H_INCLUDED
#define FONTAWESOME_H_INCLUDED

#include "JuceHeader.h"
#include "Icons.h"

typedef juce::Image RenderedIcon;

class FontAwesome {
public:
    FontAwesome() {}
    ~FontAwesome() {
        clearSingletonInstance();
    }
    juce_DeclareSingleton(FontAwesome, false)
    
    RenderedIcon getIcon(Icon icon, float size, juce::Colour colour, float scaleFactor = 1.0f);
    RenderedIcon getRotatedIcon(Icon icon, float size, juce::Colour colour, float iconRotation, float scaleFactor = 1.0f);

    void drawAt(juce::Graphics &g, RenderedIcon icon, int x, int y, float scaleFactor = 1.0f);
    void drawCenterdAt(juce::Graphics &g, RenderedIcon icon, juce::Rectangle<int> r, float scaleFactor = 1.0f);
    
    juce::Font getFont();
    juce::Font getFont(float size);
    
    static void drawAt(juce::Graphics &g, Icon icon, float size, juce::Colour colour, int x, int y, float scaleFactor);
    static void drawCenterd(juce::Graphics &g, Icon icon, float size, juce::Colour colour, juce::Rectangle<int> r, float scaleFactor);
    
    static void drawAt(juce::Graphics &g, Icon icon, float size, juce::Colour colour, int x, int y);
    static void drawCenterd(juce::Graphics &g, Icon icon, float size, juce::Colour colour, juce::Rectangle<int> r);
    
    static void drawAtRotated(juce::Graphics &g, Icon icon, float size, juce::Colour colour, int x, int y, float rotation, float scaleFactor);
    static void drawCenterdRotated(juce::Graphics &g, Icon icon, float size, juce::Colour colour, juce::Rectangle<int> r, float rotation, float scaleFactor);

    static void drawAtRotated(juce::Graphics &g, Icon icon, float size, juce::Colour colour, int x, int y, float rotation);
    static void drawCenterdRotated(juce::Graphics &g, Icon icon, float size, juce::Colour colour, juce::Rectangle<int> r, float rotation);

    
private:
    juce::Typeface::Ptr FontAwesome_ptr = juce::Typeface::createSystemTypefaceFor(FontAwesomeData::fontawesomewebfont_ttf, FontAwesomeData::fontawesomewebfont_ttfSize);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FontAwesome)
};

#endif // FONTAWESOME_H_INCLUDED
