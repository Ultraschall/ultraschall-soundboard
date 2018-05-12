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
            MaterialLookAndFeel::convertDpToPixel<float>(Material::Size::ScreenEdge),
            0.0f,
            MaterialLookAndFeel::convertDpToPixel<float>(30),
            float(getHeight())
    }, RectanglePlacement::centred, 1);
    g.setColour(findColour(Material::ColourIds::textSecondaryColorId));
    material->setFontRobotoMedium(g);
    g.drawText(title,
               getLocalBounds()
                       .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::ContentLeftMargin))
                       .withTrimmedRight(MaterialLookAndFeel::convertDpToPixel<int>(Material::Size::ScreenEdge)),
               Justification::centredLeft);
}