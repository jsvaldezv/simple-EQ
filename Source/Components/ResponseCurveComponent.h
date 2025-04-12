#pragma once
#include <JuceHeader.h>
#include "../PluginProcessor.h"
#include "../Components/PathProducer.h"

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
    
    void resized() override;
    
    void toggleAnalysisEnablement(bool enabled)
    {
        shouldShowFFTAnalysis = enabled;
    }
    
private:
    
    juce::Atomic<bool> parametersChanged {false};
    
    MonoChain monoChain;
    
    void updateChain();
    
    SimpleEQAudioProcessor& audioProcessor;
    
    juce::Image background;
    
    juce::Rectangle<int> getRenderArea();
    
    juce::Rectangle<int> getAnalisisArea();
    
    PathProducer leftPathProducer, rightPathProducer;
    
    bool shouldShowFFTAnalysis = true;
};
