#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

#include "Colors.h"
#include "Fonts.h"

//namespace Material
//{
//    class IconButton : public DrawableButton
//    {
//    public:
//        IconButton(const String& buttonName, const char *data, const size_t size, const Colour &colour = Colours::black)
//            : DrawableButton(buttonName, DrawableButton::ButtonStyle::ImageFitted),
//            icon(data, size, colour)
//        {
//            setEdgeIndent(0);
//            setImages(icon.getDrawable());
//        }
//
//        void setColour(const Colour &colour)
//        {
//            icon.setColour(colour);
//        }
//    private:
//        Icon icon;
//    };
//
//    class IconToggleButton : public DrawableButton
//    {
//    public:
//        IconToggleButton(const String& buttonName, const char *onData, const size_t onSize, const char *offData, const size_t offSize, const Colour &onColour = Colours::black, const Colour &offColour = Colours::black)
//            : DrawableButton(buttonName, DrawableButton::ButtonStyle::ImageFitted),
//            on(onData, onSize, onColour), off(offData, offSize, offColour)
//        {
//            setEdgeIndent(0);
//            setImages(on.getDrawable(), nullptr, nullptr, nullptr, off.getDrawable());
//            setColour(DrawableButton::backgroundOnColourId, Colours::transparentWhite);
//        }
//
//        void setOnColour(const Colour &colour)
//        {
//            on.setColour(colour);
//        }
//
//        void setOffColour(const Colour &colour)
//        {
//            off.setColour(colour);
//        }
//    private:
//        Icon on;
//        Icon off;
//    };
//}

class MaterialLookAndFeel : public LookAndFeel_V4
{
  public:
    MaterialLookAndFeel()
    {
        getDefaultLookAndFeel().setDefaultSansSerifTypeface(Material::Typefaces::getInstance()->Body1);

        setColour(Slider::trackColourId, Material::Color::Secondary::Main);
        setColour(Slider::thumbColourId, Material::Color::Secondary::Main);
        setColour(Slider::backgroundColourId, Material::Color::Secondary::Main.withAlpha(0.38f));
    }

    void drawLinearSlider(Graphics &g, int x, int y, int width, int height,
                          float sliderPos,
                          float minSliderPos,
                          float maxSliderPos,
                          const Slider::SliderStyle style, Slider &slider)
    {
        if (slider.isBar())
        {
            g.setColour(slider.findColour(Slider::trackColourId));
            g.fillRect(slider.isHorizontal() ? Rectangle<float>(static_cast<float>(x), y + 0.5f, sliderPos - x, height - 1.0f)
                                             : Rectangle<float>(x + 0.5f, sliderPos, width - 1.0f, y + (height - sliderPos)));
        }
        else
        {
            auto isTwoVal = (style == Slider::SliderStyle::TwoValueVertical || style == Slider::SliderStyle::TwoValueHorizontal);
            auto isThreeVal = (style == Slider::SliderStyle::ThreeValueVertical || style == Slider::SliderStyle::ThreeValueHorizontal);

            auto trackWidth = jmin(2.0f, slider.isHorizontal() ? height * 0.25f : width * 0.25f);

            Point<float> startPoint(slider.isHorizontal() ? x : x + width * 0.5f,
                                    slider.isHorizontal() ? y + height * 0.5f : height + y);

            Point<float> endPoint(slider.isHorizontal() ? width + x : startPoint.x,
                                  slider.isHorizontal() ? startPoint.y : y);

            Path backgroundTrack;
            backgroundTrack.startNewSubPath(startPoint);
            backgroundTrack.lineTo(endPoint);
            g.setColour(slider.findColour(Slider::backgroundColourId));
            g.strokePath(backgroundTrack, {trackWidth, PathStrokeType::curved, PathStrokeType::rounded});

            Path valueTrack;
            Point<float> minPoint, maxPoint, thumbPoint;

            if (isTwoVal || isThreeVal)
            {
                minPoint = {slider.isHorizontal() ? minSliderPos : width * 0.5f,
                            slider.isHorizontal() ? height * 0.5f : minSliderPos};

                if (isThreeVal)
                    thumbPoint = {slider.isHorizontal() ? sliderPos : width * 0.5f,
                                  slider.isHorizontal() ? height * 0.5f : sliderPos};

                maxPoint = {slider.isHorizontal() ? maxSliderPos : width * 0.5f,
                            slider.isHorizontal() ? height * 0.5f : maxSliderPos};
            }
            else
            {
                auto kx = slider.isHorizontal() ? sliderPos : (x + width * 0.5f);
                auto ky = slider.isHorizontal() ? (y + height * 0.5f) : sliderPos;

                minPoint = startPoint;
                maxPoint = {kx, ky};
            }

            auto thumbWidth = getSliderThumbRadius(slider);

            valueTrack.startNewSubPath(minPoint);
            valueTrack.lineTo(isThreeVal ? thumbPoint : maxPoint);
            g.setColour(slider.findColour(Slider::trackColourId));
            g.strokePath(valueTrack, {trackWidth, PathStrokeType::curved, PathStrokeType::rounded});

            if (!isTwoVal)
            {
                g.setColour(slider.findColour(Slider::thumbColourId));
                g.fillEllipse(Rectangle<float>(static_cast<float>(thumbWidth), static_cast<float>(thumbWidth)).withCentre(isThreeVal ? thumbPoint : maxPoint));
            }

            if (isTwoVal || isThreeVal)
            {
                auto sr = jmin(trackWidth, (slider.isHorizontal() ? height : width) * 0.4f);
                auto pointerColour = slider.findColour(Slider::thumbColourId);

                if (slider.isHorizontal())
                {
                    drawPointer(g, minSliderPos - sr,
                                jmax(0.0f, y + height * 0.5f - trackWidth * 2.0f),
                                trackWidth * 2.0f, pointerColour, 2);

                    drawPointer(g, maxSliderPos - trackWidth,
                                jmin(y + height - trackWidth * 2.0f, y + height * 0.5f),
                                trackWidth * 2.0f, pointerColour, 4);
                }
                else
                {
                    drawPointer(g, jmax(0.0f, x + width * 0.5f - trackWidth * 2.0f),
                                minSliderPos - trackWidth,
                                trackWidth * 2.0f, pointerColour, 1);

                    drawPointer(g, jmin(x + width - trackWidth * 2.0f, x + width * 0.5f), maxSliderPos - sr,
                                trackWidth * 2.0f, pointerColour, 3);
                }
            }
        }
    }
};
