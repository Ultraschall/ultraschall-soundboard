cmake_minimum_required(VERSION 3.15)
project("Ultraschall Soundboard" VERSION 5.0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(APPLE)
	set(CMAKE_OSX_ARCHITECTURES arm64 x86_64)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("./JUCE" JUCE)

juce_add_plugin(
	UltraschallSoundboard
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
	ICON_BIG Assets/AppIcons/iOS/Icon-76@2x.png
)

target_compile_definitions(UltraschallSoundboard PUBLIC JUCER_ENABLE_GPL_MODE=1)
target_compile_definitions(UltraschallSoundboard PUBLIC JUCE_DISPLAY_SPLASH_SCREEN=0)
target_compile_definitions(UltraschallSoundboard PUBLIC JUCE_USE_LAME_AUDIO_FORMAT=1)

juce_generate_juce_header(UltraschallSoundboard)

target_sources(UltraschallSoundboard
	PRIVATE
		Source/PluginEditor.cpp
		Source/PluginProcessor.cpp
		Source/Engine/Engine.cpp
		Source/Engine/Envelope.cpp
		Source/Engine/Player.cpp
		Source/LookAndFeel/Colors.cpp
		Source/LookAndFeel/Fonts.cpp
		Source/LookAndFeel/Icons.cpp
		Source/Store/Store.cpp
		Source/Store/Middleware/EngineMiddleware.cpp
		Source/Store/Middleware/MidiMiddleware.cpp
		Source/Store/Middleware/OscMiddleware.cpp
		Source/UserInterface/Controllers/BankViewController.cpp
		Source/UserInterface/Controllers/ClipViewController.cpp
		Source/UserInterface/Controllers/LibraryViewController.cpp
		Source/UserInterface/Controllers/MainViewController.cpp
		Source/UserInterface/Controllers/MidiSettingsViewController.cpp
		Source/UserInterface/Controllers/OscSettingsViewController.cpp
		Source/UserInterface/Controllers/PlaylistViewController.cpp
		Source/UserInterface/Controllers/SettingsViewController.cpp
		)

juce_add_binary_data(assets
	SOURCES
		Assets/Fonts/Roboto/Roboto-Black.ttf
		Assets/Fonts/Roboto/Roboto-BlackItalic.ttf
		Assets/Fonts/Roboto/Roboto-Bold.ttf
		Assets/Fonts/Roboto/Roboto-BoldItalic.ttf
		Assets/Fonts/Roboto/Roboto-Italic.ttf
		Assets/Fonts/Roboto/Roboto-Light.ttf
		Assets/Fonts/Roboto/Roboto-LightItalic.ttf
		Assets/Fonts/Roboto/Roboto-Medium.ttf
		Assets/Fonts/Roboto/Roboto-MediumItalic.ttf
		Assets/Fonts/Roboto/Roboto-Regular.ttf
		Assets/Fonts/Roboto/Roboto-Thin.ttf
		Assets/Fonts/Roboto/Roboto-ThinItalic.ttf	

		Assets/Fonts/Roboto_Mono/RobotoMono-Bold.ttf
		Assets/Fonts/Roboto_Mono/RobotoMono-BoldItalic.ttf
		Assets/Fonts/Roboto_Mono/RobotoMono-Italic.ttf
		Assets/Fonts/Roboto_Mono/RobotoMono-Light.ttf
		Assets/Fonts/Roboto_Mono/RobotoMono-LightItalic.ttf
		Assets/Fonts/Roboto_Mono/RobotoMono-Medium.ttf
		Assets/Fonts/Roboto_Mono/RobotoMono-MediumItalic.ttf
		Assets/Fonts/Roboto_Mono/RobotoMono-Regular.ttf
		Assets/Fonts/Roboto_Mono/RobotoMono-Thin.ttf
		Assets/Fonts/Roboto_Mono/RobotoMono-ThinItalic.ttf	

		Assets/Icons/sharp-create_new_folder-24px.svg
		Assets/Icons/sharp-call_made-24px.svg
		Assets/Icons/sharp-view_comfy-24px.svg
		Assets/Icons/sharp-menu-24px.svg
		Assets/Icons/sharp-volume_up-24px.svg
		Assets/Icons/arrow_back_ios-24px.svg
		Assets/Icons/sharp-play_arrow-24px.svg
		Assets/Icons/sharp-stop-24px.svg
		Assets/Icons/sharp-mic-24px.svg
		Assets/Icons/sharp-loop-24px.svg
		Assets/Icons/sharp-unarchive-24px.svg
		Assets/Icons/sharp-mic_none-24px.svg
		Assets/Icons/sharp-settings_input_antenna-24px.svg
		Assets/Icons/sharp-add-24px.svg
		Assets/Icons/sharp-pause-24px.svg
		Assets/Icons/sharp-lock_open-24px.svg
		Assets/Icons/sharp-format_list_numbered-24px.svg
		Assets/Icons/sharp-subscriptions-24px.svg
		Assets/Icons/sharp-file_copy-24px.svg
		Assets/Icons/arrow_forward_ios-24px.svg
		Assets/Icons/sharp-lock-24px.svg
		Assets/Icons/sharp-settings_input_svideo-24px.svg
		Assets/Icons/sharp-volume_mute-24px.svg
		Assets/Icons/sharp-settings-24px.svg
		Assets/Icons/sharp-volume_off-24px.svg
		
		)

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
		juce::juce_osc
		juce::juce_opengl
		assets
	PUBLIC
		juce::juce_recommended_config_flags
		juce::juce_recommended_lto_flags
		juce::juce_recommended_warning_flags)