#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Material.h"

namespace Material
{
	class IconButton : public Button
	{
	public:
		constexpr const static int iconSize = 24;
		constexpr const static int minButtonSize = 48;

		enum ColourIds
		{
			iconColourId = 0x800001
		};

		explicit IconButton(Material::Icon &icon) : Button("IconButton"), icon(icon)
		{
			setColour(ColourIds::iconColourId, Material::Color::Icons::Selected::OnPrimary::Active);
			setSize(minButtonSize, minButtonSize);
		}

		~IconButton() override = default;

		void paintButton(Graphics &g, bool /*isMouseOverButton*/, bool /*isButtonDown*/) override
		{
			if (drawable != nullptr)
			{
				drawable->drawWithin(g,
					getLocalBounds().toFloat().withSizeKeepingCentre(px<float>(iconSize), px<float>(iconSize)),
					RectanglePlacement(RectanglePlacement::Flags::centred), 1.0f);
			}
		}

		void colourChanged() override
		{
			bool needRepaint = false;
			if (isColourSpecified(ColourIds::iconColourId))
			{
				drawable.reset(icon.getDrawable(findColour(ColourIds::iconColourId)));
				needRepaint = true;
			}
			if (needRepaint)
			{
				repaint();
			}
		}

	private:
		Material::Icon &icon;
		std::unique_ptr<Drawable> drawable;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IconButton)
	};

	class IconToggleButton : public Button
	{
	public:
		constexpr const static int iconSize = 24;
		constexpr const static int minButtonSize = 48;

		enum ColourIds
		{
			iconActiveColourId = 0x800002,
			iconInactiveColourId = 0x800003
		};

		IconToggleButton(Material::Icon &iconInactive, Material::Icon &iconActive) : Button("IconToggleButton"),
			iconActive(iconActive),
			iconInactive(iconInactive)
		{
			setColour(ColourIds::iconActiveColourId, Material::Color::Icons::Selected::OnPrimary::Active);
			setColour(ColourIds::iconInactiveColourId, Material::Color::Icons::Selected::OnPrimary::Inactive);

			setSize(px(minButtonSize), px(minButtonSize));
		}

		~IconToggleButton() override = default;

		void paintButton(Graphics &g, bool /*isMouseOverButton*/, bool /*isButtonDown*/) override
		{
			if (getToggleState())
			{
				if (drawableActive != nullptr)
				{
					drawableActive->drawWithin(g,
						getLocalBounds().toFloat().withSizeKeepingCentre(px<float>(iconSize), px<float>(iconSize)),
						RectanglePlacement(RectanglePlacement::Flags::centred), 1.0f);
				}
			}
			else
			{
				if (drawableInactive != nullptr)
				{
					drawableInactive->drawWithin(g,
						getLocalBounds().toFloat().withSizeKeepingCentre(px<float>(iconSize), px<float>(iconSize)),
						RectanglePlacement(RectanglePlacement::Flags::centred), 1.0f);
				}
			}
		}

		void colourChanged() override
		{
			bool needRepaint = false;
			if (isColourSpecified(ColourIds::iconActiveColourId))
			{
				drawableActive.reset(iconActive.getDrawable(findColour(ColourIds::iconActiveColourId)));
				needRepaint = true;
			}
			if (isColourSpecified(ColourIds::iconInactiveColourId))
			{
				drawableInactive.reset(iconInactive.getDrawable(findColour(ColourIds::iconInactiveColourId)));
				needRepaint = true;
			}
			if (needRepaint)
			{
				repaint();
			}
		}

	private:
		Material::Icon &iconActive;
		Material::Icon &iconInactive;
		std::unique_ptr<Drawable> drawableActive;
		std::unique_ptr<Drawable> drawableInactive;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IconToggleButton)
	};
} // namespace Material
