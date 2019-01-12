#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Material.h"

namespace Material
{
class FloatingActionButton : public Button
{
  public:
    constexpr const static int iconSize = 24;
    constexpr const static int miniSize = 40;
    constexpr const static int extendedSize = 48;
    constexpr const static int size = 56;

    enum ColourIds
    {
        containerColourId = 0x8000000,
        iconColourId = 0x8000001
    };

    explicit FloatingActionButton(Material::Icon &icon) : Button("FloatingActionButton"), icon(icon)
    {
        setColour(ColourIds::iconColourId, Material::Color::Icons::Selected::OnPrimary::Active);
        setColour(ColourIds::containerColourId, Material::Color::Primary::Main);

        setPaintingIsUnclipped(true);
        setSize(px(miniSize), px(miniSize));
    }

    ~FloatingActionButton() noexcept override = default;

    void paintButton(Graphics &g, bool isMouseOverButton, bool isButtonDown) override
    {
        Path p;

        p.addEllipse(0, 0, getWidth(), getHeight());
        //shadow.drawForPath(g, p);
        g.setColour(findColour(ColourIds::containerColourId));
        g.fillPath(p);

        drawable->drawWithin(g, getLocalBounds().toFloat().withSizeKeepingCentre(px(iconSize), px(iconSize)), RectanglePlacement(RectanglePlacement::Flags::centred), 1.0f);
    }

    void colourChanged() override
    {
        drawable.reset(icon.getDrawable(findColour(ColourIds::iconColourId)));
    }

    void setRotation(float angle)
    {
        drawable->setTransform(AffineTransform().rotated(angle, drawable->getWidth() * 0.5f, drawable->getHeight() * 0.5f));
        repaint();
    }

  private:
    Material::Icon &icon;
    std::unique_ptr<Drawable> drawable;
    Material::Shadows::DropShadower6dp shadow;
};
} // namespace Material
