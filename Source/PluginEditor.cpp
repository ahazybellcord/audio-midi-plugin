/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HelloWorldAudioProcessorEditor::HelloWorldAudioProcessorEditor (HelloWorldAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), videoPlayer (true)
{
    setSize (1000, 800);
   
    /* Video playback */
    videoPlayer.setEnabled (true);
    videoPlayer.setBounds (0, 0, getWidth(), getHeight());
    addAndMakeVisible (videoPlayer);
    
    /* Video playback timer */
    startTimer (timerInterval);
}

HelloWorldAudioProcessorEditor::~HelloWorldAudioProcessorEditor()
{
    stopPlaybackAndCloseVideo();
}

//==============================================================================
void HelloWorldAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);
    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("Midi Video Keyboard", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void HelloWorldAudioProcessorEditor::resized()
{
}

void HelloWorldAudioProcessorEditor::timerCallback() {
    for (int index = 0; index < 128; index++)
    {
        // Break in each case so we deal with only one event at a time.
        if (processor.getShouldBePlaying(index) && !videoIsPlaying[index])
        {
            char videoFileName[100];
            snprintf(videoFileName, 100, "%s/%d.mov", videoFileDir, index);
            
            stopPlaybackAndCloseVideo();
            videoPlayer.load(File(videoFileName));
            videoPlayer.setPlaySpeed(processor.getVideoSpeed());
            videoPlayer.play();
            
            videoIsPlaying[index] = true;
            break;
        }

        if (!processor.getShouldBePlaying(index) && videoIsPlaying[index])
        {
            stopPlaybackAndCloseVideo();
            
            videoIsPlaying[index] = false;
            break;
        }
    }
    
    // Loop playback.
    if (videoPlayer.isVideoOpen() && !videoPlayer.isPlaying())
        videoPlayer.play();
}

void HelloWorldAudioProcessorEditor::stopPlaybackAndCloseVideo()
{
    if (videoPlayer.isPlaying())
        videoPlayer.stop();
    if (videoPlayer.isVideoOpen())
        videoPlayer.closeVideo();
}

void HelloWorldAudioProcessorEditor::resizeToVideoDimensions()
{
    if (!videoPlayer.isVideoOpen())
        return;
    
    auto dimensions = videoPlayer.getVideoNativeSize();
    int x = dimensions.getX();
    int y = dimensions.getY();
    if (x > 0 && y > 0)
        setSize (x, y);
}
