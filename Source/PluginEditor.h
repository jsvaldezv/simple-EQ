#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class SimpleEQAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    
    SimpleEQAudioProcessorEditor (SimpleEQAudioProcessor&);
    ~SimpleEQAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    SimpleEQAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleEQAudioProcessorEditor)
};
