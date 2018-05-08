/*
  ==============================================================================

    MaterialLookAndFeel.h
    Created: 6 May 2018 10:29:06am
    Author:  danlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

struct Material {
public:
	enum ColourIds
	{
		primaryColorId = 0x8000001,
		primaryLightColorId = 0x8000002,
		primaryDarkColorId = 0x8000003,

		primaryTextColorId = 0x8000004,
		primaryLightTextColorId = 0x8000005,
		primaryDarkTextColorId = 0x8000006,
		

		secondaryColorId = 0x8000007,
		secondaryLightColorId = 0x8000008,
		secondaryDarkColorId = 0x8000009,

		secondaryTextColorId = 0x80000010,
		secondaryLightTextColorId = 0x80000011,
		secondaryDarkTextColorId = 0x80000012,

		statusBarColorId = 0x80000013,
		appBarColorId = 0x80000014,
		backgroundColorId = 0x80000015,
		dialogColorId = 0x80000016,
		cardColorId = 0x80000017,

		textPrimaryColorId = 0x80000018,
		textSecondaryColorId = 0x80000019,
		textHintColorId = 0x80000020,
		textDisabledColorId = 0x80000021,
		dividerColorId = 0x80000022
	};

	class Icon
	{
	public:
		Icon(const char* data, const size_t size)
			: svg(XmlDocument::parse(String(data, size)))
		{
			drawable = std::unique_ptr<Drawable>(Drawable::createFromSVG(*svg.get()));
		}

		Drawable* getDrawable() {
			return drawable.get();
		}

		void setColour(Colour c) {
			if (c == colour) return;

			svg->setAttribute(fillAttribute, "#" + c.toDisplayString(false));
			svg->setAttribute(fillOpacityAttribute, c.getFloatAlpha());
			String myXmlDoc = svg->createDocument(String());
			drawable = std::unique_ptr<Drawable>(Drawable::createFromSVG(*svg.get()));

			colour = c;
		}
	private:
		Colour colour;
		Identifier fillAttribute{ "fill" };
		Identifier fillOpacityAttribute{ "fill-opacity" };
		std::unique_ptr<XmlElement> svg;
		std::unique_ptr<Drawable> drawable;
	};

private:
	class Shadow {
	public:
        virtual ~Shadow() {}
		virtual void setOwner(Component *c) = 0;
	};

public:
	class Shadow1dp : public Shadow {
	public:
		virtual void setOwner(Component * c) override {
			umbraShadower.setOwner(c);
			penumbraShadower.setOwner(c);
			ambientShadower.setOwner(c);
		}
	private:
		DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 2, Point<int>(0, 0)) };
		DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 2, Point<int>(0, 2)) };
		DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 3, Point<int>(0, 1)) };
	};

	class Shadow2dp : public Shadow {
	public:
		virtual void setOwner(Component * c) override {
			umbraShadower.setOwner(c);
			penumbraShadower.setOwner(c);
			ambientShadower.setOwner(c);
		}
	private:
		DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 4, Point<int>(0, 0)) };
		DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 4, Point<int>(0, 3)) };
		DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 5, Point<int>(0, 1)) };
	};

	class Shadow3dp : public Shadow {
	public:
		virtual void setOwner(Component * c) override {
			umbraShadower.setOwner(c);
			penumbraShadower.setOwner(c);
			ambientShadower.setOwner(c);
		}
	private:
		DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 3, Point<int>(0, 3)) };
		DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 4, Point<int>(0, 3)) };
		DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 8, Point<int>(0, 1)) };
	};

	class Shadow4dp : public Shadow {
	public:
		virtual void setOwner(Component * c) override {
			umbraShadower.setOwner(c);
			penumbraShadower.setOwner(c);
			ambientShadower.setOwner(c);
		}
	private:
		DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 4, Point<int>(0, 2)) };
		DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 5, Point<int>(0, 4)) };
		DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 10, Point<int>(0, 1)) };
	};

	class Shadow6dp : public Shadow {
	public:
		virtual void setOwner(Component * c) override {
			umbraShadower.setOwner(c);
			penumbraShadower.setOwner(c);
			ambientShadower.setOwner(c);
		}
	private:
		DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 10, Point<int>(0, 6)) };
		DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 18, Point<int>(0, 1)) };
		DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 5, Point<int>(0, 3)) };
	};

	class Shadow8dp : public Shadow {
	public:
		virtual void setOwner(Component * c) override {
			umbraShadower.setOwner(c);
			penumbraShadower.setOwner(c);
			ambientShadower.setOwner(c);
		}
	private:
		DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 10, Point<int>(0, 8)) };
		DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 14, Point<int>(0, 3)) };
		DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 15, Point<int>(0, 4)) };
	};

	class Shadow9dp : public Shadow {
	public:
		virtual void setOwner(Component * c) override {
			umbraShadower.setOwner(c);
			penumbraShadower.setOwner(c);
			ambientShadower.setOwner(c);
		}
	private:
		DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 12, Point<int>(0, 9)) };
		DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 16, Point<int>(0, 3)) };
		DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 6, Point<int>(0, 5)) };
	};

	class Shadow12dp : public Shadow {
	public:
		virtual void setOwner(Component * c) override {
			umbraShadower.setOwner(c);
			penumbraShadower.setOwner(c);
			ambientShadower.setOwner(c);
		}
	private:
		DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 17, Point<int>(0, 12)) };
		DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 22, Point<int>(0, 5)) };
		DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 8, Point<int>(0, 7)) };
	};

	class Shadow16dp : public Shadow {
	public:
		virtual void setOwner(Component * c) override {
			umbraShadower.setOwner(c);
			penumbraShadower.setOwner(c);
			ambientShadower.setOwner(c);
		}
	private:
		DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 24, Point<int>(0, 16)) };
		DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 30, Point<int>(0, 6)) };
		DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 10, Point<int>(0, 8)) };
	};

	class Shadow24dp : public Shadow {
	public:
		virtual void setOwner(Component * c) override {
			umbraShadower.setOwner(c);
			penumbraShadower.setOwner(c);
			ambientShadower.setOwner(c);
		}
	private:
		DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 38, Point<int>(0, 24)) };
		DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 46, Point<int>(0, 9)) };
		DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 15, Point<int>(0, 11)) };
	};

	struct Size {
		static const int Toolbar{ 56 };

		static const int FloatingActionButton{ 56 };

		static const int NavigationDrawer{ 320 };

		static const int ScreenEdge{ 16 };
		static const int ContentLeftMargin{ 72 };

		static const int SpaceBetweenContentAreas{ 8 };

		static const int MenuItem{ 48 };

		static const int IconTouch{ 48 };
		static const int Icon{ 40 };
		static const int IconSmall{ 18 };
	};
};

class MaterialLookAndFeel : public LookAndFeel_V4
{
public:
    MaterialLookAndFeel() {
        LookAndFeel::getDefaultLookAndFeel().setDefaultSansSerifTypeface(roboto_Regular);

		setColour(Material::primaryColorId, Colour::fromRGB(183, 28, 28));
		setColour(Material::primaryLightColorId, Colour::fromRGB(240, 85, 69));
		setColour(Material::primaryDarkColorId, Colour::fromRGB(127, 0, 0));
		setColour(Material::primaryTextColorId, Colours::white);
		setColour(Material::primaryLightTextColorId, Colours::black);
		setColour(Material::primaryDarkTextColorId, Colours::white);

		setColour(Material::secondaryColorId, Colour::fromRGB(183, 28, 28));
		setColour(Material::secondaryLightColorId, Colour::fromRGB(240, 85, 69));
		setColour(Material::secondaryDarkColorId, Colour::fromRGB(127, 0, 0));
		setColour(Material::secondaryTextColorId, Colours::white);
		setColour(Material::secondaryLightTextColorId, Colours::black);
		setColour(Material::secondaryDarkTextColorId, Colours::white);

        setColour(Material::statusBarColorId, Colour::fromRGB(224, 224, 224));
        setColour(Material::appBarColorId, Colour::fromRGB(245, 245, 245));
        setColour(Material::backgroundColorId, Colour::fromRGB(250, 250, 250));
        setColour(Material::cardColorId, Colour::fromRGB(255, 255, 255));
        setColour(Material::dialogColorId, Colour::fromRGB(255, 255, 255));

        setColour(Material::textPrimaryColorId, Colours::black.withAlpha(0.87f));
        setColour(Material::textSecondaryColorId, Colours::black.withAlpha(0.54f));
        setColour(Material::textDisabledColorId, Colours::black.withAlpha(0.54f));
        setColour(Material::textHintColorId, Colours::black.withAlpha(0.38f));
        setColour(Material::dividerColorId, Colours::black.withAlpha(0.12f));

//        setColour(Material::statusBarColorId, Colour::fromRGB(0, 0, 0));
//        setColour(Material::appBarColorId, Colour::fromRGB(33, 33, 33));
//        setColour(Material::backgroundColorId, Colour::fromRGB(48, 48, 48));
//        setColour(Material::cardColorId, Colour::fromRGB(66, 66, 66));
//        setColour(Material::dialogColorId, Colour::fromRGB(66, 66, 66));
//
//        setColour(Material::textPrimaryColorId, Colours::white);
//        setColour(Material::textSecondaryColorId, Colours::white.withAlpha(0.7f));
//        setColour(Material::textDisabledColorId, Colours::white.withAlpha(0.5f));
//        setColour(Material::textHintColorId, Colours::white.withAlpha(0.5f));
//        setColour(Material::dividerColorId, Colours::white.withAlpha(0.12f));
	}

	enum DensityQualifier {
		ldpi = 120,
		mdpi = 160,
		hdpi = 240,
		xhdpi = 320,
		xxhdpi = 480,
		xxxhdpi = 640,
		nodpi = 0,
		tvdpi = 213
	};

	template <typename T>
	static T convertDpToPixel(T dp) {
		auto display = Desktop::getInstance().getDisplays().getDisplayContaining(TopLevelWindow::getTopLevelWindow(0)->getScreenBounds().getCentre());
		double px = (dp * (display.dpi / 120)) * 0.4;
		return T(std::round(px));
	}
    
    void setFontRobotoMedium(Graphics &g) {
        g.setFont(Font(roboto_Medium));
    }

private:
	juce::Typeface::Ptr roboto_Black				= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoBlack_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr roboto_BlackItalic			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoBlackItalic_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr roboto_Bold					= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoBold_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr roboto_BoldItalic			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoBoldItalic_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr robotoCondensed_Bold			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedBold_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr robotoCondensed_BoldItalic	= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedBoldItalic_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr robotoCondensed_Italic		= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedItalic_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr robotoCondensed_Light		= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedLight_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr robotoCondensed_LightItalic  = juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedLightItalic_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr robotoCondensed_Regular		= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedRegular_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr roboto_Italic				= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoItalic_ttf, BinaryData::RobotoRegular_ttfSize);
	
	juce::Typeface::Ptr roboto_Light				= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoLight_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr roboto_LightItalic			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoLightItalic_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr roboto_Medium				= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoMedium_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr roboto_MediumItalic			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoMediumItalic_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr roboto_Regular				= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoRegular_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr roboto_Thin					= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoThin_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr roboto_ThinItalic			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoThinItalic_ttf, BinaryData::RobotoRegular_ttfSize);
};
