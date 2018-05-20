#include "../../JuceLibraryCode/JuceHeader.h"
#include "SideNavbarItemView.h"

void SideNavbarItem::paintButton(Graphics &g, bool isMouseOverButton, bool /*isButtonDown*/)
{
    const auto material = dynamic_cast<MaterialLookAndFeel *>(&getLookAndFeel());
    if (isMouseOverButton)
    {
		g.setColour(findColour(Material::ColourIds::dividerColorId));
		g.fillRoundedRectangle(getLocalBounds().reduced(MaterialLookAndFeel::convertDpToPixel(8)).toFloat(), MaterialLookAndFeel::convertDpToPixel(4.0f));
    }

    icon.getDrawable()->drawWithin(g, {
            MaterialLookAndFeel::convertDpToPixel<float>(Material::Specs::NavigationDrawer::Modal::Padding::Left),
            0.0f,
            MaterialLookAndFeel::convertDpToPixel<float>(Material::Specs::NavigationDrawer::Modal::Dimensions::Icon),
			float(getHeight())
    }, RectanglePlacement::onlyReduceInSize, 1);

    g.setColour(findColour(Material::ColourIds::textPrimaryColorId));
	g.setFont(Font(material->robotoCondensed_Bold));
	g.setFont(MaterialLookAndFeel::convertDpToPixel(14));
    g.drawText(text,
               getLocalBounds()
                       .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Padding::TextLeft)),
               Justification::centredLeft);
}

void SideNavbarTitle::paint(Graphics &g) {
    const auto material = dynamic_cast<MaterialLookAndFeel *>(&getLookAndFeel());
    auto font = Font(material->robotoCondensed_Regular);

    g.setColour(findColour(Material::textSecondaryColorId));
    g.setFont(font);
    g.setFont(MaterialLookAndFeel::convertDpToPixel(14));
    g.drawText(text, getLocalBounds()
            .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Padding::Left))
            .withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Bottom)), Justification::bottomLeft);
}

void SideNavbarSeperator::paint(Graphics &g) {
    g.setColour(findColour(Material::ColourIds::dividerColorId));
    auto y = getHeight() * 0.5f;
    g.drawLine(0, y, getWidth(), y);
}
