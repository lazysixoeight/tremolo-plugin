#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

namespace tremolo {
struct Parameters {
  explicit Parameters(juce::AudioProcessor&);
};
}  // namespace tremolo
