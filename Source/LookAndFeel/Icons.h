#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

namespace Material
{
	class Icon
	{
	public:
		explicit Icon(const char *data, const int size)
		{
			svg = XmlDocument::parse(String::fromUTF8(data, size));
		}

		std::unique_ptr<Drawable> getDrawable(const Colour &colour = Colours::black)
		{
			auto drawable = Drawable::createFromSVG(*svg);
			drawable->replaceColour(Colours::black, colour);
			return drawable;
		}

	private:
		std::unique_ptr<XmlElement> svg;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Icon)
	};

	namespace Icons
	{
		extern Icon add;
		extern Icon menu;
		extern Icon mic;
		extern Icon mic_none;
		extern Icon volume_mute;
		extern Icon volume_up;
		extern Icon format_list_numbered;
		extern Icon view_comfy;
		extern Icon subscriptions;
		extern Icon lock;
		extern Icon lock_open;
		extern Icon settings;
		extern Icon settings_input_antenna;
		extern Icon settings_input_svideo;
		extern Icon create_new_folder;
		extern Icon file_copy;
		extern Icon unarchive;
		extern Icon call_made;
		extern Icon pause;
		extern Icon play_arrow;
		extern Icon stop;
		extern Icon volume_off;
		extern Icon loop;
		extern Icon back;
		extern Icon forward;

	} // namespace Icons
} // namespace Material
