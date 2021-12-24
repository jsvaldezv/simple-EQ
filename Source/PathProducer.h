#pragma once
#include "FFTDataGenerator.h"
#include "AnalyzerDataGenerator.h"

struct PathProducer
{
    PathProducer(SingleChannelSampleFifo<SimpleEQAudioProcessor::BlockType>& scsf) : leftChannelFifo(&scsf)
    {
        leftChannelFFTDataGenerator.changeOrder(FFTOrder::order2048);
        monoBuffer.setSize(1, leftChannelFFTDataGenerator.getFFTSize());
    }
    
    void process(juce::Rectangle<float> fftBounds, double sampleRate);
    juce::Path getPath() {return leftChannelFFTPath;}
    
private:
    
    SingleChannelSampleFifo<SimpleEQAudioProcessor::BlockType>* leftChannelFifo;
    
    juce::AudioBuffer<float> monoBuffer;
    
    FFTDataGenerator<std::vector<float>> leftChannelFFTDataGenerator;
    
    AnalyzerPathGenerator<juce::Path> pathProducer;
    
    juce::Path leftChannelFFTPath;
};
