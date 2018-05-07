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

		secondaryColorId = 0x8000005,
		secondaryLightColorId = 0x8000006,
		secondaryDarkColorId = 0x8000007,
		secondaryTextColorId = 0x8000008
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

		void setColour(Colour colour) {
			svg->setAttribute(fillAttribute, "#" + colour.toDisplayString(false));
			drawable = std::unique_ptr<Drawable>(Drawable::createFromSVG(*svg.get()));
		}
	private:
		Identifier fillAttribute{ "fill" };
		std::unique_ptr<XmlElement> svg;
		std::unique_ptr<Drawable> drawable;
	};

private:
	class Shadow {
	public:
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
		static const int IconSmall{ 8 };
	};
};

class MaterialLookAndFeel : public LookAndFeel_V4
{
public:
    MaterialLookAndFeel() {
        LookAndFeel::getDefaultLookAndFeel().setDefaultSansSerifTypeface(roboto_Regular);

		setColour(Material::primaryColorId, Colour::fromFloatRGBA( 0.22f, 0.29f, 0.67f, 1.0f));
		setColour(Material::primaryLightColorId, Colour::fromFloatRGBA( 0.44f, 0.45f, 0.87f, 1.0f ));
		setColour(Material::primaryDarkColorId, Colour::fromFloatRGBA( 0.00f, 0.13f, 0.48f, 1.0f ));
		setColour(Material::primaryTextColorId, Colour::fromFloatRGBA( 1.0f, 1.0f, 1.0f, 1.0f ));

		setColour(Material::secondaryColorId, Colour::fromFloatRGBA( 0.22f, 0.29f, 0.67f, 1.0f ));
		setColour(Material::secondaryLightColorId, Colour::fromFloatRGBA( 0.44f, 0.45f, 0.87f, 1.0f ));
		setColour(Material::secondaryDarkColorId, Colour::fromFloatRGBA( 0.00f, 0.13f, 0.48f, 1.0f ));
		setColour(Material::secondaryTextColorId, Colour::fromFloatRGBA( 1.0f, 1.0f, 1.0f, 1.0f ));
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
		double px = (dp * (display.dpi / 120)) * 0.75;
		return std::round(T(px));
	}

	void setFontRobotoMedium(Graphics &g) {
		g.setFont(Font(roboto_Bold));
	}

private:
	juce::Typeface::Ptr roboto_Black				= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoBlack_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr roboto_BlackItalic			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoBlackItalic_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr roboto_Bold					= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoBold_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr roboto_BoldItalic			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoBoldItalic_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr robotoCondensedBold			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedBold_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr robotoCondensedBoldItalic	= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedBoldItalic_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr robotoCondensedItalic		= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedItalic_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr robotoCondensedLight		= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedLight_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr robotoCondensedLightItalic  = juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedLightItalic_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr robotoCondensed_Regular = juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedRegular_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr roboto_Italic				= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoItalic_ttf, BinaryData::RobotoRegular_ttfSize);
	
	juce::Typeface::Ptr roboto_Light				= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoLight_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr roboto_LightItalic			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoLightItalic_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr roboto_Medium				= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoMedium_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr roboto_MediumItalic			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoMediumItalic_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr roboto_Regular				= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoRegular_ttf, BinaryData::RobotoRegular_ttfSize);

	juce::Typeface::Ptr roboto_Thin					= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoThin_ttf, BinaryData::RobotoRegular_ttfSize);
	juce::Typeface::Ptr roboto_ThinItalic			= juce::Typeface::createSystemTypefaceFor(BinaryData::RobotoThinItalic_ttf, BinaryData::RobotoRegular_ttfSize);
};
