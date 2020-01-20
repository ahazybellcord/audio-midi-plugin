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
    setSize (400, 400);
    
    midiVolume.setSliderStyle(Slider::ThreeValueHorizontal);
    midiVolume.setRange(0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    midiVolume.setPopupDisplayEnabled(true, true, this);
    midiVolume.setTextValueSuffix(" Volume");
    
    midiVolume.setMinMaxAndCurrentValues(0.0, 127.0, 64.0);
    midiVolume.setBounds(20, 20, getWidth() - 40, 30);
    addAndMakeVisible(&midiVolume);
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
