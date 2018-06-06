#pragma once

#include "JuceHeader.h"

namespace Material {
    class Icon {
    public:
        Icon(const char *data, const int size)
                : svg(XmlDocument::parse(String(CharPointer_UTF8(data), size))) {
        }

        Drawable *getDrawable(const Colour &colour = Colours::black) {
            auto drawable = Drawable::createFromSVG(*svg);
            drawable->replaceColour(Colours::black, colour);
            return drawable;
        }

    private:
        std::unique_ptr<XmlElement> svg;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Icon)
    };

    namespace Icons {
        static Icon add{BinaryData::sharpadd24px_svg, BinaryData::sharpadd24px_svgSize};
        static Icon menu{BinaryData::sharpmenu24px_svg, BinaryData::sharpmenu24px_svgSize};
        static Icon mic{BinaryData::sharpmic24px_svg, BinaryData::sharpmic24px_svgSize};
        static Icon mic_none{BinaryData::sharpmic_none24px_svg, BinaryData::sharpmic_none24px_svgSize};
        static Icon volume_mute{BinaryData::sharpvolume_mute24px_svg, BinaryData::sharpvolume_mute24px_svgSize};
        static Icon volume_up{BinaryData::sharpvolume_up24px_svg, BinaryData::sharpvolume_up24px_svgSize};
        static Icon format_list_numbered{BinaryData::sharpformat_list_numbered24px_svg, BinaryData::sharpformat_list_numbered24px_svgSize};
        static Icon view_comfy{BinaryData::sharpview_comfy24px_svg, BinaryData::sharpview_comfy24px_svgSize};
        static Icon subscriptions{BinaryData::sharpsubscriptions24px_svg, BinaryData::sharpsubscriptions24px_svgSize};
        static Icon lock{BinaryData::sharplock24px_svg, BinaryData::sharplock24px_svgSize};
        static Icon lock_open{BinaryData::sharplock_open24px_svg, BinaryData::sharplock_open24px_svgSize};
        static Icon settings{BinaryData::sharpsettings24px_svg, BinaryData::sharpsettings24px_svgSize};
        static Icon settings_input_antenna{BinaryData::sharpsettings_input_antenna24px_svg, BinaryData::sharpsettings_input_antenna24px_svgSize};
        static Icon settings_input_svideo{BinaryData::sharpsettings_input_svideo24px_svg, BinaryData::sharpsettings_input_svideo24px_svgSize};
        static Icon create_new_folder{BinaryData::sharpcreate_new_folder24px_svg, BinaryData::sharpcreate_new_folder24px_svgSize};
        static Icon file_copy{BinaryData::sharpfile_copy24px_svg, BinaryData::sharpfile_copy24px_svgSize};
        static Icon unarchive{BinaryData::sharpunarchive24px_svg, BinaryData::sharpunarchive24px_svgSize};
        static Icon call_made{BinaryData::sharpcall_made24px_svg, BinaryData::sharpcall_made24px_svgSize};
        static Icon pause{BinaryData::sharppause24px_svg, BinaryData::sharppause24px_svgSize};
        static Icon play_arrow{BinaryData::sharpplay_arrow24px_svg, BinaryData::sharpplay_arrow24px_svgSize};
        static Icon stop{BinaryData::sharpstop24px_svg, BinaryData::sharpstop24px_svgSize};
        static Icon volume_off{BinaryData::sharpvolume_off24px_svg, BinaryData::sharpvolume_off24px_svgSize};
        static Icon loop{BinaryData::sharploop24px_svg, BinaryData::sharploop24px_svgSize};

    }
}
