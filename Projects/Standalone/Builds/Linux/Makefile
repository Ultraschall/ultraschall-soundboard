# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef STRIP
  STRIP=strip
endif

ifndef AR
  AR=ar
endif

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Debug
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DDEBUG=1 -D_DEBUG=1 -DJUCER_LINUX_MAKE_7346DA2A=1 -DJUCE_APP_VERSION=1.9.9 -DJUCE_APP_VERSION_HEX=0x10909 $(shell pkg-config --cflags alsa freetype2 libcurl x11 xext xinerama) -pthread -I../../JuceLibraryCode -I../../../../Submodules/danlin_modules/modules -I../../../../Submodules/JUCE/modules -I../../../../Submodules/stk_module/modules -I../../../../Source/Plugin -I../../../../Source/Shared/Player -I../../../../Source/Shared/UserInterface -I../../../../Source/Shared/UserInterface/Grid -I../../../../Source/Shared/UserInterface/Settings -I../../../../Source/Shared/UserInterface/Table
  JUCE_CFLAGS += $(CFLAGS) $(JUCE_CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0 -stdlib=libc++
  JUCE_CXXFLAGS += $(CXXFLAGS) $(JUCE_CFLAGS) -std=c++11
  JUCE_LDFLAGS += $(LDFLAGS) $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -L/usr/X11R6/lib/ $(shell pkg-config --libs alsa freetype2 libcurl x11 xext xinerama) -lGL -ldl -lpthread -lrt -stdlib=libc++

  TARGET := Soundboard
  BLDCMD = $(CXX) -o $(JUCE_OUTDIR)/$(TARGET) $(OBJECTS) $(JUCE_LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),Release)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Release
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DNDEBUG=1 -DJUCER_LINUX_MAKE_7346DA2A=1 -DJUCE_APP_VERSION=1.9.9 -DJUCE_APP_VERSION_HEX=0x10909 $(shell pkg-config --cflags alsa freetype2 libcurl x11 xext xinerama) -pthread -I../../JuceLibraryCode -I../../../../Submodules/danlin_modules/modules -I../../../../Submodules/JUCE/modules -I../../../../Submodules/stk_module/modules -I../../../../Source/Plugin -I../../../../Source/Shared/Player -I../../../../Source/Shared/UserInterface -I../../../../Source/Shared/UserInterface/Grid -I../../../../Source/Shared/UserInterface/Settings -I../../../../Source/Shared/UserInterface/Table
  JUCE_CFLAGS += $(CFLAGS) $(JUCE_CPPFLAGS) $(TARGET_ARCH) -Os -stdlib=libc++
  JUCE_CXXFLAGS += $(CXXFLAGS) $(JUCE_CFLAGS) -std=c++11
  JUCE_LDFLAGS += $(LDFLAGS) $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -fvisibility=hidden -L/usr/X11R6/lib/ $(shell pkg-config --libs alsa freetype2 libcurl x11 xext xinerama) -lGL -ldl -lpthread -lrt -stdlib=libc++

  TARGET := Soundboard
  BLDCMD = $(CXX) -o $(JUCE_OUTDIR)/$(TARGET) $(OBJECTS) $(JUCE_LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

OBJECTS := \
  $(JUCE_OBJDIR)/Main_9e5e7de4.o \
  $(JUCE_OBJDIR)/PluginEditor_834861fd.o \
  $(JUCE_OBJDIR)/PluginProcessor_67d3a80c.o \
  $(JUCE_OBJDIR)/Slot_8cd0b0ab.o \
  $(JUCE_OBJDIR)/Bank_5ec47de9.o \
  $(JUCE_OBJDIR)/Library_2efeabf8.o \
  $(JUCE_OBJDIR)/Player_77495a0e.o \
  $(JUCE_OBJDIR)/TableButtonCell_9e52701f.o \
  $(JUCE_OBJDIR)/TableComponent_f010aebc.o \
  $(JUCE_OBJDIR)/GridCell_9bf901ef.o \
  $(JUCE_OBJDIR)/GridComponent_d088b95a.o \
  $(JUCE_OBJDIR)/SettingsComponent_76602a3a.o \
  $(JUCE_OBJDIR)/LookAndFeel_93bf7b9c.o \
  $(JUCE_OBJDIR)/danlin_fontawesome_59f5bb3e.o \
  $(JUCE_OBJDIR)/danlin_oscpack_5bf5a822.o \
  $(JUCE_OBJDIR)/danlin_oscserver_1dc02b4c.o \
  $(JUCE_OBJDIR)/juce_audio_basics_6b797ca1.o \
  $(JUCE_OBJDIR)/juce_audio_devices_a742c38b.o \
  $(JUCE_OBJDIR)/juce_audio_formats_5a29c68a.o \
  $(JUCE_OBJDIR)/juce_audio_processors_dea3173d.o \
  $(JUCE_OBJDIR)/juce_audio_utils_c7eb679f.o \
  $(JUCE_OBJDIR)/juce_core_75b14332.o \
  $(JUCE_OBJDIR)/juce_data_structures_72d3da2c.o \
  $(JUCE_OBJDIR)/juce_events_d2be882c.o \
  $(JUCE_OBJDIR)/juce_graphics_9c18891e.o \
  $(JUCE_OBJDIR)/juce_gui_basics_8a6da59c.o \
  $(JUCE_OBJDIR)/juce_gui_extra_4a026f23.o \
  $(JUCE_OBJDIR)/juce_opengl_cd70b4c2.o \
  $(JUCE_OBJDIR)/stk_core_3544047d.o \
  $(JUCE_OBJDIR)/stk_generators_a5b9599e.o \

.PHONY: clean

$(JUCE_OUTDIR)/$(TARGET): check-pkg-config $(OBJECTS) $(RESOURCES)
	@echo Linking Soundboard
	-@mkdir -p $(JUCE_BINDIR)
	-@mkdir -p $(JUCE_LIBDIR)
	-@mkdir -p $(JUCE_OUTDIR)
	@$(BLDCMD)

check-pkg-config:
	@command -v pkg-config >/dev/null 2>&1 || { echo >&2 "pkg-config not installed. Please, install it."; exit 1; }
	@pkg-config --print-errors alsa freetype2 libcurl x11 xext xinerama

clean:
	@echo Cleaning Soundboard
	@$(CLEANCMD)

strip:
	@echo Stripping Soundboard
	-@$(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(TARGET)

$(JUCE_OBJDIR)/Main_9e5e7de4.o: ../../../../Source/Standalone/Main.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Main.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PluginEditor_834861fd.o: ../../../../Source/Plugin/PluginEditor.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling PluginEditor.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PluginProcessor_67d3a80c.o: ../../../../Source/Plugin/PluginProcessor.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling PluginProcessor.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Slot_8cd0b0ab.o: ../../../../Source/Shared/Player/Slot.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Slot.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Bank_5ec47de9.o: ../../../../Source/Shared/Player/Bank.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Bank.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Library_2efeabf8.o: ../../../../Source/Shared/Player/Library.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Library.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Player_77495a0e.o: ../../../../Source/Shared/Player/Player.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Player.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TableButtonCell_9e52701f.o: ../../../../Source/Shared/UserInterface/Table/TableButtonCell.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling TableButtonCell.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TableComponent_f010aebc.o: ../../../../Source/Shared/UserInterface/Table/TableComponent.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling TableComponent.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/GridCell_9bf901ef.o: ../../../../Source/Shared/UserInterface/Grid/GridCell.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling GridCell.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/GridComponent_d088b95a.o: ../../../../Source/Shared/UserInterface/Grid/GridComponent.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling GridComponent.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SettingsComponent_76602a3a.o: ../../../../Source/Shared/UserInterface/Settings/SettingsComponent.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling SettingsComponent.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/LookAndFeel_93bf7b9c.o: ../../../../Source/Shared/UserInterface/LookAndFeel.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling LookAndFeel.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/danlin_fontawesome_59f5bb3e.o: ../../JuceLibraryCode/danlin_fontawesome.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling danlin_fontawesome.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/danlin_oscpack_5bf5a822.o: ../../JuceLibraryCode/danlin_oscpack.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling danlin_oscpack.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/danlin_oscserver_1dc02b4c.o: ../../JuceLibraryCode/danlin_oscserver.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling danlin_oscserver.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_basics_6b797ca1.o: ../../JuceLibraryCode/juce_audio_basics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_devices_a742c38b.o: ../../JuceLibraryCode/juce_audio_devices.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_formats_5a29c68a.o: ../../JuceLibraryCode/juce_audio_formats.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_processors_dea3173d.o: ../../JuceLibraryCode/juce_audio_processors.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_utils_c7eb679f.o: ../../JuceLibraryCode/juce_audio_utils.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_utils.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_core_75b14332.o: ../../JuceLibraryCode/juce_core.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_data_structures_72d3da2c.o: ../../JuceLibraryCode/juce_data_structures.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_events_d2be882c.o: ../../JuceLibraryCode/juce_events.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_graphics_9c18891e.o: ../../JuceLibraryCode/juce_graphics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_gui_basics_8a6da59c.o: ../../JuceLibraryCode/juce_gui_basics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_gui_extra_4a026f23.o: ../../JuceLibraryCode/juce_gui_extra.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_opengl_cd70b4c2.o: ../../JuceLibraryCode/juce_opengl.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_opengl.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/stk_core_3544047d.o: ../../JuceLibraryCode/stk_core.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling stk_core.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/stk_generators_a5b9599e.o: ../../JuceLibraryCode/stk_generators.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling stk_generators.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
