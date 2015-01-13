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

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.4" -D "JUCE_APP_VERSION_HEX=0x10400" -I /usr/include -I /usr/include/freetype2 -I ../../JuceLibraryCode -I ../../../Submodules/danlin_modules/modules -I ../../../Submodules/JUCE/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -L/usr/X11R6/lib/ -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.4" -D "JUCE_APP_VERSION_HEX=0x10400" -I /usr/include -I /usr/include/freetype2 -I ../../JuceLibraryCode -I ../../../Submodules/danlin_modules/modules -I ../../../Submodules/JUCE/modules
  TARGET := Soundboard
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

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.4" -D "JUCE_APP_VERSION_HEX=0x10400" -I /usr/include -I /usr/include/freetype2 -I ../../JuceLibraryCode -I ../../../Submodules/danlin_modules/modules -I ../../../Submodules/JUCE/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -Os
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -fvisibility=hidden -L/usr/X11R6/lib/ -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.4" -D "JUCE_APP_VERSION_HEX=0x10400" -I /usr/include -I /usr/include/freetype2 -I ../../JuceLibraryCode -I ../../../Submodules/danlin_modules/modules -I ../../../Submodules/JUCE/modules
  TARGET := Soundboard
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

OBJECTS := \
  $(OBJDIR)/Player_4d629b.o \
  $(OBJDIR)/LookAndFeel_b6daf1ce.o \
  $(OBJDIR)/GridComponent_d7366267.o \
  $(OBJDIR)/TableComponent_f21f3489.o \
  $(OBJDIR)/PluginEditor_ef07f2fa.o \
  $(OBJDIR)/PluginProcessor_319d19ef.o \
  $(OBJDIR)/Main_90ebc5c2.o \
  $(OBJDIR)/danlin_fontawesome_f87f2fce.o \
  $(OBJDIR)/danlin_oscpack_7cfac24e.o \
  $(OBJDIR)/danlin_oscserver_c3f0f90e.o \
  $(OBJDIR)/juce_audio_basics_5a8f0a75.o \
  $(OBJDIR)/juce_audio_devices_78a195f3.o \
  $(OBJDIR)/juce_audio_formats_a722df93.o \
  $(OBJDIR)/juce_audio_processors_d4209f2d.o \
  $(OBJDIR)/juce_audio_utils_1bd91f33.o \
  $(OBJDIR)/juce_core_4c9d1d57.o \
  $(OBJDIR)/juce_data_structures_ab565d3.o \
  $(OBJDIR)/juce_events_7123064b.o \
  $(OBJDIR)/juce_graphics_4ff5c82f.o \
  $(OBJDIR)/juce_gui_basics_4feb802b.o \
  $(OBJDIR)/juce_gui_extra_4cf5c073.o \

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

$(OBJDIR)/Player_4d629b.o: ../../../Source/Player.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Player.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/LookAndFeel_b6daf1ce.o: ../../../Source/LookAndFeel.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling LookAndFeel.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/GridComponent_d7366267.o: ../../../Source/GridComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling GridComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/TableComponent_f21f3489.o: ../../../Source/TableComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling TableComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginEditor_ef07f2fa.o: ../../../Source/PluginEditor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginEditor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginProcessor_319d19ef.o: ../../../Source/PluginProcessor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginProcessor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Main_90ebc5c2.o: ../../Source/Main.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Main.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/danlin_fontawesome_f87f2fce.o: ../../../Submodules/danlin_modules/modules/danlin_fontawesome/danlin_fontawesome.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling danlin_fontawesome.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/danlin_oscpack_7cfac24e.o: ../../../Submodules/danlin_modules/modules/danlin_oscpack/danlin_oscpack.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling danlin_oscpack.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/danlin_oscserver_c3f0f90e.o: ../../../Submodules/danlin_modules/modules/danlin_oscserver/danlin_oscserver.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling danlin_oscserver.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_5a8f0a75.o: ../../../Submodules/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_78a195f3.o: ../../../Submodules/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_a722df93.o: ../../../Submodules/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_processors_d4209f2d.o: ../../../Submodules/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_utils_1bd91f33.o: ../../../Submodules/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_utils.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_4c9d1d57.o: ../../../Submodules/JUCE/modules/juce_core/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_ab565d3.o: ../../../Submodules/JUCE/modules/juce_data_structures/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_7123064b.o: ../../../Submodules/JUCE/modules/juce_events/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_4ff5c82f.o: ../../../Submodules/JUCE/modules/juce_graphics/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_4feb802b.o: ../../../Submodules/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_4cf5c073.o: ../../../Submodules/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
