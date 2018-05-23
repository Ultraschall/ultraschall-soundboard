#pragma once

#include "JuceHeader.h"

namespace Material
{
    namespace Theme::Colour {
        namespace Pallete {
            juce::Colour const Primary{0xFF6200EE};
            juce::Colour const PrimaryVariant{0xFF3700B3};
            juce::Colour const PrimaryVariant2{0xFFBB86FC};
            juce::Colour const Secondary{0xFF03DAC6};
            juce::Colour const SecondaryVariant{0xFF018786};

            juce::Colour const Background{0xFFFFFFFF};
            juce::Colour const Surface{0xFFFFFFFF};
            juce::Colour const Error{0xFFB00020};
            
            juce::Colour const OnPrimary{0xFFFFFFFF};
            juce::Colour const OnSecondary{0xFF000000};
            juce::Colour const OnBackground{0xFF000000};
            juce::Colour const OnSurface{0xFF000000};
            juce::Colour const OnError{0xFFFFFFFF};
        }
    }
	
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
		Icon(const char *data, const size_t size, const Colour &c = Colours::black)
			: svg(XmlDocument::parse(String(data, size)))
		{
			if (c == Colours::black)
			{
				drawable = std::unique_ptr<Drawable>(Drawable::createFromSVG(*svg));
				return;
			}

			setColour(c);
		}

		Drawable *getDrawable() const
		{
			return drawable.get();
		}

		void setColour(Colour c)
		{
			if (c == colour) return;

			svg->setAttribute(fillAttribute, "#" + c.toDisplayString(false));
			svg->setAttribute(fillOpacityAttribute, c.getFloatAlpha());
			String myXmlDoc = svg->createDocument(String());
			drawable = std::unique_ptr<Drawable>(Drawable::createFromSVG(*svg));

			colour = c;
		}

	private:
		Colour colour{ Colours::black };
		Identifier fillAttribute{ "fill" };
		Identifier fillOpacityAttribute{ "fill-opacity" };
		std::unique_ptr<XmlElement> svg;
		std::unique_ptr<Drawable> drawable;
	};

	namespace Shadows {
		class ShadowBase
		{
		public:
			virtual ~ShadowBase()
			{
			}

			virtual void setOwner(Component *c) = 0;
		};

		class _1dp : public ShadowBase
		{
		public:
			virtual void setOwner(Component *c) override
			{
				umbraShadower.setOwner(c);
				penumbraShadower.setOwner(c);
				ambientShadower.setOwner(c);
			}

		private:
			DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 2, Point<int>(0, 0)) };
			DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 2, Point<int>(0, 2)) };
			DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 3, Point<int>(0, 1)) };
		};

		class _2dp : public ShadowBase
		{
		public:
			virtual void setOwner(Component *c) override
			{
				umbraShadower.setOwner(c);
				penumbraShadower.setOwner(c);
				ambientShadower.setOwner(c);
			}

		private:
			DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 4, Point<int>(0, 0)) };
			DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 4, Point<int>(0, 3)) };
			DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 5, Point<int>(0, 1)) };
		};

		class _3dp : public ShadowBase
		{
		public:
			virtual void setOwner(Component *c) override
			{
				umbraShadower.setOwner(c);
				penumbraShadower.setOwner(c);
				ambientShadower.setOwner(c);
			}

		private:
			DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 3, Point<int>(0, 3)) };
			DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 4, Point<int>(0, 3)) };
			DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 8, Point<int>(0, 1)) };
		};

		class _4dp : public ShadowBase
		{
		public:
			virtual void setOwner(Component *c) override
			{
				umbraShadower.setOwner(c);
				penumbraShadower.setOwner(c);
				ambientShadower.setOwner(c);
			}

		private:
			DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 4, Point<int>(0, 2)) };
			DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 5, Point<int>(0, 4)) };
			DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 10, Point<int>(0, 1)) };
		};

		class _6dp : public ShadowBase
		{
		public:
			virtual void setOwner(Component *c) override
			{
				umbraShadower.setOwner(c);
				penumbraShadower.setOwner(c);
				ambientShadower.setOwner(c);
			}

		private:
			DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 10, Point<int>(0, 6)) };
			DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 18, Point<int>(0, 1)) };
			DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 5, Point<int>(0, 3)) };
		};

		class _8dp : public ShadowBase
		{
		public:
			virtual void setOwner(Component *c) override
			{
				umbraShadower.setOwner(c);
				penumbraShadower.setOwner(c);
				ambientShadower.setOwner(c);
			}

		private:
			DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 10, Point<int>(0, 8)) };
			DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 14, Point<int>(0, 3)) };
			DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 15, Point<int>(0, 4)) };
		};

		class _9dp : public ShadowBase
		{
		public:
			virtual void setOwner(Component *c) override
			{
				umbraShadower.setOwner(c);
				penumbraShadower.setOwner(c);
				ambientShadower.setOwner(c);
			}

		private:
			DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 12, Point<int>(0, 9)) };
			DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 16, Point<int>(0, 3)) };
			DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 6, Point<int>(0, 5)) };
		};

		class _12dp : public ShadowBase
		{
		public:
			virtual void setOwner(Component *c) override
			{
				umbraShadower.setOwner(c);
				penumbraShadower.setOwner(c);
				ambientShadower.setOwner(c);
			}

		private:
			DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 17, Point<int>(0, 12)) };
			DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 22, Point<int>(0, 5)) };
			DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 8, Point<int>(0, 7)) };
		};

		class _16dp : public ShadowBase
		{
		public:
			virtual void setOwner(Component *c) override
			{
				umbraShadower.setOwner(c);
				penumbraShadower.setOwner(c);
				ambientShadower.setOwner(c);
			}

		private:
			DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 24, Point<int>(0, 16)) };
			DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 30, Point<int>(0, 6)) };
			DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 10, Point<int>(0, 8)) };
		};

		class _24dp : public ShadowBase
		{
		public:
			virtual void setOwner(Component *c) override
			{
				umbraShadower.setOwner(c);
				penumbraShadower.setOwner(c);
				ambientShadower.setOwner(c);
			}

		private:
			DropShadower umbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), 38, Point<int>(0, 24)) };
			DropShadower penumbraShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), 46, Point<int>(0, 9)) };
			DropShadower ambientShadower{ DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), 15, Point<int>(0, 11)) };
		};
	}

	namespace Specs {
		namespace Global 
		{
			namespace Dimensions
			{
				static const int IconSizeSmall = 24;
				static const int TouchArea = 40;
			}

			namespace Padding
			{
				static const int Base = 16;
				static const int Left = 16;
				static const int Right = 16;
				static const int Top = 16;
				static const int Bottom = 16;
			}
		}

		namespace FloatingActionButton {
			namespace Regular {
				namespace Dimensions
				{
					static const int Size = 56;
					static const int IconSize = 24;
				}
				namespace Padding
				{
					static const int Left = 16;
					static const int Right = 16;
				}
				namespace Placement
				{
					static const int Right = 16;
					static const int Bottom = 16;
				}
			}
			namespace Mini 
			{
				namespace Dimensions
				{
					static const int Size = 40;
					static const int IconSize = 24;
				}
				namespace Padding
				{
					static const int Left = 8;
					static const int Right = 8;
				}
			}
			namespace Extended {
				namespace Dimensions
				{
					static const int Size = 48;
					static const int IconSize = 24;
				}
				namespace Padding
				{
					static const int Left = 16;
					static const int IconToTitle = 8;
					static const int Right = 20;
				}
				namespace Placement
				{
					static const int Right = 8;
				}
			}
		}
		namespace NavigationDrawer
		{
			namespace Standard
			{
				namespace Dimensions
				{
					static const int Width = 256;
					static const int TitleHeight = 64;
				}

				namespace Padding
				{
					static const int Left = 16;
					static const int TextLeft = 72;
				}

				namespace TextBaseline
				{
					static const int Left = 42;
				}
			}
			namespace Modal
			{
				namespace Dimensions
				{
					static const int ItemHeight = 48;
					static const int ContentRight = 58;
					static const int Icon = 24;
				}

				namespace Padding
				{
					static const int Left = 16;
				}

				namespace TextBaseline
				{
					static const int Title = 32;
					static const int Subtext = 32;
					static const int Labels = 29;
				}
			}
		}
		namespace TopAppBar
		{
			namespace Regular
			{
				namespace Dimensions
				{
					static const int Height = 56;
					static const int IconSize = 24;
				}

				namespace Padding
				{
					static const int Left = 16;
					static const int Right = 16;
					static const int Top = 16;
					static const int Bottom = 16;
					static const int Icons = 16;
					static const int IconToTitle = 32;
				}

				namespace TextBaseline
				{
					static const int TitleFromBottom = 20;
				}
			}
		}
	}

	class IconButton : public DrawableButton
	{
	public:
		IconButton(const String& buttonName, const char *data, const size_t size, const Colour &colour = Colours::black)
			: DrawableButton(buttonName, DrawableButton::ButtonStyle::ImageFitted),
			icon(data, size, colour)
		{
			setEdgeIndent(0);
			setImages(icon.getDrawable());
		}

		void setColour(const Colour &colour)
        {
		    icon.setColour(colour);
        }
	private:
		Icon icon;
	};

	class IconToggleButton : public DrawableButton
	{
	public:
		IconToggleButton(const String& buttonName, const char *onData, const size_t onSize, const char *offData, const size_t offSize, const Colour &onColour = Colours::black, const Colour &offColour = Colours::black)
			: DrawableButton(buttonName, DrawableButton::ButtonStyle::ImageFitted),
			on(onData, onSize, onColour), off(offData, offSize, offColour)
		{
			setEdgeIndent(0);
			setImages(on.getDrawable(), nullptr, nullptr, nullptr, off.getDrawable());
			setColour(DrawableButton::backgroundOnColourId, Colours::transparentWhite);
		}

        void setOnColour(const Colour &colour)
        {
            on.setColour(colour);
        }

        void setOffColour(const Colour &colour)
        {
            off.setColour(colour);
        }
	private:
		Icon on;
		Icon off;
	};
}

class MaterialLookAndFeel : public LookAndFeel_V4
{
public:
	MaterialLookAndFeel()
	{
		getDefaultLookAndFeel().setDefaultSansSerifTypeface(roboto_Regular);

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

		//setColour(Material::statusBarColorId, Colour::fromRGB(0, 0, 0));
		//setColour(Material::appBarColorId, Colour::fromRGB(33, 33, 33));
		//setColour(Material::backgroundColorId, Colour::fromRGB(48, 48, 48));
		//setColour(Material::cardColorId, Colour::fromRGB(66, 66, 66));
		//setColour(Material::dialogColorId, Colour::fromRGB(66, 66, 66));

		//setColour(Material::textPrimaryColorId, Colours::white);
		//setColour(Material::textSecondaryColorId, Colours::white.withAlpha(0.7f));
		//setColour(Material::textDisabledColorId, Colours::white.withAlpha(0.5f));
		//setColour(Material::textHintColorId, Colours::white.withAlpha(0.5f));
		//setColour(Material::dividerColorId, Colours::white.withAlpha(0.12f));


		setColour(DrawableButton::ColourIds::backgroundOnColourId, Colours::transparentWhite);

		setColour(Slider::trackColourId, findColour(Material::ColourIds::primaryColorId));
		setColour(Slider::thumbColourId, findColour(Material::ColourIds::primaryColorId));
		setColour(Slider::backgroundColourId, findColour(Material::ColourIds::dividerColorId));
	}

	enum DensityQualifier
	{
		ldpi = 120,
		mdpi = 160,
		hdpi = 240,
		xhdpi = 320,
		xxhdpi = 480,
		xxxhdpi = 640,
		nodpi = 0,
		tvdpi = 213
	};

	template<typename T>
	static T convertDpToPixel(T dp)
	{
		//const auto display = Desktop::getInstance().getDisplays().getDisplayContaining(TopLevelWindow::getTopLevelWindow(0)->getScreenBounds().getCentre());
		//auto screenDensity = display.totalArea.getWidth() / display.totalArea.getHeight();
		//const double px = (dp * (display.dpi / ldpi));
		//return T(std::round(px));
#if JUCE_LINUX || JUCE_WINDOWS || JUCE_MAC
		//const auto display = Desktop::getInstance().getDisplays().getDisplayContaining(TopLevelWindow::getTopLevelWindow(0)->getScreenBounds().getCentre());
 		return T(std::round(dp) * 0.75);
#else
		return T(std::round(dp));
#endif
	}

	void setFontRoboto(Graphics &g) const
	{
		g.setFont(Font(roboto_Regular));
	}

	void setFontRobotoBlack(Graphics &g) const
	{
		g.setFont(Font(roboto_Black));
	}

	void setFontRobotoBlackItalic(Graphics &g) const
	{
		g.setFont(Font(roboto_BlackItalic));
	}

	void setFontRobotoBold(Graphics &g) const
	{
		g.setFont(Font(roboto_Bold));
	}

	void setFontRobotoBoldItalic(Graphics &g) const
	{
		g.setFont(Font(roboto_BoldItalic));
	}

	void setFontRobotoMedium(Graphics &g) const
	{
		g.setFont(Font(roboto_Medium));
	}

	Typeface::Ptr roboto_Black{
			Typeface::createSystemTypefaceFor(BinaryData::RobotoBlack_ttf, BinaryData::RobotoRegular_ttfSize) 
	};
	Typeface::Ptr roboto_BlackItalic{
		Typeface::createSystemTypefaceFor(BinaryData::RobotoBlackItalic_ttf, BinaryData::RobotoRegular_ttfSize)
	};

	Typeface::Ptr roboto_Bold{
		Typeface::createSystemTypefaceFor(BinaryData::RobotoBold_ttf,BinaryData::RobotoRegular_ttfSize)
	};
	Typeface::Ptr roboto_BoldItalic{
		Typeface::createSystemTypefaceFor(BinaryData::RobotoBoldItalic_ttf, BinaryData::RobotoRegular_ttfSize)
	};

	Typeface::Ptr robotoCondensed_Bold{
		Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedBold_ttf, BinaryData::RobotoRegular_ttfSize)
	};
	Typeface::Ptr robotoCondensed_BoldItalic{
		Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedBoldItalic_ttf, BinaryData::RobotoRegular_ttfSize)
	};
	Typeface::Ptr robotoCondensed_Italic{
			Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedItalic_ttf, BinaryData::RobotoRegular_ttfSize)
	};
	Typeface::Ptr robotoCondensed_Light = Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedLight_ttf,
		BinaryData::RobotoRegular_ttfSize);
	Typeface::Ptr robotoCondensed_LightItalic = Typeface::createSystemTypefaceFor(
		BinaryData::RobotoCondensedLightItalic_ttf, BinaryData::RobotoRegular_ttfSize);
	Typeface::Ptr robotoCondensed_Regular = Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensedRegular_ttf,
		BinaryData::RobotoRegular_ttfSize);

	Typeface::Ptr roboto_Italic = Typeface::createSystemTypefaceFor(BinaryData::RobotoItalic_ttf,
		BinaryData::RobotoRegular_ttfSize);

	Typeface::Ptr roboto_Light = Typeface::createSystemTypefaceFor(BinaryData::RobotoLight_ttf,
		BinaryData::RobotoRegular_ttfSize);
	Typeface::Ptr roboto_LightItalic = Typeface::createSystemTypefaceFor(BinaryData::RobotoLightItalic_ttf,
		BinaryData::RobotoRegular_ttfSize);

	Typeface::Ptr roboto_Medium = Typeface::createSystemTypefaceFor(BinaryData::RobotoMedium_ttf,
		BinaryData::RobotoRegular_ttfSize);
	Typeface::Ptr roboto_MediumItalic = Typeface::createSystemTypefaceFor(BinaryData::RobotoMediumItalic_ttf,
		BinaryData::RobotoRegular_ttfSize);

	Typeface::Ptr roboto_Regular = Typeface::createSystemTypefaceFor(BinaryData::RobotoRegular_ttf,
		BinaryData::RobotoRegular_ttfSize);

	Typeface::Ptr roboto_Thin = Typeface::createSystemTypefaceFor(BinaryData::RobotoThin_ttf,
		BinaryData::RobotoRegular_ttfSize);
	Typeface::Ptr roboto_ThinItalic = Typeface::createSystemTypefaceFor(BinaryData::RobotoThinItalic_ttf,
		BinaryData::RobotoRegular_ttfSize);
};
