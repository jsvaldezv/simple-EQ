#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

struct CustomRotarySlider : juce::Slider
{
    CustomRotarySlider() : juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,
                                        juce::Slider::TextEntryBoxPosition::NoTextBox)
    {
        
    }
};

struct ResponseCurveComponent : juce::Component,
juce::AudioProcessorParameter::Listener,
juce::Timer
{
public:
    
    ResponseCurveComponent (SimpleEQAudioProcessor&);
    ~ResponseCurveComponent() override;
    
    void paint (juce::Graphics& g) override;
    
    void parameterValueChanged (int parameterIndex, float newValue) override;
    void parameterGestureChanged (int parameterIndex, bool gestureIsStarting) override;
    
    void timerCallback() override;
    
private:
    
    juce::Atomic<bool> parametersChanged {false};
    
    MonoChain monoChain;
    
    SimpleEQAudioProcessor& audioProcessor;
};

class SimpleEQAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    
    SimpleEQAudioProcessorEditor (SimpleEQAudioProcessor&);
    ~SimpleEQAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    SimpleEQAudioProcessor& audioProcessor;
    
    CustomRotarySlider  peakFreqSlider,
                        peakGainSlider,
                        peakQualitySlider,
                        lowCutFreqSlider,
                        highCutFreqSlider,
                        lowCutSlopeSlider,
                        highCutSlopeSlider;
    
    ResponseCurveComponent responseCurveComponent;
    
    using APVTS = juce::AudioProcessorValueTreeState;
    using Attachment = APVTS::SliderAttachment;
    
    Attachment  peakFreqSliderAttachment,
                peakGainSliderAttachment,
                peakQualitySliderAttachment,
                lowCutFreqSliderAttachment,
                highCutFreqSliderAttachment,
                lowCutSlopeSliderAttachment,
                highCutSlopeSliderAttachment;
    
    std::vector<juce::Component*> getComps();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleEQAudioProcessorEditor)
};
