# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Debug
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.2" -D "JUCE_APP_VERSION_HEX=0x10200" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/VST3_SDK -I ../../JuceLibraryCode -I ../../Submodules/danlin_modules/modules -I ../../Submodules/JUCE/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -fPIC -O0
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -shared -L/usr/X11R6/lib/ -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.2" -D "JUCE_APP_VERSION_HEX=0x10200" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/VST3_SDK -I ../../JuceLibraryCode -I ../../Submodules/danlin_modules/modules -I ../../Submodules/JUCE/modules
  TARGET := Soundboard.so
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.2" -D "JUCE_APP_VERSION_HEX=0x10200" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/VST3_SDK -I ../../JuceLibraryCode -I ../../Submodules/danlin_modules/modules -I ../../Submodules/JUCE/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -fPIC -Os
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -shared -fvisibility=hidden -L/usr/X11R6/lib/ -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.2" -D "JUCE_APP_VERSION_HEX=0x10200" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/VST3_SDK -I ../../JuceLibraryCode -I ../../Submodules/danlin_modules/modules -I ../../Submodules/JUCE/modules
  TARGET := Soundboard.so
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

OBJECTS := \
  $(OBJDIR)/Player_a64961ea.o \
  $(OBJDIR)/PluginProcessor_a059e380.o \
  $(OBJDIR)/PluginEditor_94d4fb09.o \
  $(OBJDIR)/LookAndFeel_40552bdf.o \
  $(OBJDIR)/danlin_fontawesome_5dc89e5d.o \
  $(OBJDIR)/danlin_oscpack_78c72fdd.o \
  $(OBJDIR)/danlin_oscserver_19e071d.o \
  $(OBJDIR)/juce_audio_basics_ae169784.o \
  $(OBJDIR)/juce_audio_devices_87a1b42.o \
  $(OBJDIR)/juce_audio_formats_36fb64e2.o \
  $(OBJDIR)/juce_audio_processors_11cdad3c.o \
  $(OBJDIR)/juce_core_dca6a866.o \
  $(OBJDIR)/juce_data_structures_451caba2.o \
  $(OBJDIR)/juce_events_7c4271da.o \
  $(OBJDIR)/juce_graphics_9f46d43e.o \
  $(OBJDIR)/juce_gui_basics_38a9ecba.o \
  $(OBJDIR)/juce_gui_extra_c3404c2.o \
  $(OBJDIR)/juce_PluginUtilities_ee6b9a4e.o \
  $(OBJDIR)/juce_VST_Wrapper_ef53a357.o \
  $(OBJDIR)/juce_VST3_Wrapper_729262d5.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking Soundboard
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning Soundboard
	@$(CLEANCMD)

strip:
	@echo Stripping Soundboard
	-@strip --strip-unneeded $(OUTDIR)/$(TARGET)

$(OBJDIR)/Player_a64961ea.o: ../../Source/Player.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Player.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginProcessor_a059e380.o: ../../Source/PluginProcessor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginProcessor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginEditor_94d4fb09.o: ../../Source/PluginEditor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginEditor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/LookAndFeel_40552bdf.o: ../../Source/LookAndFeel.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling LookAndFeel.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/danlin_fontawesome_5dc89e5d.o: ../../Submodules/danlin_modules/modules/danlin_fontawesome/danlin_fontawesome.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling danlin_fontawesome.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/danlin_oscpack_78c72fdd.o: ../../Submodules/danlin_modules/modules/danlin_oscpack/danlin_oscpack.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling danlin_oscpack.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/danlin_oscserver_19e071d.o: ../../Submodules/danlin_modules/modules/danlin_oscserver/danlin_oscserver.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling danlin_oscserver.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_ae169784.o: ../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_87a1b42.o: ../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_36fb64e2.o: ../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_processors_11cdad3c.o: ../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_dca6a866.o: ../../Submodules/JUCE/modules/juce_core/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_451caba2.o: ../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_7c4271da.o: ../../Submodules/JUCE/modules/juce_events/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_9f46d43e.o: ../../Submodules/JUCE/modules/juce_graphics/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_38a9ecba.o: ../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_c3404c2.o: ../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_PluginUtilities_ee6b9a4e.o: ../../Submodules/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_PluginUtilities.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST_Wrapper_ef53a357.o: ../../Submodules/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_VST_Wrapper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST3_Wrapper_729262d5.o: ../../Submodules/JUCE/modules/juce_audio_plugin_client/VST3/juce_VST3_Wrapper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_VST3_Wrapper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
