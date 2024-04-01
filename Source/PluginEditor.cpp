/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
//==============================================================================
JammerEditor::JammerEditor(JammerProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p),
    gainSlider([&](float value) { handleGainChange(value);  }),
    driveKnob([&](float value) { handleDriveChange(value);  }),
    rangeKnob([&](float value) { handleRangeChange(value);  }),
    blendKnob([&](float value) { handleBlendChange(value);  })
{
    addAndMakeVisible(horizontalMeterL);
    addAndMakeVisible(horizontalMeterR);
    addAndMakeVisible(gainSlider);
    addAndMakeVisible(driveKnob);
    addAndMakeVisible(rangeKnob);
    addAndMakeVisible(blendKnob);

    //driveAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(p.getState(), "drive", driveKnob.get()->getSlider());
    //rangeAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(p.getState(), "range", rangeKnob.get()->getSlider());
    //blendAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(p.getState(), "blend", blendKnob.get()->getSlider());
    //volumeAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(p.getState(), "volume", volumeKnob.get()->getSlider());

    setSize(600, 600);

    startTimerHz(24);
}

JammerEditor::~JammerEditor()
{
}


//==============================================================================

void JammerEditor::timerCallback()
{
    horizontalMeterL.setLevel(audioProcessor.getRmsValue(0));
    horizontalMeterR.setLevel(audioProcessor.getRmsValue(1));

    horizontalMeterL.repaint();
    horizontalMeterR.repaint();
}


void JammerEditor::paint(juce::Graphics& g)
{
    Random random;
    int red = random.nextInt(256);
    int green = random.nextInt(256);
    int blue = random.nextInt(256);

    Colour randomColor(red, green, blue);

    g.fillAll(randomColor);
}

void JammerEditor::resized()
{
    int width = getWidth();
    int height = getHeight();
    horizontalMeterL.setBounds(width - 250, height - 50, 200, 15);
    horizontalMeterR.setBounds(width - 250, height - 30, 200, 15);

    // Set the parameters for the sliders
    int sliderWidth = 100;
    int sliderHeight = 200;
    int interval = 10;
    int startX = 50;
    int startY = 10;

    Array<Gui::Zlider*> gainSlidersArray;
    gainSlidersArray.add(&gainSlider);
    gainSlidersArray.add(&driveKnob);
    gainSlidersArray.add(&rangeKnob);
    gainSlidersArray.add(&blendKnob);
    Gui::sliderStack(gainSlidersArray, interval, sliderWidth, sliderHeight, startX, startY);
}

