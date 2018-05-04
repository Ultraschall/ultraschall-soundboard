# Automatically generated CMakeLists, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

cmake_minimum_required (VERSION 3.4.1)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Debug"  CACHE STRING "Choose the type of build." FORCE)
endif (NOT CMAKE_BUILD_TYPE)

###############################################################################
# Xcode (MacOSX)
###############################################################################

if (APPLE)

project ("Ultraschall Soundboard" C CXX)

add_executable (STANDALONE_PLUGIN
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_Standalone.cpp"
    "../../JuceLibraryCode/include_juce_audio_plugin_client_Standalone.cpp"
)

set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_Standalone.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)

add_library (SHARED_CODE STATIC
    "../../Assets/ic_mic_none_white_48px.svg"
    "../../Assets/ic_mic_white_48px.svg"
    "../../Assets/ic_pause_circle_outline_white_48px.svg"
    "../../Assets/ic_play_circle_outline_white_48px.svg"
    "../../Assets/ic_volume_up_white_48px.svg"
    "../../Assets/ic_view_headline_white_48px.svg"
    "../../Assets/ic_settings_white_48px.svg"
    "../../Assets/ic_view_module_white_48px.svg"
    "../../Assets/ic_folder_open_white_48px.svg"
    "../../Source/Models/Identifier.h"
    "../../Source/Models/Utilities.h"
    "../../Source/Models/ValueTreeObjectList.h"
    "../../Source/Models/ClipModel.h"
    "../../Source/Models/PlayerModel.h"
    "../../Source/Views/BankView.cpp"
    "../../Source/Views/BankView.h"
    "../../Source/Views/ClipView.cpp"
    "../../Source/Views/ClipView.h"
    "../../Source/Views/DrawingTools.cpp"
    "../../Source/Views/DrawingTools.h"
    "../../Source/Views/LibraryView.cpp"
    "../../Source/Views/LibraryView.h"
    "../../Source/Views/MainView.cpp"
    "../../Source/Views/MainView.h"
    "../../Source/Controller/ClipViewController.cpp"
    "../../Source/Controller/ClipViewController.h"
    "../../Source/Controller/LibraryViewController.cpp"
    "../../Source/Controller/LibraryViewController.h"
    "../../Source/Controller/MainViewController.cpp"
    "../../Source/Controller/MainViewController.h"
    "../../Source/Controller/ViewController.h"
    "../../Source/Engine/ADSR.cpp"
    "../../Source/Engine/ADSR.h"
    "../../Source/Engine/Library.cpp"
    "../../Source/Engine/Library.h"
    "../../Source/Engine/Player.cpp"
    "../../Source/Engine/Player.h"
    "../../Source/PluginProcessor.cpp"
    "../../Source/PluginProcessor.h"
    "../../Source/PluginEditor.cpp"
    "../../Source/PluginEditor.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioSampleBuffer.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_Decibels.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LinearSmoothedValue.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_Reverb.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_AudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_PositionableAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.mm"
    "../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_SystemAudioVolume.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiInput.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Audio.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Midi.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Oboe.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_OpenSL.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_ALSA.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_Bela.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_Midi.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_mac_CoreAudio.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_mac_CoreMidi.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_MidiDataConcatenator.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_ASIO.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_DirectSound.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_Midi.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_WASAPI.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.mm"
    "../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitmath.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitreader.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/cpu.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/crc.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/fixed.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/float.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/format.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/md5.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/memory.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/window_flac.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/all.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/alloc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/assert.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/callback.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/compat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/endswap.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/export.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/Flac Licence.txt"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/format.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/metadata.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/ordinals.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/stream_decoder.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/stream_encoder.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/win_utf8_io.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_51.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_stereo.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/floor/floor_books.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/uncoupled/res_books_uncoupled.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/floor_all.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_8.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_11.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_16.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_44.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_8.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_16.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44p51.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44u.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_8.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_11.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_16.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_22.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_32.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44p51.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44u.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_X.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/analysis.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/backends.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/block.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codec_internal.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor0.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor1.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/highlevel.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/info.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup_data.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mapping0.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/masking.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/misc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/os.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/res0.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/scales.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/sharedbook.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/synthesis.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisenc.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisfile.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/bitwise.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/codec.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/config_types.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/framing.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/ogg.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/os_types.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisenc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisfile.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.mm"
    "../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBaseHelper.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewDispatch.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputFormatConverter.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUSilentTimeout.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUTimestampGenerator.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUViewLocalizedStringKeys.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomic.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomicStack.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAutoDisposer.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugMacros.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugPrintf.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAException.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAHostTimeBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMath.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAReferenceCounted.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAThreadSafeList.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnitTypes.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAXException.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterApp.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_CarbonVisibility.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_CheckSettingMacros.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_FakeMouseMoveGenerator.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeModuleHeaders.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeSystemHeaders.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginHostType.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_WindowsHooks.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.mm"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VSTCallbackHandler.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_utils.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST_utils.mm"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3Common.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3Headers.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTCommon.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTInterface.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTMidiEventList.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorListener.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameter.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameters.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.mm"
    "../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDBurner.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailBase.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_linux_AudioCDReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDBurner.mm"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDReader.mm"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.mm"
    "../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_AbstractFifo.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_Array.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_DynamicObject.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_DynamicObject.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_ElementComparator.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_HashMap.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_HashMap_test.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_LinkedListPointer.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_ListenerList.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_NamedValueSet.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_OwnedArray.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_PropertySet.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_PropertySet.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_SortedSet.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_SparseSet.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_Variant.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_Variant.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_DirectoryIterator.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_File.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_File.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileFilter.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileFilter.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileInputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileInputStream.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileOutputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileOutputStream.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileSearchPath.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileSearchPath.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_MemoryMappedFile.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_TemporaryFile.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_TemporaryFile.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_WildcardFileFilter.h"
    "../../Submodules/JUCE/modules/juce_core/javascript/juce_Javascript.cpp"
    "../../Submodules/JUCE/modules/juce_core/javascript/juce_Javascript.h"
    "../../Submodules/JUCE/modules/juce_core/javascript/juce_JSON.cpp"
    "../../Submodules/JUCE/modules/juce_core/javascript/juce_JSON.h"
    "../../Submodules/JUCE/modules/juce_core/logging/juce_FileLogger.cpp"
    "../../Submodules/JUCE/modules/juce_core/logging/juce_FileLogger.h"
    "../../Submodules/JUCE/modules/juce_core/logging/juce_Logger.cpp"
    "../../Submodules/JUCE/modules/juce_core/logging/juce_Logger.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_BigInteger.cpp"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_BigInteger.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_Expression.cpp"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_Expression.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_MathsFunctions.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_NormalisableRange.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_Random.cpp"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_Random.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_Range.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_Atomic.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_ByteOrder.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_HeapBlock.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_Memory.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_MemoryBlock.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_ScopedPointer.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_Singleton.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_WeakReference.h"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_Result.cpp"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_Result.h"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_RuntimePermissions.h"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.cpp"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.h"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_Uuid.cpp"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_Uuid.h"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_WindowsRegistry.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_Files.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_JNIHelpers.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_Misc.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_Network.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_SystemStats.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_Threads.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_curl_Network.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_linux_Files.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_linux_Network.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_linux_Threads.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_ClangBugWorkaround.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_Files.mm"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_Network.mm"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_Strings.mm"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_SystemStats.mm"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_Threads.mm"
    "../../Submodules/JUCE/modules/juce_core/native/juce_osx_ObjCHelpers.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_posix_SharedCode.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_Files.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_Network.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_Registry.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_Threads.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_IPAddress.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_IPAddress.h"
    "../../Submodules/JUCE/modules/juce_core/network/juce_MACAddress.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_MACAddress.h"
    "../../Submodules/JUCE/modules/juce_core/network/juce_NamedPipe.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_NamedPipe.h"
    "../../Submodules/JUCE/modules/juce_core/network/juce_Socket.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_Socket.h"
    "../../Submodules/JUCE/modules/juce_core/network/juce_URL.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_URL.h"
    "../../Submodules/JUCE/modules/juce_core/network/juce_WebInputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_WebInputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_BufferedInputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_FileInputSource.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_FileInputSource.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_InputSource.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_InputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_InputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryInputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_OutputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_OutputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_SubregionStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_SubregionStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_URLInputSource.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_URLInputSource.h"
    "../../Submodules/JUCE/modules/juce_core/system/juce_CompilerSupport.h"
    "../../Submodules/JUCE/modules/juce_core/system/juce_PlatformDefs.h"
    "../../Submodules/JUCE/modules/juce_core/system/juce_StandardHeader.h"
    "../../Submodules/JUCE/modules/juce_core/system/juce_SystemStats.cpp"
    "../../Submodules/JUCE/modules/juce_core/system/juce_SystemStats.h"
    "../../Submodules/JUCE/modules/juce_core/system/juce_TargetPlatform.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_Base64.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_Base64.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharacterFunctions.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_Identifier.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_Identifier.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_LocalisedStrings.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_NewLine.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_String.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_String.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringArray.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringArray.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringPairArray.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringPairArray.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringPool.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringPool.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringRef.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_TextDiff.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_TextDiff.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ChildProcess.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ChildProcess.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_CriticalSection.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_DynamicLibrary.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_InterProcessLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_Process.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ReadWriteLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedReadLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_SpinLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_Thread.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_Thread.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadPool.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadPool.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_TimeSliceThread.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_WaitableEvent.h"
    "../../Submodules/JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp"
    "../../Submodules/JUCE/modules/juce_core/time/juce_PerformanceCounter.h"
    "../../Submodules/JUCE/modules/juce_core/time/juce_RelativeTime.cpp"
    "../../Submodules/JUCE/modules/juce_core/time/juce_RelativeTime.h"
    "../../Submodules/JUCE/modules/juce_core/time/juce_Time.cpp"
    "../../Submodules/JUCE/modules/juce_core/time/juce_Time.h"
    "../../Submodules/JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp"
    "../../Submodules/JUCE/modules/juce_core/unit_tests/juce_UnitTest.h"
    "../../Submodules/JUCE/modules/juce_core/xml/juce_XmlDocument.cpp"
    "../../Submodules/JUCE/modules/juce_core/xml/juce_XmlDocument.h"
    "../../Submodules/JUCE/modules/juce_core/xml/juce_XmlElement.cpp"
    "../../Submodules/JUCE/modules/juce_core/xml/juce_XmlElement.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/adler32.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/compress.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/crc32.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/crc32.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/deflate.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/deflate.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/infback.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inffast.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inffast.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inffixed.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inflate.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inflate.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inftrees.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inftrees.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/trees.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/trees.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/uncompr.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/zconf.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/zconf.in.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/zlib.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/zutil.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/zutil.h"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_ZipFile.cpp"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_ZipFile.h"
    "../../Submodules/JUCE/modules/juce_core/juce_core.cpp"
    "../../Submodules/JUCE/modules/juce_core/juce_core.mm"
    "../../Submodules/JUCE/modules/juce_core/juce_core.h"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.h"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_Primes.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_Primes.h"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.h"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_MD5.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_MD5.h"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_SHA256.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_SHA256.h"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.h"
    "../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.mm"
    "../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.h"
    "../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h"
    "../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h"
    "../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h"
    "../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_CachedValue.h"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_Value.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_Value.h"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTree.h"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h"
    "../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.mm"
    "../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.h"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionListener.h"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_ApplicationBase.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_CallbackMessage.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_Initialisation.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_Message.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_MessageListener.cpp"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_MessageListener.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_MessageManager.cpp"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_MessageManager.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_NotificationType.h"
    "../../Submodules/JUCE/modules/juce_events/native/juce_android_Messaging.cpp"
    "../../Submodules/JUCE/modules/juce_events/native/juce_ios_MessageManager.mm"
    "../../Submodules/JUCE/modules/juce_events/native/juce_linux_EventLoop.h"
    "../../Submodules/JUCE/modules/juce_events/native/juce_linux_Messaging.cpp"
    "../../Submodules/JUCE/modules/juce_events/native/juce_mac_MessageManager.mm"
    "../../Submodules/JUCE/modules/juce_events/native/juce_osx_MessageQueue.h"
    "../../Submodules/JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h"
    "../../Submodules/JUCE/modules/juce_events/native/juce_win32_Messaging.cpp"
    "../../Submodules/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp"
    "../../Submodules/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h"
    "../../Submodules/JUCE/modules/juce_events/timers/juce_MultiTimer.cpp"
    "../../Submodules/JUCE/modules/juce_events/timers/juce_MultiTimer.h"
    "../../Submodules/JUCE/modules/juce_events/timers/juce_Timer.cpp"
    "../../Submodules/JUCE/modules/juce_events/timers/juce_Timer.h"
    "../../Submodules/JUCE/modules/juce_events/juce_events.cpp"
    "../../Submodules/JUCE/modules/juce_events/juce_events.mm"
    "../../Submodules/JUCE/modules/juce_events/juce_events.h"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colour.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colour.h"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_ColourGradient.h"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colours.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colours.h"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_FillType.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_FillType.h"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_PixelFormats.h"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h"
    "../../Submodules/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h"
    "../../Submodules/JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/effects/juce_GlowEffect.h"
    "../../Submodules/JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_AttributedString.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Font.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Font.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_TextLayout.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Typeface.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_BorderSize.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Line.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Path.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Path.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathIterator.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Point.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Rectangle.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_RectangleList.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/png.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/png.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_Image.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_Image.h"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageCache.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageCache.h"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/placement/juce_Justification.h"
    "../../Submodules/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h"
    "../../Submodules/JUCE/modules/juce_graphics/juce_graphics.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/juce_graphics.mm"
    "../../Submodules/JUCE/modules/juce_graphics/juce_graphics.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/application/juce_Application.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/application/juce_Application.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_Button.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Component.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Component.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Desktop.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Desktop.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Grid.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridItem.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridUnitTests.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Viewport.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Clipboard.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Windowing.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Label.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Slider.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.mm"
    "../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.h"
    "../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Draggable3DOrientation.h"
    "../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Matrix3D.h"
    "../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Quaternion.h"
    "../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Vector3D.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_MissingGLDefinitions.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_android.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_ios.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_linux_X11.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_osx.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_win32.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGLExtensions.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLRenderer.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.h"
    "../../Submodules/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.h"
    "../../Submodules/JUCE/modules/juce_opengl/juce_opengl.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/juce_opengl.mm"
    "../../Submodules/JUCE/modules/juce_opengl/juce_opengl.h"
    "../../Submodules/JUCE/modules/juce_video/capture/juce_CameraDevice.cpp"
    "../../Submodules/JUCE/modules/juce_video/capture/juce_CameraDevice.h"
    "../../Submodules/JUCE/modules/juce_video/native/juce_android_CameraDevice.h"
    "../../Submodules/JUCE/modules/juce_video/native/juce_mac_CameraDevice.h"
    "../../Submodules/JUCE/modules/juce_video/native/juce_mac_Video.h"
    "../../Submodules/JUCE/modules/juce_video/native/juce_win32_CameraDevice.h"
    "../../Submodules/JUCE/modules/juce_video/native/juce_win32_Video.h"
    "../../Submodules/JUCE/modules/juce_video/playback/juce_VideoComponent.cpp"
    "../../Submodules/JUCE/modules/juce_video/playback/juce_VideoComponent.h"
    "../../Submodules/JUCE/modules/juce_video/juce_video.cpp"
    "../../Submodules/JUCE/modules/juce_video/juce_video.mm"
    "../../Submodules/JUCE/modules/juce_video/juce_video.h"
    "../../JuceLibraryCode/AppConfig.h"
    "../../JuceLibraryCode/BinaryData.cpp"
    "../../JuceLibraryCode/BinaryData.h"
    "../../JuceLibraryCode/include_juce_audio_basics.mm"
    "../../JuceLibraryCode/include_juce_audio_devices.mm"
    "../../JuceLibraryCode/include_juce_audio_formats.mm"
    "../../JuceLibraryCode/include_juce_audio_plugin_client_utils.cpp"
    "../../JuceLibraryCode/include_juce_audio_plugin_client_VST_utils.mm"
    "../../JuceLibraryCode/include_juce_audio_processors.mm"
    "../../JuceLibraryCode/include_juce_audio_utils.mm"
    "../../JuceLibraryCode/include_juce_core.mm"
    "../../JuceLibraryCode/include_juce_cryptography.mm"
    "../../JuceLibraryCode/include_juce_data_structures.mm"
    "../../JuceLibraryCode/include_juce_events.mm"
    "../../JuceLibraryCode/include_juce_graphics.mm"
    "../../JuceLibraryCode/include_juce_gui_basics.mm"
    "../../JuceLibraryCode/include_juce_gui_extra.mm"
    "../../JuceLibraryCode/include_juce_opengl.mm"
    "../../JuceLibraryCode/include_juce_video.mm"
    "../../JuceLibraryCode/JuceHeader.h"
)

set_source_files_properties ("../../Assets/ic_mic_none_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_mic_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_pause_circle_outline_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_play_circle_outline_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_volume_up_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_view_headline_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_settings_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_view_module_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_folder_open_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Models/Identifier.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Models/Utilities.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Models/ValueTreeObjectList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Models/ClipModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Models/PlayerModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Views/BankView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Views/ClipView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Views/DrawingTools.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Views/LibraryView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Views/MainView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Controller/ClipViewController.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Controller/LibraryViewController.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Controller/MainViewController.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Controller/ViewController.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Engine/ADSR.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Engine/Library.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Engine/Player.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/PluginProcessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/PluginEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioSampleBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_Decibels.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LinearSmoothedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_Reverb.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_AudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_PositionableAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_SystemAudioVolume.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiInput.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Oboe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_OpenSL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_ALSA.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_Bela.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_mac_CoreAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_mac_CoreMidi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_MidiDataConcatenator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_ASIO.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_DirectSound.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_WASAPI.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitmath.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitreader.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/cpu.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/crc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/fixed.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/float.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/format.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/md5.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/memory.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/window_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/alloc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/assert.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/callback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/compat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/endswap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/export.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/Flac Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/ordinals.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/win_utf8_io.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_stereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/floor/floor_books.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/uncoupled/res_books_uncoupled.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/floor_all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_22.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_X.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/analysis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/backends.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/block.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codec_internal.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/highlevel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/info.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup_data.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mapping0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/masking.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/misc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/os.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/res0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/scales.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/sharedbook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/synthesis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisenc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisfile.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/bitwise.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/codec.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/config_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/ogg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/os_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisenc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisfile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBaseHelper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputFormatConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUSilentTimeout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUTimestampGenerator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUViewLocalizedStringKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomicStack.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAutoDisposer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugMacros.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugPrintf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAException.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAHostTimeBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAReferenceCounted.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAThreadSafeList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnitTypes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAXException.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterApp.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_CarbonVisibility.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_CheckSettingMacros.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_FakeMouseMoveGenerator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeModuleHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeSystemHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginHostType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_WindowsHooks.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VSTCallbackHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_utils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST_utils.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3Common.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3Headers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTCommon.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTMidiEventList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDBurner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_linux_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDBurner.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDReader.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_AbstractFifo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_Array.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_DynamicObject.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_DynamicObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_ElementComparator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_HashMap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_HashMap_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_LinkedListPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_ListenerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_NamedValueSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_OwnedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_PropertySet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_PropertySet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_SortedSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_SparseSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_Variant.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_Variant.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_DirectoryIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_File.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_File.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileSearchPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileSearchPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_MemoryMappedFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_TemporaryFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_TemporaryFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_WildcardFileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/javascript/juce_Javascript.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/javascript/juce_Javascript.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/javascript/juce_JSON.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/javascript/juce_JSON.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/logging/juce_FileLogger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/logging/juce_FileLogger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/logging/juce_Logger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/logging/juce_Logger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_BigInteger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_BigInteger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_Expression.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_Expression.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_MathsFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_NormalisableRange.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_Random.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_Random.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_Range.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_Atomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_ByteOrder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_HeapBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_Memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_MemoryBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_ScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_Singleton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_WeakReference.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_Result.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_Result.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_RuntimePermissions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_Uuid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_Uuid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_WindowsRegistry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_JNIHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_Misc.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_curl_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_linux_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_linux_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_linux_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_ClangBugWorkaround.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_Files.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_Network.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_Strings.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_SystemStats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_Threads.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_osx_ObjCHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_posix_SharedCode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_Registry.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_IPAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_MACAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_MACAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_NamedPipe.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_Socket.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_Socket.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_URL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_URL.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_WebInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_WebInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_BufferedInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_FileInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_FileInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_InputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_InputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_InputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_OutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_OutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_SubregionStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_SubregionStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_URLInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_URLInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_CompilerSupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_PlatformDefs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_StandardHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_SystemStats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_TargetPlatform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_Base64.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_Base64.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharacterFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_Identifier.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_Identifier.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_LocalisedStrings.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_NewLine.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_String.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_String.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringPairArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringPairArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringRef.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_TextDiff.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_TextDiff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_CriticalSection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_DynamicLibrary.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_InterProcessLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_Process.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ReadWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedReadLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_SpinLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_Thread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_Thread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_TimeSliceThread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_WaitableEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_PerformanceCounter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_RelativeTime.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_RelativeTime.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_Time.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_Time.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/unit_tests/juce_UnitTest.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/xml/juce_XmlDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/xml/juce_XmlDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/xml/juce_XmlElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/xml/juce_XmlElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/adler32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/compress.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/crc32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/crc32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/deflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/deflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/infback.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inffast.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inffast.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inffixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inftrees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inftrees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/trees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/trees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/uncompr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/zconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/zconf.in.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/zlib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/zutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/zutil.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_ZipFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_ZipFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/juce_core.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/juce_core.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/juce_core.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_Primes.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_Primes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_MD5.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_MD5.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_SHA256.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_SHA256.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_CachedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_Value.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_Value.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTree.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_ApplicationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_CallbackMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_Initialisation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_Message.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_MessageListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_MessageListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_MessageManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_MessageManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_NotificationType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_android_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_ios_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_linux_EventLoop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_linux_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_mac_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_osx_MessageQueue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_win32_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/timers/juce_MultiTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/timers/juce_MultiTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/timers/juce_Timer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/timers/juce_Timer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/juce_events.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/juce_events.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/juce_events.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colour.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colour.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_ColourGradient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colours.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_FillType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_FillType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_PixelFormats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/effects/juce_GlowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_AttributedString.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Font.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Font.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_TextLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Typeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_BorderSize.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Line.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Path.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Path.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Point.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Rectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_RectangleList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/png.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/png.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_Image.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_Image.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/placement/juce_Justification.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/juce_graphics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/juce_graphics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/juce_graphics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/application/juce_Application.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/application/juce_Application.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_Button.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Component.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Component.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Desktop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Desktop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Grid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridUnitTests.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Viewport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Clipboard.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Label.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Slider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Draggable3DOrientation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Matrix3D.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Quaternion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Vector3D.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_MissingGLDefinitions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_android.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_ios.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_linux_X11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_osx.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_win32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGLExtensions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/juce_opengl.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/juce_opengl.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/juce_opengl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/capture/juce_CameraDevice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/capture/juce_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/native/juce_android_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/native/juce_mac_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/native/juce_mac_Video.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/native/juce_win32_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/native/juce_win32_Video.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/playback/juce_VideoComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/playback/juce_VideoComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/juce_video.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/juce_video.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/juce_video.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../JuceLibraryCode/AppConfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../JuceLibraryCode/BinaryData.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../JuceLibraryCode/JuceHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)

set_target_properties (SHARED_CODE PROPERTIES SUFFIX ".a")

#------------------------------------------------------------------------------
# Config: Debug
#------------------------------------------------------------------------------

if (CMAKE_BUILD_TYPE STREQUAL Debug)

execute_process (COMMAND uname -m OUTPUT_VARIABLE JUCE_ARCH_LABEL OUTPUT_STRIP_TRAILING_WHITESPACE)

target_include_directories (STANDALONE_PLUGIN PRIVATE
    "../../JuceLibraryCode"
    "../../Submodules/JUCE/modules"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (STANDALONE_PLUGIN PRIVATE
    "_DEBUG=1"
    "DEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=4.0.0"
    "JUCE_APP_VERSION_HEX=0x40000"
    "JucePlugin_Build_VST=0"
    "JucePlugin_Build_VST3=0"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=1"
)

target_compile_options (STANDALONE_PLUGIN PRIVATE
    -mmacosx-version-min=10.11
    -O0
)

set_target_properties (STANDALONE_PLUGIN PROPERTIES
    OUTPUT_NAME "Ultraschall Soundboard"
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_COPY_PHASE_STRIP NO
    XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC NO
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_INFOPLIST_FILE "C:\src\ultraschall-soundboard\Builds\CLion\Debug-Info-Standalone_Plugin.plist"
    XCODE_ATTRIBUTE_INFOPLIST_PREPROCESS NO
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER fm.ultraschall.Soundboard
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
    MACOSX_BUNDLE_INFO_PLIST "C:\src\ultraschall-soundboard\Builds\CLion\Debug-Info-Standalone_Plugin.plist"
    XCODE_ATTRIBUTE_PRODUCT_NAME "Ultraschall Soundboard"
    MACOSX_BUNDLE TRUE
)

target_link_libraries (STANDALONE_PLUGIN PRIVATE
    SHARED_CODE
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

target_include_directories (SHARED_CODE PRIVATE
    "../../JuceLibraryCode"
    "../../Submodules/JUCE/modules"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (SHARED_CODE PRIVATE
    "_DEBUG=1"
    "DEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=4.0.0"
    "JUCE_APP_VERSION_HEX=0x40000"
    "JucePlugin_Build_VST=0"
    "JucePlugin_Build_VST3=0"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=1"
    "JUCE_SHARED_CODE=1"
)

target_compile_options (SHARED_CODE PRIVATE
    -mmacosx-version-min=10.11
    -O0
)

set_target_properties (SHARED_CODE PROPERTIES
    OUTPUT_NAME "Ultraschall Soundboard"
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_COPY_PHASE_STRIP NO
    XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC NO
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_INSTALL_PATH "@executable_path/../Frameworks"
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER fm.ultraschall.Soundboard
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
)

target_link_libraries (SHARED_CODE PRIVATE
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-common -Wswitch -Wunused-variable -Wparentheses -Wnon-virtual-dtor -Wshorten-64-to-32 -Wundeclared-selector -Wuninitialized -Wunused-function -Wbool-conversion -Wcomma -Wconstant-conversion -Wempty-body -Wenum-conversion -Winfinite-recursion -Wint-conversion -Wrange-loop-analysis -Wstrict-prototypes -Wmove -Wunreachable-code -Wduplicate-method-match -Wreorder -fvisibility-inlines-hidden")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS}")

endif (CMAKE_BUILD_TYPE STREQUAL Debug)

#------------------------------------------------------------------------------
# Config: Release
#------------------------------------------------------------------------------

if (CMAKE_BUILD_TYPE STREQUAL Release)

execute_process (COMMAND uname -m OUTPUT_VARIABLE JUCE_ARCH_LABEL OUTPUT_STRIP_TRAILING_WHITESPACE)

target_include_directories (STANDALONE_PLUGIN PRIVATE
    "../../JuceLibraryCode"
    "../../Submodules/JUCE/modules"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (STANDALONE_PLUGIN PRIVATE
    "_NDEBUG=1"
    "NDEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=4.0.0"
    "JUCE_APP_VERSION_HEX=0x40000"
    "JucePlugin_Build_VST=0"
    "JucePlugin_Build_VST3=0"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=1"
)

target_compile_options (STANDALONE_PLUGIN PRIVATE
    -mmacosx-version-min=10.11
    -O3
    -flto
)

set_target_properties (STANDALONE_PLUGIN PROPERTIES
    OUTPUT_NAME "Ultraschall Soundboard"
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_DEAD_CODE_STRIPPING YES
    XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS NO
    XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN YES
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_INFOPLIST_FILE "C:\src\ultraschall-soundboard\Builds\CLion\Release-Info-Standalone_Plugin.plist"
    XCODE_ATTRIBUTE_INFOPLIST_PREPROCESS NO
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER fm.ultraschall.Soundboard
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
    MACOSX_BUNDLE_INFO_PLIST "C:\src\ultraschall-soundboard\Builds\CLion\Release-Info-Standalone_Plugin.plist"
    XCODE_ATTRIBUTE_PRODUCT_NAME "Ultraschall Soundboard"
    MACOSX_BUNDLE TRUE
)

target_link_libraries (STANDALONE_PLUGIN PRIVATE
    SHARED_CODE
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

target_include_directories (SHARED_CODE PRIVATE
    "../../JuceLibraryCode"
    "../../Submodules/JUCE/modules"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (SHARED_CODE PRIVATE
    "_NDEBUG=1"
    "NDEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=4.0.0"
    "JUCE_APP_VERSION_HEX=0x40000"
    "JucePlugin_Build_VST=0"
    "JucePlugin_Build_VST3=0"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=1"
    "JUCE_SHARED_CODE=1"
)

target_compile_options (SHARED_CODE PRIVATE
    -mmacosx-version-min=10.11
    -O3
    -flto
)

set_target_properties (SHARED_CODE PROPERTIES
    OUTPUT_NAME "Ultraschall Soundboard"
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_DEAD_CODE_STRIPPING YES
    XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS NO
    XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN YES
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_INSTALL_PATH "@executable_path/../Frameworks"
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER fm.ultraschall.Soundboard
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
)

target_link_libraries (SHARED_CODE PRIVATE
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-common -Wswitch -Wunused-variable -Wparentheses -Wnon-virtual-dtor -Wshorten-64-to-32 -Wundeclared-selector -Wuninitialized -Wunused-function -Wbool-conversion -Wcomma -Wconstant-conversion -Wempty-body -Wenum-conversion -Winfinite-recursion -Wint-conversion -Wrange-loop-analysis -Wstrict-prototypes -Wmove -Wunreachable-code -Wduplicate-method-match -Wreorder -fvisibility-inlines-hidden")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS}")

endif (CMAKE_BUILD_TYPE STREQUAL Release)

endif()

###############################################################################
# Linux Makefile
###############################################################################

if (UNIX AND NOT APPLE)

project ("Ultraschall Soundboard" C CXX)

find_package (PkgConfig REQUIRED)
pkg_search_module (ALSA REQUIRED alsa)
pkg_search_module (FREETYPE2 REQUIRED freetype2)
pkg_search_module (LIBCURL REQUIRED libcurl)
pkg_search_module (X11 REQUIRED x11)
pkg_search_module (XEXT REQUIRED xext)
pkg_search_module (XINERAMA REQUIRED xinerama)
pkg_search_module (WEBKIT2GTK-4.0 REQUIRED webkit2gtk-4.0)
pkg_search_module (GTK+-X11-3.0 REQUIRED gtk+-x11-3.0)

add_executable (STANDALONE_PLUGIN
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_Standalone.cpp"
    "../../JuceLibraryCode/include_juce_audio_plugin_client_Standalone.cpp"
)

set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_Standalone.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)

add_library (SHARED_CODE STATIC
    "../../Assets/ic_mic_none_white_48px.svg"
    "../../Assets/ic_mic_white_48px.svg"
    "../../Assets/ic_pause_circle_outline_white_48px.svg"
    "../../Assets/ic_play_circle_outline_white_48px.svg"
    "../../Assets/ic_volume_up_white_48px.svg"
    "../../Assets/ic_view_headline_white_48px.svg"
    "../../Assets/ic_settings_white_48px.svg"
    "../../Assets/ic_view_module_white_48px.svg"
    "../../Assets/ic_folder_open_white_48px.svg"
    "../../Source/Models/Identifier.h"
    "../../Source/Models/Utilities.h"
    "../../Source/Models/ValueTreeObjectList.h"
    "../../Source/Models/ClipModel.h"
    "../../Source/Models/PlayerModel.h"
    "../../Source/Views/BankView.cpp"
    "../../Source/Views/BankView.h"
    "../../Source/Views/ClipView.cpp"
    "../../Source/Views/ClipView.h"
    "../../Source/Views/DrawingTools.cpp"
    "../../Source/Views/DrawingTools.h"
    "../../Source/Views/LibraryView.cpp"
    "../../Source/Views/LibraryView.h"
    "../../Source/Views/MainView.cpp"
    "../../Source/Views/MainView.h"
    "../../Source/Controller/ClipViewController.cpp"
    "../../Source/Controller/ClipViewController.h"
    "../../Source/Controller/LibraryViewController.cpp"
    "../../Source/Controller/LibraryViewController.h"
    "../../Source/Controller/MainViewController.cpp"
    "../../Source/Controller/MainViewController.h"
    "../../Source/Controller/ViewController.h"
    "../../Source/Engine/ADSR.cpp"
    "../../Source/Engine/ADSR.h"
    "../../Source/Engine/Library.cpp"
    "../../Source/Engine/Library.h"
    "../../Source/Engine/Player.cpp"
    "../../Source/Engine/Player.h"
    "../../Source/PluginProcessor.cpp"
    "../../Source/PluginProcessor.h"
    "../../Source/PluginEditor.cpp"
    "../../Source/PluginEditor.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioSampleBuffer.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_Decibels.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LinearSmoothedValue.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_Reverb.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_AudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_PositionableAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.h"
    "../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp"
    "../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.mm"
    "../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_SystemAudioVolume.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiInput.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Audio.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Midi.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Oboe.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_OpenSL.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_ALSA.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_Bela.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_Midi.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_mac_CoreAudio.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_mac_CoreMidi.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_MidiDataConcatenator.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_ASIO.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_DirectSound.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_Midi.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_WASAPI.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.h"
    "../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp"
    "../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.mm"
    "../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitmath.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitreader.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/cpu.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/crc.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/fixed.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/float.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/format.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/md5.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/memory.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/window_flac.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/all.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/alloc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/assert.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/callback.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/compat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/endswap.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/export.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/Flac Licence.txt"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/format.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/metadata.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/ordinals.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/stream_decoder.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/stream_encoder.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/win_utf8_io.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_51.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_stereo.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/floor/floor_books.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/uncoupled/res_books_uncoupled.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/floor_all.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_8.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_11.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_16.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_44.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_8.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_16.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44p51.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44u.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_8.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_11.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_16.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_22.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_32.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44p51.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44u.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_X.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/analysis.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/backends.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/block.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codec_internal.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor0.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor1.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/highlevel.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/info.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup_data.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mapping0.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/masking.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/misc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/os.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/res0.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/scales.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/sharedbook.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/synthesis.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisenc.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisfile.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/bitwise.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/codec.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/config_types.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/framing.c"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/ogg.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/os_types.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisenc.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisfile.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.h"
    "../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp"
    "../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.mm"
    "../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBaseHelper.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewDispatch.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputFormatConverter.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUSilentTimeout.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUTimestampGenerator.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUViewLocalizedStringKeys.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomic.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomicStack.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAutoDisposer.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugMacros.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugPrintf.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAException.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAHostTimeBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMath.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAReferenceCounted.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAThreadSafeList.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnitTypes.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAXException.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterApp.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_CarbonVisibility.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_CheckSettingMacros.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_FakeMouseMoveGenerator.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeModuleHeaders.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeSystemHeaders.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginHostType.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_WindowsHooks.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.mm"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VSTCallbackHandler.h"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_utils.cpp"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST_utils.mm"
    "../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3Common.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3Headers.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTCommon.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTInterface.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTMidiEventList.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorListener.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameter.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameters.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h"
    "../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp"
    "../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.mm"
    "../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDBurner.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailBase.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_linux_AudioCDReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDBurner.mm"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDReader.mm"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDReader.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.h"
    "../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp"
    "../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.mm"
    "../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_AbstractFifo.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_Array.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_DynamicObject.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_DynamicObject.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_ElementComparator.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_HashMap.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_HashMap_test.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_LinkedListPointer.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_ListenerList.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_NamedValueSet.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_OwnedArray.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_PropertySet.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_PropertySet.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_SortedSet.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_SparseSet.h"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_Variant.cpp"
    "../../Submodules/JUCE/modules/juce_core/containers/juce_Variant.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_DirectoryIterator.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_File.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_File.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileFilter.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileFilter.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileInputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileInputStream.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileOutputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileOutputStream.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileSearchPath.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_FileSearchPath.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_MemoryMappedFile.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_TemporaryFile.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_TemporaryFile.h"
    "../../Submodules/JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp"
    "../../Submodules/JUCE/modules/juce_core/files/juce_WildcardFileFilter.h"
    "../../Submodules/JUCE/modules/juce_core/javascript/juce_Javascript.cpp"
    "../../Submodules/JUCE/modules/juce_core/javascript/juce_Javascript.h"
    "../../Submodules/JUCE/modules/juce_core/javascript/juce_JSON.cpp"
    "../../Submodules/JUCE/modules/juce_core/javascript/juce_JSON.h"
    "../../Submodules/JUCE/modules/juce_core/logging/juce_FileLogger.cpp"
    "../../Submodules/JUCE/modules/juce_core/logging/juce_FileLogger.h"
    "../../Submodules/JUCE/modules/juce_core/logging/juce_Logger.cpp"
    "../../Submodules/JUCE/modules/juce_core/logging/juce_Logger.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_BigInteger.cpp"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_BigInteger.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_Expression.cpp"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_Expression.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_MathsFunctions.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_NormalisableRange.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_Random.cpp"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_Random.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_Range.h"
    "../../Submodules/JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_Atomic.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_ByteOrder.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_HeapBlock.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_Memory.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_MemoryBlock.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_ScopedPointer.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_Singleton.h"
    "../../Submodules/JUCE/modules/juce_core/memory/juce_WeakReference.h"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_Result.cpp"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_Result.h"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_RuntimePermissions.h"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.cpp"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.h"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_Uuid.cpp"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_Uuid.h"
    "../../Submodules/JUCE/modules/juce_core/misc/juce_WindowsRegistry.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_Files.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_JNIHelpers.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_Misc.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_Network.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_SystemStats.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_android_Threads.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_curl_Network.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_linux_Files.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_linux_Network.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_linux_Threads.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_ClangBugWorkaround.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_Files.mm"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_Network.mm"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_Strings.mm"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_SystemStats.mm"
    "../../Submodules/JUCE/modules/juce_core/native/juce_mac_Threads.mm"
    "../../Submodules/JUCE/modules/juce_core/native/juce_osx_ObjCHelpers.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_posix_SharedCode.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_Files.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_Network.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_Registry.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp"
    "../../Submodules/JUCE/modules/juce_core/native/juce_win32_Threads.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_IPAddress.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_IPAddress.h"
    "../../Submodules/JUCE/modules/juce_core/network/juce_MACAddress.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_MACAddress.h"
    "../../Submodules/JUCE/modules/juce_core/network/juce_NamedPipe.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_NamedPipe.h"
    "../../Submodules/JUCE/modules/juce_core/network/juce_Socket.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_Socket.h"
    "../../Submodules/JUCE/modules/juce_core/network/juce_URL.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_URL.h"
    "../../Submodules/JUCE/modules/juce_core/network/juce_WebInputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/network/juce_WebInputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_BufferedInputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_FileInputSource.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_FileInputSource.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_InputSource.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_InputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_InputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryInputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_OutputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_OutputStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_SubregionStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_SubregionStream.h"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_URLInputSource.cpp"
    "../../Submodules/JUCE/modules/juce_core/streams/juce_URLInputSource.h"
    "../../Submodules/JUCE/modules/juce_core/system/juce_CompilerSupport.h"
    "../../Submodules/JUCE/modules/juce_core/system/juce_PlatformDefs.h"
    "../../Submodules/JUCE/modules/juce_core/system/juce_StandardHeader.h"
    "../../Submodules/JUCE/modules/juce_core/system/juce_SystemStats.cpp"
    "../../Submodules/JUCE/modules/juce_core/system/juce_SystemStats.h"
    "../../Submodules/JUCE/modules/juce_core/system/juce_TargetPlatform.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_Base64.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_Base64.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharacterFunctions.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_Identifier.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_Identifier.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_LocalisedStrings.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_NewLine.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_String.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_String.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringArray.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringArray.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringPairArray.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringPairArray.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringPool.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringPool.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_StringRef.h"
    "../../Submodules/JUCE/modules/juce_core/text/juce_TextDiff.cpp"
    "../../Submodules/JUCE/modules/juce_core/text/juce_TextDiff.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ChildProcess.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ChildProcess.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_CriticalSection.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_DynamicLibrary.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_InterProcessLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_Process.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ReadWriteLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedReadLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_SpinLock.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_Thread.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_Thread.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadPool.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadPool.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_TimeSliceThread.h"
    "../../Submodules/JUCE/modules/juce_core/threads/juce_WaitableEvent.h"
    "../../Submodules/JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp"
    "../../Submodules/JUCE/modules/juce_core/time/juce_PerformanceCounter.h"
    "../../Submodules/JUCE/modules/juce_core/time/juce_RelativeTime.cpp"
    "../../Submodules/JUCE/modules/juce_core/time/juce_RelativeTime.h"
    "../../Submodules/JUCE/modules/juce_core/time/juce_Time.cpp"
    "../../Submodules/JUCE/modules/juce_core/time/juce_Time.h"
    "../../Submodules/JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp"
    "../../Submodules/JUCE/modules/juce_core/unit_tests/juce_UnitTest.h"
    "../../Submodules/JUCE/modules/juce_core/xml/juce_XmlDocument.cpp"
    "../../Submodules/JUCE/modules/juce_core/xml/juce_XmlDocument.h"
    "../../Submodules/JUCE/modules/juce_core/xml/juce_XmlElement.cpp"
    "../../Submodules/JUCE/modules/juce_core/xml/juce_XmlElement.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/adler32.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/compress.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/crc32.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/crc32.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/deflate.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/deflate.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/infback.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inffast.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inffast.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inffixed.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inflate.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inflate.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inftrees.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/inftrees.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/trees.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/trees.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/uncompr.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/zconf.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/zconf.in.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/zlib.h"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/zutil.c"
    "../../Submodules/JUCE/modules/juce_core/zip/zlib/zutil.h"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_ZipFile.cpp"
    "../../Submodules/JUCE/modules/juce_core/zip/juce_ZipFile.h"
    "../../Submodules/JUCE/modules/juce_core/juce_core.cpp"
    "../../Submodules/JUCE/modules/juce_core/juce_core.mm"
    "../../Submodules/JUCE/modules/juce_core/juce_core.h"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.h"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_Primes.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_Primes.h"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.h"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_MD5.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_MD5.h"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_SHA256.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_SHA256.h"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.h"
    "../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.cpp"
    "../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.mm"
    "../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.h"
    "../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h"
    "../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h"
    "../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h"
    "../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_CachedValue.h"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_Value.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_Value.h"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTree.h"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h"
    "../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h"
    "../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.cpp"
    "../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.mm"
    "../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.h"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionListener.h"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h"
    "../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp"
    "../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_ApplicationBase.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_CallbackMessage.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_Initialisation.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_Message.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_MessageListener.cpp"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_MessageListener.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_MessageManager.cpp"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_MessageManager.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h"
    "../../Submodules/JUCE/modules/juce_events/messages/juce_NotificationType.h"
    "../../Submodules/JUCE/modules/juce_events/native/juce_android_Messaging.cpp"
    "../../Submodules/JUCE/modules/juce_events/native/juce_ios_MessageManager.mm"
    "../../Submodules/JUCE/modules/juce_events/native/juce_linux_EventLoop.h"
    "../../Submodules/JUCE/modules/juce_events/native/juce_linux_Messaging.cpp"
    "../../Submodules/JUCE/modules/juce_events/native/juce_mac_MessageManager.mm"
    "../../Submodules/JUCE/modules/juce_events/native/juce_osx_MessageQueue.h"
    "../../Submodules/JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h"
    "../../Submodules/JUCE/modules/juce_events/native/juce_win32_Messaging.cpp"
    "../../Submodules/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp"
    "../../Submodules/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h"
    "../../Submodules/JUCE/modules/juce_events/timers/juce_MultiTimer.cpp"
    "../../Submodules/JUCE/modules/juce_events/timers/juce_MultiTimer.h"
    "../../Submodules/JUCE/modules/juce_events/timers/juce_Timer.cpp"
    "../../Submodules/JUCE/modules/juce_events/timers/juce_Timer.h"
    "../../Submodules/JUCE/modules/juce_events/juce_events.cpp"
    "../../Submodules/JUCE/modules/juce_events/juce_events.mm"
    "../../Submodules/JUCE/modules/juce_events/juce_events.h"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colour.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colour.h"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_ColourGradient.h"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colours.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colours.h"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_FillType.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_FillType.h"
    "../../Submodules/JUCE/modules/juce_graphics/colour/juce_PixelFormats.h"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h"
    "../../Submodules/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h"
    "../../Submodules/JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/effects/juce_GlowEffect.h"
    "../../Submodules/JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_AttributedString.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Font.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Font.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_TextLayout.h"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Typeface.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_BorderSize.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Line.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Path.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Path.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathIterator.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Point.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Rectangle.h"
    "../../Submodules/JUCE/modules/juce_graphics/geometry/juce_RectangleList.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/png.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/png.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_Image.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_Image.h"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageCache.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageCache.h"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/placement/juce_Justification.h"
    "../../Submodules/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h"
    "../../Submodules/JUCE/modules/juce_graphics/juce_graphics.cpp"
    "../../Submodules/JUCE/modules/juce_graphics/juce_graphics.mm"
    "../../Submodules/JUCE/modules/juce_graphics/juce_graphics.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/application/juce_Application.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/application/juce_Application.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_Button.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Component.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Component.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Desktop.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Desktop.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Grid.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridItem.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridUnitTests.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Viewport.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Clipboard.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Windowing.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Label.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Slider.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h"
    "../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp"
    "../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.mm"
    "../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp"
    "../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.mm"
    "../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.h"
    "../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Draggable3DOrientation.h"
    "../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Matrix3D.h"
    "../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Quaternion.h"
    "../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Vector3D.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_MissingGLDefinitions.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_android.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_ios.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_linux_X11.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_osx.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_win32.h"
    "../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGLExtensions.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLRenderer.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.h"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.h"
    "../../Submodules/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.h"
    "../../Submodules/JUCE/modules/juce_opengl/juce_opengl.cpp"
    "../../Submodules/JUCE/modules/juce_opengl/juce_opengl.mm"
    "../../Submodules/JUCE/modules/juce_opengl/juce_opengl.h"
    "../../Submodules/JUCE/modules/juce_video/capture/juce_CameraDevice.cpp"
    "../../Submodules/JUCE/modules/juce_video/capture/juce_CameraDevice.h"
    "../../Submodules/JUCE/modules/juce_video/native/juce_android_CameraDevice.h"
    "../../Submodules/JUCE/modules/juce_video/native/juce_mac_CameraDevice.h"
    "../../Submodules/JUCE/modules/juce_video/native/juce_mac_Video.h"
    "../../Submodules/JUCE/modules/juce_video/native/juce_win32_CameraDevice.h"
    "../../Submodules/JUCE/modules/juce_video/native/juce_win32_Video.h"
    "../../Submodules/JUCE/modules/juce_video/playback/juce_VideoComponent.cpp"
    "../../Submodules/JUCE/modules/juce_video/playback/juce_VideoComponent.h"
    "../../Submodules/JUCE/modules/juce_video/juce_video.cpp"
    "../../Submodules/JUCE/modules/juce_video/juce_video.mm"
    "../../Submodules/JUCE/modules/juce_video/juce_video.h"
    "../../JuceLibraryCode/AppConfig.h"
    "../../JuceLibraryCode/BinaryData.cpp"
    "../../JuceLibraryCode/BinaryData.h"
    "../../JuceLibraryCode/include_juce_audio_basics.cpp"
    "../../JuceLibraryCode/include_juce_audio_devices.cpp"
    "../../JuceLibraryCode/include_juce_audio_formats.cpp"
    "../../JuceLibraryCode/include_juce_audio_plugin_client_utils.cpp"
    "../../JuceLibraryCode/include_juce_audio_processors.cpp"
    "../../JuceLibraryCode/include_juce_audio_utils.cpp"
    "../../JuceLibraryCode/include_juce_core.cpp"
    "../../JuceLibraryCode/include_juce_cryptography.cpp"
    "../../JuceLibraryCode/include_juce_data_structures.cpp"
    "../../JuceLibraryCode/include_juce_events.cpp"
    "../../JuceLibraryCode/include_juce_graphics.cpp"
    "../../JuceLibraryCode/include_juce_gui_basics.cpp"
    "../../JuceLibraryCode/include_juce_gui_extra.cpp"
    "../../JuceLibraryCode/include_juce_opengl.cpp"
    "../../JuceLibraryCode/include_juce_video.cpp"
    "../../JuceLibraryCode/JuceHeader.h"
)

set_source_files_properties ("../../Assets/ic_mic_none_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_mic_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_pause_circle_outline_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_play_circle_outline_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_volume_up_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_view_headline_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_settings_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_view_module_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Assets/ic_folder_open_white_48px.svg" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Models/Identifier.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Models/Utilities.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Models/ValueTreeObjectList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Models/ClipModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Models/PlayerModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Views/BankView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Views/ClipView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Views/DrawingTools.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Views/LibraryView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Views/MainView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Controller/ClipViewController.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Controller/LibraryViewController.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Controller/MainViewController.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Controller/ViewController.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Engine/ADSR.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Engine/Library.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Engine/Player.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/PluginProcessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/PluginEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_AudioSampleBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_Decibels.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_LinearSmoothedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/effects/juce_Reverb.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_AudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_PositionableAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/audio_io/juce_SystemAudioVolume.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiInput.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_Oboe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_android_OpenSL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_ALSA.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_Bela.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_linux_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_mac_CoreAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_mac_CoreMidi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_MidiDataConcatenator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_ASIO.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_DirectSound.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/native/juce_win32_WASAPI.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitmath.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitreader.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/cpu.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/crc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/fixed.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/float.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/format.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/md5.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/memory.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/window_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/alloc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/assert.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/callback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/compat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/endswap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/export.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/Flac Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/ordinals.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/flac/win_utf8_io.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_stereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/floor/floor_books.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/uncoupled/res_books_uncoupled.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/floor_all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_22.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_X.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/analysis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/backends.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/block.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codec_internal.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/highlevel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/info.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup_data.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mapping0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/masking.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/misc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/os.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/res0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/scales.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/sharedbook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/synthesis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisenc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisfile.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/bitwise.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/codec.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/config_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/ogg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/os_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisenc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisfile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBaseHelper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputFormatConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUSilentTimeout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUTimestampGenerator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUViewLocalizedStringKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomicStack.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAutoDisposer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugMacros.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugPrintf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAException.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAHostTimeBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAReferenceCounted.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAThreadSafeList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnitTypes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAXException.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterApp.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_CarbonVisibility.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_CheckSettingMacros.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_FakeMouseMoveGenerator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeModuleHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeSystemHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginHostType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_WindowsHooks.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VSTCallbackHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_utils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST_utils.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3Common.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3Headers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTCommon.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTMidiEventList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDBurner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_linux_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDBurner.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDReader.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_AbstractFifo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_Array.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_DynamicObject.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_DynamicObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_ElementComparator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_HashMap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_HashMap_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_LinkedListPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_ListenerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_NamedValueSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_OwnedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_PropertySet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_PropertySet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_SortedSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_SparseSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_Variant.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/containers/juce_Variant.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_DirectoryIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_File.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_File.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileSearchPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_FileSearchPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_MemoryMappedFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_TemporaryFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_TemporaryFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/files/juce_WildcardFileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/javascript/juce_Javascript.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/javascript/juce_Javascript.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/javascript/juce_JSON.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/javascript/juce_JSON.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/logging/juce_FileLogger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/logging/juce_FileLogger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/logging/juce_Logger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/logging/juce_Logger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_BigInteger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_BigInteger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_Expression.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_Expression.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_MathsFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_NormalisableRange.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_Random.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_Random.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_Range.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_Atomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_ByteOrder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_HeapBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_Memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_MemoryBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_ScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_Singleton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/memory/juce_WeakReference.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_Result.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_Result.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_RuntimePermissions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_Uuid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_Uuid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/misc/juce_WindowsRegistry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_JNIHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_Misc.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_android_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_curl_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_linux_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_linux_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_linux_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_ClangBugWorkaround.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_Files.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_Network.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_Strings.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_SystemStats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_mac_Threads.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_osx_ObjCHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_posix_SharedCode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_Registry.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/native/juce_win32_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_IPAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_MACAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_MACAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_NamedPipe.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_Socket.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_Socket.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_URL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_URL.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_WebInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/network/juce_WebInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_BufferedInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_FileInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_FileInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_InputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_InputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_InputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_OutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_OutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_SubregionStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_SubregionStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_URLInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/streams/juce_URLInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_CompilerSupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_PlatformDefs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_StandardHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_SystemStats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/system/juce_TargetPlatform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_Base64.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_Base64.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharacterFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_Identifier.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_Identifier.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_LocalisedStrings.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_NewLine.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_String.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_String.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringPairArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringPairArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_StringRef.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_TextDiff.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/text/juce_TextDiff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_CriticalSection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_DynamicLibrary.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_InterProcessLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_Process.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ReadWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedReadLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_SpinLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_Thread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_Thread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_ThreadPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_TimeSliceThread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/threads/juce_WaitableEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_PerformanceCounter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_RelativeTime.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_RelativeTime.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_Time.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/time/juce_Time.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/unit_tests/juce_UnitTest.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/xml/juce_XmlDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/xml/juce_XmlDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/xml/juce_XmlElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/xml/juce_XmlElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/adler32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/compress.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/crc32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/crc32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/deflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/deflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/infback.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inffast.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inffast.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inffixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inftrees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/inftrees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/trees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/trees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/uncompr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/zconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/zconf.in.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/zlib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/zutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/zlib/zutil.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_ZipFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/zip/juce_ZipFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/juce_core.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/juce_core.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_core/juce_core.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_Primes.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_Primes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_MD5.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_MD5.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_SHA256.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_SHA256.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_cryptography/juce_cryptography.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_CachedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_Value.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_Value.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTree.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ActionListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_ApplicationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_CallbackMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_Initialisation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_Message.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_MessageListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_MessageListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_MessageManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_MessageManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/messages/juce_NotificationType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_android_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_ios_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_linux_EventLoop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_linux_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_mac_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_osx_MessageQueue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_win32_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/timers/juce_MultiTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/timers/juce_MultiTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/timers/juce_Timer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/timers/juce_Timer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/juce_events.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/juce_events.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_events/juce_events.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colour.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colour.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_ColourGradient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colours.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_Colours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_FillType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_FillType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/colour/juce_PixelFormats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/effects/juce_GlowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_AttributedString.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Font.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Font.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_TextLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/fonts/juce_Typeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_BorderSize.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Line.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Path.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Path.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Point.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_Rectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/geometry/juce_RectangleList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/png.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/png.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_Image.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_Image.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/placement/juce_Justification.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/juce_graphics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/juce_graphics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_graphics/juce_graphics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/application/juce_Application.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/application/juce_Application.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_Button.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Component.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Component.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Desktop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_Desktop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Grid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GridUnitTests.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/layout/juce_Viewport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Clipboard.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Label.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Slider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Draggable3DOrientation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Matrix3D.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Quaternion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/geometry/juce_Vector3D.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_MissingGLDefinitions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_android.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_ios.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_linux_X11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_osx.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGL_win32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/native/juce_OpenGLExtensions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/juce_opengl.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/juce_opengl.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_opengl/juce_opengl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/capture/juce_CameraDevice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/capture/juce_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/native/juce_android_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/native/juce_mac_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/native/juce_mac_Video.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/native/juce_win32_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/native/juce_win32_Video.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/playback/juce_VideoComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/playback/juce_VideoComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/juce_video.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/juce_video.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Submodules/JUCE/modules/juce_video/juce_video.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../JuceLibraryCode/AppConfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../JuceLibraryCode/BinaryData.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../JuceLibraryCode/JuceHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)

set_target_properties (STANDALONE_PLUGIN PROPERTIES SUFFIX "")

set_target_properties (SHARED_CODE PROPERTIES SUFFIX ".a")

#------------------------------------------------------------------------------
# Config: Debug
#------------------------------------------------------------------------------

if (CMAKE_BUILD_TYPE STREQUAL Debug)

execute_process (COMMAND uname -m OUTPUT_VARIABLE JUCE_ARCH_LABEL OUTPUT_STRIP_TRAILING_WHITESPACE)

include_directories (
    "../../JuceLibraryCode"
    "../../Submodules/JUCE/modules"
    ${ALSA_INCLUDE_DIRS}
    ${FREETYPE2_INCLUDE_DIRS}
    ${LIBCURL_INCLUDE_DIRS}
    ${X11_INCLUDE_DIRS}
    ${XEXT_INCLUDE_DIRS}
    ${XINERAMA_INCLUDE_DIRS}
    ${WEBKIT2GTK-4.0_INCLUDE_DIRS}
    ${GTK+-X11-3.0_INCLUDE_DIRS}
)

find_library (GL GL
)

find_library (DL dl
)

find_library (PTHREAD pthread
)

find_library (RT rt
)

set_target_properties (STANDALONE_PLUGIN PROPERTIES
    OUTPUT_NAME "Ultraschall Soundboard"
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)

target_compile_definitions (STANDALONE_PLUGIN PRIVATE
    LINUX=1
    DEBUG=1
    _DEBUG=1
    JUCER_LINUX_MAKE_6D53C8B4=1
    JUCE_APP_VERSION=4.0.0
    JUCE_APP_VERSION_HEX=0x40000
    JucePlugin_Build_VST=0
    JucePlugin_Build_VST3=0
    JucePlugin_Build_AU=0
    JucePlugin_Build_AUv3=0
    JucePlugin_Build_RTAS=0
    JucePlugin_Build_AAX=0
    JucePlugin_Build_Standalone=1
)

target_link_libraries (STANDALONE_PLUGIN PRIVATE
    SHARED_CODE
    -march=native
    ${GL}
    ${DL}
    ${PTHREAD}
    ${RT}
    ${ALSA_LIBRARIES}
    ${FREETYPE2_LIBRARIES}
    ${LIBCURL_LIBRARIES}
    ${X11_LIBRARIES}
    ${XEXT_LIBRARIES}
    ${XINERAMA_LIBRARIES}
    ${WEBKIT2GTK-4.0_LIBRARIES}
    ${GTK+-X11-3.0_LIBRARIES}
)

add_dependencies (STANDALONE_PLUGIN SHARED_CODE)

set_target_properties (SHARED_CODE PROPERTIES
    OUTPUT_NAME "Ultraschall Soundboard"
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)

target_compile_definitions (SHARED_CODE PRIVATE
    LINUX=1
    DEBUG=1
    _DEBUG=1
    JUCER_LINUX_MAKE_6D53C8B4=1
    JUCE_APP_VERSION=4.0.0
    JUCE_APP_VERSION_HEX=0x40000
    JucePlugin_Build_VST=0
    JucePlugin_Build_VST3=0
    JucePlugin_Build_AU=0
    JucePlugin_Build_AUv3=0
    JucePlugin_Build_RTAS=0
    JucePlugin_Build_AAX=0
    JucePlugin_Build_Standalone=1
    JUCE_SHARED_CODE=1
)

target_link_libraries (SHARED_CODE PRIVATE
    -march=native
    ${GL}
    ${DL}
    ${PTHREAD}
    ${RT}
    ${ALSA_LIBRARIES}
    ${FREETYPE2_LIBRARIES}
    ${LIBCURL_LIBRARIES}
    ${X11_LIBRARIES}
    ${XEXT_LIBRARIES}
    ${XINERAMA_LIBRARIES}
    ${WEBKIT2GTK-4.0_LIBRARIES}
    ${GTK+-X11-3.0_LIBRARIES}
)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native -pthread -g -ggdb -O0")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS} ")

endif (CMAKE_BUILD_TYPE STREQUAL Debug)

#------------------------------------------------------------------------------
# Config: Release
#------------------------------------------------------------------------------

if (CMAKE_BUILD_TYPE STREQUAL Release)

execute_process (COMMAND uname -m OUTPUT_VARIABLE JUCE_ARCH_LABEL OUTPUT_STRIP_TRAILING_WHITESPACE)

include_directories (
    "../../JuceLibraryCode"
    "../../Submodules/JUCE/modules"
    ${ALSA_INCLUDE_DIRS}
    ${FREETYPE2_INCLUDE_DIRS}
    ${LIBCURL_INCLUDE_DIRS}
    ${X11_INCLUDE_DIRS}
    ${XEXT_INCLUDE_DIRS}
    ${XINERAMA_INCLUDE_DIRS}
    ${WEBKIT2GTK-4.0_INCLUDE_DIRS}
    ${GTK+-X11-3.0_INCLUDE_DIRS}
)

find_library (GL GL
)

find_library (DL dl
)

find_library (PTHREAD pthread
)

find_library (RT rt
)

set_target_properties (STANDALONE_PLUGIN PROPERTIES
    OUTPUT_NAME "Ultraschall Soundboard"
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)

target_compile_definitions (STANDALONE_PLUGIN PRIVATE
    LINUX=1
    NDEBUG=1
    JUCER_LINUX_MAKE_6D53C8B4=1
    JUCE_APP_VERSION=4.0.0
    JUCE_APP_VERSION_HEX=0x40000
    JucePlugin_Build_VST=0
    JucePlugin_Build_VST3=0
    JucePlugin_Build_AU=0
    JucePlugin_Build_AUv3=0
    JucePlugin_Build_RTAS=0
    JucePlugin_Build_AAX=0
    JucePlugin_Build_Standalone=1
)

target_link_libraries (STANDALONE_PLUGIN PRIVATE
    SHARED_CODE
    -march=native
    -fvisibility=hidden
    ${GL}
    ${DL}
    ${PTHREAD}
    ${RT}
    ${ALSA_LIBRARIES}
    ${FREETYPE2_LIBRARIES}
    ${LIBCURL_LIBRARIES}
    ${X11_LIBRARIES}
    ${XEXT_LIBRARIES}
    ${XINERAMA_LIBRARIES}
    ${WEBKIT2GTK-4.0_LIBRARIES}
    ${GTK+-X11-3.0_LIBRARIES}
)

add_dependencies (STANDALONE_PLUGIN SHARED_CODE)

set_target_properties (SHARED_CODE PROPERTIES
    OUTPUT_NAME "Ultraschall Soundboard"
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)

target_compile_definitions (SHARED_CODE PRIVATE
    LINUX=1
    NDEBUG=1
    JUCER_LINUX_MAKE_6D53C8B4=1
    JUCE_APP_VERSION=4.0.0
    JUCE_APP_VERSION_HEX=0x40000
    JucePlugin_Build_VST=0
    JucePlugin_Build_VST3=0
    JucePlugin_Build_AU=0
    JucePlugin_Build_AUv3=0
    JucePlugin_Build_RTAS=0
    JucePlugin_Build_AAX=0
    JucePlugin_Build_Standalone=1
    JUCE_SHARED_CODE=1
)

target_link_libraries (SHARED_CODE PRIVATE
    -march=native
    -fvisibility=hidden
    ${GL}
    ${DL}
    ${PTHREAD}
    ${RT}
    ${ALSA_LIBRARIES}
    ${FREETYPE2_LIBRARIES}
    ${LIBCURL_LIBRARIES}
    ${X11_LIBRARIES}
    ${XEXT_LIBRARIES}
    ${XINERAMA_LIBRARIES}
    ${WEBKIT2GTK-4.0_LIBRARIES}
    ${GTK+-X11-3.0_LIBRARIES}
)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native -pthread -O3")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS} ")

endif (CMAKE_BUILD_TYPE STREQUAL Release)

endif()

