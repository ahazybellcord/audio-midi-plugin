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
    : AudioProcessorEditor (&p), processor (p), video (true)
{
    setSize (400, 400);
    
    /* MIDI velocity limiter */
    midiVolume.setSliderStyle (Slider::LinearBarVertical);
    midiVolume.setRange (0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle (Slider::NoTextBox, false, 100, 20);
    midiVolume.setPopupDisplayEnabled (true, true, this);
    midiVolume.setTextValueSuffix (" Velocity");
    
    midiVolume.setValue (64.0);
    midiVolume.setBounds (40, 30, 20, getHeight() - 60);
    addAndMakeVisible (&midiVolume);
    
    midiVolume.addListener (this);
    
    /* Audio gain */
    audioGain.setSliderStyle (Slider::LinearBarVertical);
    audioGain.setRange (0.0, 1.0, 0.01);
    audioGain.setTextBoxStyle (Slider::NoTextBox, false, 100, 20);
    audioGain.setPopupDisplayEnabled (true, true, this);
    audioGain.setTextValueSuffix (" Gain");
    
    audioGain.setValue (1.0);
    audioGain.setBounds (80, 30, 20, getHeight() - 60);
    addAndMakeVisible (audioGain);
    
    audioGain.addListener (this);
    
    /* Video playback */
    video.setEnabled (true);
    video.setBounds (0, 0, getWidth(), getHeight());
    video.load (File(videoFilePath));
    addAndMakeVisible (video);
    
    /* Video playback timer */
    startTimer (timerInterval);
}

HelloWorldAudioProcessorEditor::~HelloWorldAudioProcessorEditor()
{
    if (video.isPlaying())
        video.stop();
    if (video.isVideoOpen())
        video.closeVideo();
}

//==============================================================================
void HelloWorldAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);
    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("Midi Volume", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void HelloWorldAudioProcessorEditor::resized()
{
    midiVolume.setBounds(40, 30, 20, getHeight() - 60);
}

void HelloWorldAudioProcessorEditor::sliderValueChanged (Slider *slider)
{
    if (slider == &midiVolume)
    {
        processor.setNoteOnVel (midiVolume.getValue());
    }
    else if (slider == &audioGain)
    {
        processor.setAudioGain (audioGain.getValue());
    }
}

void HelloWorldAudioProcessorEditor::timerCallback() {
    if (processor.getShouldBePlaying() && !video.isPlaying())
    {
        video.play();
    }

    if (!processor.getShouldBePlaying() && video.isPlaying())
    {
        video.stop();
    }
}
