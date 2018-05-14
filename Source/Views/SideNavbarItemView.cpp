#include "../../JuceLibraryCode/JuceHeader.h"
#include "SideNavbarItemView.h"

void SideNavbarItemView::paintButton(Graphics &g, bool isMouseOverButton, bool isButtonDown)
{
    const auto material = dynamic_cast<MaterialLookAndFeel *>(&getLookAndFeel());
    if (isMouseOverButton)
    {
        g.fillAll(findColour(Material::ColourIds::dividerColorId));
    }
    icon.setColour(findColour(Material::ColourIds::textSecondaryColorId));
    icon.getDrawable()->drawWithin(g, {
            MaterialLookAndFeel::convertDpToPixel(float(Material::Specs::NavigationDrawer::Modal::Padding::Left)),
            0.0f,
            MaterialLookAndFeel::convertDpToPixel(float(Material::Specs::NavigationDrawer::Modal::Dimensions::Icon)),
			float(getHeight())
    }, RectanglePlacement::centred, 1);
    g.setColour(findColour(Material::ColourIds::textSecondaryColorId));
    material->setFontRoboto(g);
    g.drawText(title,
               getLocalBounds()
                       .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::NavigationDrawer::Modal::Padding::Left)),
               Justification::centredLeft);
}