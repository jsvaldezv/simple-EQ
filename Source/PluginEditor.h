#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Components/FFTDataGenerator.h"
#include "Components/AnalyzerDataGenerator.h"
#include "Components/ResponseCurveComponent.h"
#include "Components/PathProducer.h"
#include "LookAndFeel/LookAndFeel.h"

class SimpleEQAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    
    SimpleEQAudioProcessorEditor (SimpleEQAudioProcessor&);
    ~SimpleEQAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    SimpleEQAudioProcessor& audioProcessor;
    
    RotarySliderWithLabels  peakFreqSlider,
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
    
    PowerButton lowcutBypassButton, peakBypassButton, highcutBypassButton;
    AnalyzerButton analyserEnabledButton;
    
    using ButtonAttachment = APVTS::ButtonAttachment;
    ButtonAttachment    lowcutBypassButtonAttachment,
                        peakBypassButtonAttachment,
                        highcutBypassButtonAttachment,
                        analyserEnabledButtonAttachment;
    
    std::vector<juce::Component*> getComps();
    
    LookAndFeel lnf;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleEQAudioProcessorEditor)
};
