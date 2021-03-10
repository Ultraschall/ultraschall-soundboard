cmake_minimum_required(VERSION 3.15)
project("Ultraschall Soundboard" VERSION 4.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES arm64 x86_64)
endif()

add_subdirectory("./JUCE" JUCE)

juce_add_plugin(Soundboard
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
	PRODUCT_NAME "Soundboard"
    )

juce_add_modules(
	ALIAS_NAMESPACE danlin
	modules/danlin_fontawesome
	modules/danlin_oscpack
	modules/danlin_oscserver)
juce_add_modules(
	ALIAS_NAMESPACE stk
	modules/stk_core
	modules/stk_generators)

target_compile_definitions(Soundboard PUBLIC JUCER_ENABLE_GPL_MODE=1)
target_compile_definitions(Soundboard PUBLIC JUCE_DISPLAY_SPLASH_SCREEN=0)
target_compile_definitions(Soundboard PUBLIC JUCE_USE_LAME_AUDIO_FORMAT=1)

file(GLOB_RECURSE
    SOURCE_LIST
    CONFIGURE_DEPENDS
    src/*.cpp
    src/*.h
)
target_sources(Soundboard
	PRIVATE
    ${SOURCE_LIST}
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_LIST})


target_compile_definitions(Soundboard
	PUBLIC
		JUCE_WEB_BROWSER=0
		JUCE_USE_CURL=0
		JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(Soundboard
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
