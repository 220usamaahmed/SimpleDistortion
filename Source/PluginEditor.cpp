/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleDistortionAudioProcessorEditor::SimpleDistortionAudioProcessorEditor (SimpleDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    driveSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    driveSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 96, 48);
    addAndMakeVisible(driveSlider);

    rangeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    rangeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 96, 48);
    addAndMakeVisible(rangeSlider);

    blendSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    blendSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 96, 48);
    addAndMakeVisible(blendSlider);

    volumeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    volumeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 50);
    addAndMakeVisible(volumeSlider);

    driveSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "Drive", driveSlider);
    rangeSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "Range", rangeSlider);
    blendSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "Blend", blendSlider);
    volumeSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "Volume", volumeSlider);

    setSize (400, 200);
}

SimpleDistortionAudioProcessorEditor::~SimpleDistortionAudioProcessorEditor()
{
}

//==============================================================================
void SimpleDistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SimpleDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    driveSlider.setBounds(10, getHeight() / 2 - 40, 80, 80);
    rangeSlider.setBounds(110, getHeight() / 2 - 40, 80, 80);
    blendSlider.setBounds(210, getHeight() / 2 - 40, 80, 80);
    volumeSlider.setBounds(310, getHeight() / 2 - 40, 80, 80);
}
