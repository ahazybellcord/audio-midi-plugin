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

    const int timerInterval = 100; // timer tick interval in milliseconds
    
    VideoComponent videoPlayer;
    const char *videoFileDir = "/Users/zl/projects/juce/video_test";
    bool videoIsPlaying[128] = {false};
    bool videoIsLoaded[128] = {false};

    void stopPlaybackAndCloseVideo();
    void resizeToVideoDimensions();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelloWorldAudioProcessorEditor)
};
