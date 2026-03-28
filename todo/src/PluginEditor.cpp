#include "include/PluginEditor.h"
#include <PluginAssets.h>

PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p) {
  background.setImage(juce::ImageCache::getFromMemory(
      PluginAssets::Background_png, PluginAssets::Background_pngSize));

  logo.setImage(
      juce::ImageCache::getFromMemory(PluginAssets::Logo_png, PluginAssets::Logo_pngSize));

  addAndMakeVisible(background);
  addAndMakeVisible(logo);

  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(540, 270);
}

void PluginEditor::resized() {
  const auto bounds = getLocalBounds();

  background.setBounds(bounds);

  logo.setBounds({16, 16, 105, 24});
}
