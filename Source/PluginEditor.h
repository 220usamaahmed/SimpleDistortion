/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SimpleDistortionAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleDistortionAudioProcessorEditor (SimpleDistortionAudioProcessor&);
    ~SimpleDistortionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleDistortionAudioProcessor& audioProcessor;

    juce::Slider driveSlider;
    juce::Slider rangeSlider;
    juce::Slider blendSlider;
    juce::Slider volumeSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> rangeSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> blendSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> volumeSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleDistortionAudioProcessorEditor)
};
