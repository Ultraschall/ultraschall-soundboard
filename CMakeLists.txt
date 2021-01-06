cmake_minimum_required(VERSION 3.15)
project(ULTRASCHALL_SOUNDBOARD VERSION 4.0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(JUCE)

juce_add_plugin(UltraschallSoundboard
	# ICON_BIG ...                              # ICON_* arguments specify a path to an image file to use as an icon for the Standalone
	# ICON_SMALL ...
	# COMPANY_NAME ...                          # Specify the name of the plugin's author
	# IS_SYNTH TRUE/FALSE                       # Is this a synth or an effect?
	# NEEDS_MIDI_INPUT TRUE/FALSE               # Does the plugin need midi input?
	# NEEDS_MIDI_OUTPUT TRUE/FALSE              # Does the plugin need midi output?
	# IS_MIDI_EFFECT TRUE/FALSE                 # Is this plugin a MIDI effect?
	# EDITOR_WANTS_KEYBOARD_FOCUS TRUE/FALSE    # Does the editor need keyboard focus?
	# COPY_PLUGIN_AFTER_BUILD TRUE/FALSE        # Should the plugin be installed to a default location after building?
	PLUGIN_MANUFACTURER_CODE Ultr               # A four-character manufacturer id with at least one upper-case character
	PLUGIN_CODE Sndb                            # A unique four-character plugin id with at least one upper-case character
	FORMATS AU VST3 Standalone                  # The formats to build. Other valid formats are: AAX Unity VST AU AUv3
	PRODUCT_NAME "Soundboard")        # The name of the final executable, which can differ from the target name

juce_add_modules(
	ALIAS_NAMESPACE danlin
	modules/danlin_fontawesome
	modules/danlin_oscpack
	modules/danlin_oscserver)
juce_add_modules(
	ALIAS_NAMESPACE stk
	modules/stk_core
	modules/stk_generators)

juce_generate_juce_header(UltraschallSoundboard)

target_sources(UltraschallSoundboard
	PRIVATE
		src/plugin/PluginEditor.cpp
		src/plugin/PluginProcessor.cpp
		src/shared/player/Bank.cpp
		src/shared/player/Library.cpp
		src/shared/player/Player.cpp
		src/shared/player/Slot.cpp
		src/shared/ui/LookAndFeel.cpp
		src/shared/ui/grid/GridCell.cpp
		src/shared/ui/grid/GridComponent.cpp
		src/shared/ui/settings/SettingsComponent.cpp
		src/shared/ui/table/TableButtonCell.cpp
		src/shared/ui/table/TableComponent.cpp)

target_compile_definitions(UltraschallSoundboard
	PUBLIC
		JUCE_WEB_BROWSER=0
		JUCE_USE_CURL=0
		JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(UltraschallSoundboard
	PRIVATE
		juce::juce_audio_basics
		juce::juce_audio_devices
		juce::juce_audio_formats
		juce::juce_audio_plugin_client
		juce::juce_audio_processors
		juce::juce_audio_utils
		juce::juce_core
		juce::juce_data_structures
		juce::juce_events
		juce::juce_graphics
		juce::juce_gui_basics
		juce::juce_gui_extra
		danlin::danlin_fontawesome
		danlin::danlin_oscpack
		danlin::danlin_oscserver
		stk::stk_core
		stk::stk_generators
	PUBLIC
		juce::juce_recommended_config_flags
		juce::juce_recommended_lto_flags
		juce::juce_recommended_warning_flags)
