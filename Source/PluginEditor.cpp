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
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (200, 200);
    
    midiVolume.setSliderStyle (Slider::LinearBarVertical);
    midiVolume.setRange (0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle (Slider::NoTextBox, false, 100, 20);
    midiVolume.setPopupDisplayEnabled (true, true, this);
    midiVolume.setTextValueSuffix (" Volume");
    
    midiVolume.setValue (64.0);
    midiVolume.setBounds (40, 30, 20, getHeight() - 60);
    addAndMakeVisible (&midiVolume);
    
    midiVolume.addListener (this);
}

HelloWorldAudioProcessorEditor::~HelloWorldAudioProcessorEditor()
{
}

//==============================================================================
void HelloWorldAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
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
    processor.setNoteOnVel (midiVolume.getValue());
}
