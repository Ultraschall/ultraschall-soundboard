#include "../../JuceLibraryCode/JuceHeader.h"
#include "SideNavbarItemView.h"

void SideNavbarItemView::paintButton(Graphics &g, bool isMouseOverButton, bool /*isButtonDown*/)
{
    const auto material = dynamic_cast<MaterialLookAndFeel *>(&getLookAndFeel());
    if (isMouseOverButton)
    {
		g.setColour(findColour(Material::ColourIds::dividerColorId));
		g.fillRect(getLocalBounds()
			.reduced(MaterialLookAndFeel::convertDpToPixel(8))
		);
    }

    icon.setColour(findColour(Material::ColourIds::textPrimaryColorId));
    icon.getDrawable()->drawWithin(g, {
            MaterialLookAndFeel::convertDpToPixel(float(Material::Specs::NavigationDrawer::Modal::Padding::Left)),
            0.0f,
            MaterialLookAndFeel::convertDpToPixel(float(Material::Specs::NavigationDrawer::Modal::Dimensions::Icon)),
			float(getHeight())
    }, RectanglePlacement::centred, 1);

    g.setColour(findColour(Material::ColourIds::textPrimaryColorId));
	g.setFont(Font(material->robotoCondensed_Regular));
	g.setFont(14);
    g.drawText(title,
               getLocalBounds()
                       .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Standard::Padding::TextLeft)),
               Justification::centredLeft);
}