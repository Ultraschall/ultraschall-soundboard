#include "../../JuceLibraryCode/JuceHeader.h"
#include "LibraryRowView.h"

LibraryRowView::LibraryRowView()
{
    addAndMakeVisible(playButton);
    addAndMakeVisible(stopButton);
    addAndMakeVisible(settingsButton);
    addAndMakeVisible(loopButton);
    addAndMakeVisible(fadeButton);
}

LibraryRowView::~LibraryRowView()
{
    if (!audioThumbnail.expired())
    {
        audioThumbnail.lock()->removeChangeListener(this);
    }
}

void LibraryRowView::paint(Graphics &g)
{
    const auto material = dynamic_cast<MaterialLookAndFeel *>(&getLookAndFeel());

    g.fillAll(findColour(Material::ColourIds::dialogColorId));
    g.setColour(findColour(Material::ColourIds::dividerColorId));
    g.drawLine(0, getHeight() - 1, getWidth(), getHeight() - 1);

    g.setColour(findColour(Material::ColourIds::dialogColorId).contrasting(0.05));
    if (!audioThumbnail.expired())
    {
        auto thumbnail = audioThumbnail.lock();
        if (thumbnail->getTotalLength() > 0.0)
        {
            thumbnail->drawChannel(g, getLocalBounds()
                                                .withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Base))
                                                .withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Base)),
                                        0, thumbnail->getTotalLength(), 1, 1.0f);
        }
    }

    //    g.setColour(findColour(Material::ColourIds::primaryColorId));
    //	g.fillRect(getLocalBounds().withTrimmedBottom(iconBarSize));

//    g.setColour(findColour(Material::ColourIds::textPrimaryColorId));
//    material->setFontRoboto(g);
//    g.setFont(14);
//    g.drawText(title,
//               getLocalBounds()
//                       .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Base))
//                       .withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Base)),
//               Justification::topLeft
//    );

    //g.setColour(findColour(Material::ColourIds::textSecondaryColorId));
    //g.setFont(8);
    //g.drawText("00:00:00", getLocalBounds()
    //                   .removeFromRight(MaterialLookAndFeel::convertDpToPixel(96))
    //                   .withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge + 26)),
    //           Justification::topLeft);

    //auto p = 0.75;
    //g.fillRect(
    //        getLocalBounds()
    //                .withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(108))
    //                .withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge + 30))
    //                .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge + 8))
    //                .withHeight(MaterialLookAndFeel::convertDpToPixel(8))
    //);
//	g.fillRect(
//			getLocalBounds()
//					.withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(108))
//					.withTrimmedTop(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge + 30))
//					.withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Size::ScreenEdge + 8))
//					.withHeight(MaterialLookAndFeel::convertDpToPixel(8))
//	);
    //g.setColour(findColour(Material::ColourIds::dividerColorId));
    //g.fillRectList(getLocalBounds().withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(66)).removeFromBottom(MaterialLookAndFeel::convertDpToPixel(24)).withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(16)).withRight(MaterialLookAndFeel::convertDpToPixel(166)));
    //g.setColour(findColour(Material::ColourIds::primaryColorId));
    //g.fillRectList(getLocalBounds().withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(66)).removeFromBottom(MaterialLookAndFeel::convertDpToPixel(24)).withTrimmedBottom(MaterialLookAndFeel::convertDpToPixel(16)).withRight(MaterialLookAndFeel::convertDpToPixel(166 * progress)));
}

void LibraryRowView::resized()
{
    const auto iconSize = MaterialLookAndFeel::convertDpToPixel(40);
    FlexBox flexBox;

    flexBox.items.add(FlexItem(settingsButton).withMaxWidth(iconSize).withFlex(1));
    flexBox.items.add(FlexItem(loopButton).withMaxWidth(iconSize).withFlex(1));
    flexBox.items.add(FlexItem(spacer).withFlex(2));
    flexBox.items.add(FlexItem(fadeButton).withMaxWidth(iconSize).withFlex(1));
    flexBox.items.add(FlexItem(stopButton).withMaxWidth(iconSize).withFlex(1));
    flexBox.items.add(FlexItem(playButton).withMaxWidth(iconSize).withFlex(1));

    flexBox.performLayout(
            getLocalBounds()
                    .withTrimmedLeft(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Left))
                    .withTrimmedRight(MaterialLookAndFeel::convertDpToPixel(Material::Specs::Global::Padding::Right))
    );
}
