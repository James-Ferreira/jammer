#pragma once
#include <JuceHeader.h>

namespace Gui
{

    class Zlider : public Component, public Slider::Listener
    {
    public:
        using OnChange = std::function<void(float)>;

        static constexpr int defaultWidth = 200;
        static constexpr int defaultHeight = 400;

        Zlider(OnChange cb, Slider::SliderStyle sliderStyle, const String& labelText)
            : onChange(std::move(cb))
        {
            setSize(defaultWidth, defaultHeight);

            addAndMakeVisible(slider);
            slider.setSliderStyle(sliderStyle);
            slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
            slider.addListener(this);

            addAndMakeVisible(label);
            label.setText(labelText, juce::NotificationType::dontSendNotification);
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

        void setSliderRange(float min, float max) {
            slider.setRange(min, max);
        }

        void setSliderValue(float value) {
            slider.setValue(value);
        }

        juce::Slider& getSlider() noexcept {
            return slider;
        }

    private:
        OnChange onChange;
        Slider slider;
        Label label;
    };

    class GainSlider : public Zlider
    {
    public:
        GainSlider(OnChange cb)
            : Zlider(cb, Slider::LinearVertical, "Gain")
        {
            setSliderRange(-48.0, 12.0);
            setSliderValue(-1);
        }
    };

    class DriveSlider : public Zlider
    {
    public:
        DriveSlider(OnChange cb)
            : Zlider(cb, Slider::Rotary, "Drive")
        {
            setSliderRange(0.f, 1.f);
            setSliderValue(1);
        }
    };

    class BlendSlider : public Zlider
    {
    public:
        BlendSlider(OnChange cb)
            : Zlider(cb, Slider::Rotary, "Blend")
        {
            setSliderRange(0.f, 1.f);
            setSliderValue(1.f);
        }
    };

    class RangeSlider : public Zlider
    {
    public:
        RangeSlider(OnChange cb)
            : Zlider(cb, Slider::Rotary, "Range")
        {
            setSliderRange(0.f, 1.f);
            setSliderValue(1.f);
        }
    };

}
