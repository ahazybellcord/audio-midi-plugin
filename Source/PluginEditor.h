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
                                        private Slider::Listener
{
public:
    HelloWorldAudioProcessorEditor (HelloWorldAudioProcessor&);
    ~HelloWorldAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    HelloWorldAudioProcessor& processor;
    
    Slider midiVolume;
    void sliderValueChanged (Slider *slider) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelloWorldAudioProcessorEditor)
};
