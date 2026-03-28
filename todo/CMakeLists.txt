cmake_minimum_required(VERSION 3.22)

project(JucePluginDevelopmentCourseTremoloPlugin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Sets the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the JUCE dependency
include(FetchContent)

set(FETCHCONTENT_BASE_DIR "${PROJECT_SOURCE_DIR}/libs" CACHE PATH "External dependencies path." FORCE)

FetchContent_Declare(juce
  GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
  GIT_TAG 8.0.12
  SOURCE_DIR "${FETCHCONTENT_BASE_DIR}/JUCE")
FetchContent_MakeAvailable(juce)

# Adds a plugin target.
set(TREMOLO_PLUGIN_NAME "Tremolo")
juce_add_plugin(
  TremoloCoursePlugin
  PRODUCT_NAME
    ${TREMOLO_PLUGIN_NAME}
  VERSION
    0.0.0
  COMPANY_NAME
    "lazy608"
  PLUGIN_MANUFACTURER_CODE
    l608
  PLUGIN_CODE
    Trcp
  FORMATS
    Standalone
    AU
    VST3
  IS_SYNTH
    FALSE
  NEEDS_MIDI_INPUT
    FALSE
  NEEDS_MIDI_OUTPUT
    FALSE
  VST3_AUTO_MANIFEST
    FALSE
  COPY_PLUGIN_AFTER_BUILD
    FALSE
)

# Configures the JUCE sources included in the plugin target.
target_compile_definitions(TremoloCoursePlugin
  PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

juce_add_binary_data(PluginAssets
  HEADER_NAME
    "PluginAssets.h"
  NAMESPACE
    PluginAssets
  SOURCES
    assets/Background.png
    assets/Logo.png
    # TODO: Add custom font files
)

target_sources(TremoloCoursePlugin
  PRIVATE
    src/CustomLookAndFeel.cpp
    src/JsonSerializer.cpp
    src/Parameters.cpp
    src/PluginEditor.cpp
    src/PluginProcessor.cpp
)

target_link_libraries(
  TremoloCoursePlugin
  PRIVATE
    PluginAssets
    juce::juce_audio_utils
  PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
)
