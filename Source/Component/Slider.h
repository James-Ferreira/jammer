#pragma once
#include <JuceHeader.h>

namespace Gui
{

    class Zlider : public Component, public Slider::Listener
    {
    public:
        using OnChange = std::function<void(float)>;

        Zlider(OnChange cb) : onChange(std::move(cb))
        {
            setSize(200, 400);
            addAndMakeVisible(slider);
            slider.setSliderStyle(juce::Slider::LinearVertical);
            slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
            slider.setRange(-48.0, 12.0);
            slider.setValue(-1);
            slider.addListener(this);


            addAndMakeVisible(label);
            label.setText("Gainzz", juce::NotificationType::dontSendNotification);
            label.setJustificationType(juce::Justification::centred);

            slider.setColour(Slider::textBoxTextColourId, juce::Colours::black);
            label.setColour(Label::textColourId, Colours::black);
        }

        ~Zlider() override {}

        void resized() override
        {
            slider.setBounds(getLocalBounds().reduced(10, 30));
            label.setBounds(getLocalBounds().removeFromTop(30));
        }

        void handleSliderChange()
        {
            if (onChange)
            {
                onChange(slider.getValue());
            }
        }

        void sliderValueChanged(Slider* slider) override
        {
            if (slider == &this->slider)
            {
                handleSliderChange();
            }
        }

    private:
        OnChange onChange;
        Slider slider;
        Label label;
    };
}
