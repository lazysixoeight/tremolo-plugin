#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <tremolo_plugin/include/Tremolo/CustomLookAndFeel.h>

namespace tremolo {
class CustomLookAndFeel : public juce::LookAndFeel_V4 {};
}  // namespace tremolo
