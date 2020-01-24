/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class HelloWorldAudioProcessorEditor  : public AudioProcessorEditor,
                                        private Slider::Listener,
                                        public Timer
{
public:
    HelloWorldAudioProcessorEditor (HelloWorldAudioProcessor&);
    ~HelloWorldAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void timerCallback() override;

private:
    HelloWorldAudioProcessor& processor;
    
    Slider midiVolume;
    Slider audioGain;
    
    const int timerInterval = 100; // milliseconds
    
    VideoComponent video;
    const char *videoFilePath = "/Users/zl/Desktop/OnA steve remaster.mov";
    
    bool videoPlaying = false;
    bool videoIsLoaded = false;

    void sliderValueChanged (Slider *slider) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelloWorldAudioProcessorEditor)
};
