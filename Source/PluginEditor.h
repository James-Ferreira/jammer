/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Component/HorizontalMeter.h"
#include "Component/Slider.h"
#include "Component/Stack.h"

//==============================================================================
/**
*/
class JammerEditor  : public juce::AudioProcessorEditor, public Timer
{
public:
    JammerEditor (JammerProcessor&);
    ~JammerEditor() override;

    //==============================================================================
    void timerCallback() override;
    void paint(juce::Graphics&) override;
    void resized() override;

    /* Sliders */
    void handleGainChange(float value);

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JammerProcessor& audioProcessor;

    Gui::HorizontalMeter horizontalMeterL, horizontalMeterR;
    Gui::Zlider gainSlider;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JammerEditor)
};
