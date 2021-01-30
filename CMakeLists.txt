cmake_minimum_required(VERSION 3.15)
project(ULTRASCHALL_SOUNDBOARD VERSION 4.0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES arm64 x86_64)
endif()

add_subdirectory("./JUCE" JUCE)

juce_add_plugin(UltraschallSoundboard
	IS_SYNTH TRUE
	NEEDS_MIDI_INPUT TRUE
	EDITOR_WANTS_KEYBOARD_FOCUS TRUE
	COPY_PLUGIN_AFTER_BUILD FALSE
	PLUGIN_MANUFACTURER_CODE Ultr
	PLUGIN_CODE Sndb
	COMPANY_NAME Ultraschall
	COMPANY_WEBSITE https://ultraschall.fm
	COMPANY_EMAIL info@ultraschall.fm
	DESCRIPTION Ultraschall Soundboard
	FORMATS AU VST3 Standalone
	VST3_CATEGORIES Instrument
	AU_MAIN_TYPE kAudioUnitType_Generator
	PRODUCT_NAME "Soundboard")

juce_add_modules(
	ALIAS_NAMESPACE danlin
	modules/danlin_fontawesome
	modules/danlin_oscpack
	modules/danlin_oscserver)
juce_add_modules(
	ALIAS_NAMESPACE stk
	modules/stk_core
	modules/stk_generators)

target_compile_definitions(UltraschallSoundboard PUBLIC JUCER_ENABLE_GPL_MODE=1)
target_compile_definitions(UltraschallSoundboard PUBLIC JUCE_DISPLAY_SPLASH_SCREEN=0)
target_compile_definitions(UltraschallSoundboard PUBLIC JUCE_USE_LAME_AUDIO_FORMAT=1)

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
