/*
  ==============================================================================

    FontAwesome.cpp
    Created: 13 Jul 2014 12:45:27pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "FontAwesome.h"

juce_ImplementSingleton(FontAwesome)

RenderedIcon FontAwesome::getIcon(Icon icon, float size, juce::Colour colour, float scaleFactor) {
    int scaledSize = int(size * scaleFactor);
    
    String identifier = juce::String(icon + "@" + String(scaledSize) + "@" + colour.toString());
    int64 hash = identifier.hashCode64();
    Image canvas = juce::ImageCache::getFromHashCode(hash);
    if (canvas.isValid())
        return canvas;

    Font fontAwesome = getFont(scaledSize);
    scaledSize = max(fontAwesome.getStringWidth(icon), scaledSize);
    
    canvas = Image(Image::PixelFormat::ARGB, scaledSize, scaledSize, true);
    Graphics g(canvas);
    g.setColour(colour);
    g.setFont(fontAwesome);
    g.drawText(icon, 0, 0, scaledSize, scaledSize, Justification::centred, true);
    juce::ImageCache::addImageToCache(canvas, hash);
    return canvas;
}

RenderedIcon FontAwesome::getRotatedIcon(Icon icon, float size, juce::Colour colour, float iconRotation, float scaleFactor) {
    int scaledSize = int(size * scaleFactor);
    String identifier = String(icon + "@" + String(scaledSize) + "@" + colour.toString() + "@" + String(iconRotation) + "@");
    int64 hash = identifier.hashCode64();
    Image canvas = juce::ImageCache::getFromHashCode(hash);
    if (canvas.isValid())
        return canvas;

    RenderedIcon renderdIcon = getIcon(icon, size, colour, scaleFactor);
    canvas = Image(Image::PixelFormat::ARGB, renderdIcon.getWidth(), renderdIcon.getHeight(), true);
    Graphics g(canvas);
    g.drawImageTransformed(renderdIcon, AffineTransform::rotation(-(float_Pi * iconRotation), renderdIcon.getWidth() * 0.5f, renderdIcon.getHeight() * 0.5f));
    juce::ImageCache::addImageToCache(canvas, hash);
    return canvas;
}

void FontAwesome::drawAt(juce::Graphics &g, RenderedIcon icon, int x, int y, float scaleFactor) {
    auto w = icon.getWidth();
    auto h = icon.getHeight();
    g.drawImage(icon,
                x, y,
                int(w/scaleFactor), int(h/scaleFactor),
                0, 0,
                w, h,
                false);
}

void FontAwesome::drawCenterdAt(juce::Graphics &g, RenderedIcon icon, Rectangle<int> r, float scaleFactor) {
    auto iconWidth = icon.getWidth() / scaleFactor;
    auto iconHeight = icon.getHeight() / scaleFactor;
    
    auto x = r.getX() +  ((r.getWidth() * 0.5f) - (iconWidth * 0.5f));
    auto y = r.getY() +  ((r.getHeight() * 0.5f) - (iconHeight * 0.5f));
    g.drawImage(icon, int(x), int(y), int(iconWidth), int(iconHeight), 0, 0, icon.getWidth(), icon.getWidth());
}

juce::Font FontAwesome::getFont() {
    static Font fontAwesomeFont(FontAwesome_ptr);
    return fontAwesomeFont;
}

juce::Font FontAwesome::getFont(float size) {
    juce::Font font = getFont();
    font.setHeight(size);
    return font;
}

void FontAwesome::drawAt(juce::Graphics &g, Icon icon, float size, juce::Colour colour, int x, int y, float scaleFactor) {
    FontAwesome::getInstance()->drawAt(g, FontAwesome::getInstance()->getIcon(icon, size, colour, scaleFactor), x, y, scaleFactor);
}

void FontAwesome::drawAt(juce::Graphics &g, Icon icon, float size, juce::Colour colour, int x, int y) {
    FontAwesome::getInstance()->drawAt(g, FontAwesome::getInstance()->getIcon(icon, size, colour, g.getInternalContext().getPhysicalPixelScaleFactor()), x, y, g.getInternalContext().getPhysicalPixelScaleFactor());
}

void FontAwesome::drawCenterd(juce::Graphics &g, Icon icon, float size, juce::Colour colour, juce::Rectangle<int> r, float scaleFactor) {
    FontAwesome::getInstance()->drawCenterdAt(g, FontAwesome::getInstance()->getIcon(icon, size, colour, scaleFactor), r, scaleFactor);
}

void FontAwesome::drawCenterd(juce::Graphics &g, Icon icon, float size, juce::Colour colour, juce::Rectangle<int> r) {
    FontAwesome::getInstance()->drawCenterdAt(g, FontAwesome::getInstance()->getIcon(icon, size, colour, g.getInternalContext().getPhysicalPixelScaleFactor()), r,  g.getInternalContext().getPhysicalPixelScaleFactor());
}

void FontAwesome::drawAtRotated(juce::Graphics &g, Icon icon, float size, juce::Colour colour, int x, int y, float rotation, float scaleFactor) {
    FontAwesome::getInstance()->drawAt(g, FontAwesome::getInstance()->getRotatedIcon(icon, size, colour, rotation, scaleFactor), x, y, scaleFactor);
}

void FontAwesome::drawAtRotated(juce::Graphics &g, Icon icon, float size, juce::Colour colour, int x, int y, float rotation) {
    FontAwesome::getInstance()->drawAt(g, FontAwesome::getInstance()->getRotatedIcon(icon, size, colour, rotation, g.getInternalContext().getPhysicalPixelScaleFactor()), x, y, g.getInternalContext().getPhysicalPixelScaleFactor());
}

void FontAwesome::drawCenterdRotated(juce::Graphics &g, Icon icon, float size, juce::Colour colour, juce::Rectangle<int> r, float rotation, float scaleFactor) {
    FontAwesome::getInstance()->drawCenterdAt(g, FontAwesome::getInstance()->getRotatedIcon(icon, size, colour, rotation, scaleFactor), r, scaleFactor);
}

void FontAwesome::drawCenterdRotated(juce::Graphics &g, Icon icon, float size, juce::Colour colour, juce::Rectangle<int> r, float rotation) {
    FontAwesome::getInstance()->drawCenterdAt(g, FontAwesome::getInstance()->getRotatedIcon(icon, size, colour, rotation, g.getInternalContext().getPhysicalPixelScaleFactor()), r, g.getInternalContext().getPhysicalPixelScaleFactor());
}

