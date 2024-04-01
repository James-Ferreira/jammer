#pragma once

#include <JuceHeader.h>

namespace Gui
{
	class HorizontalMeter : public Component
	{
	public:
		void paint(Graphics& g) override
		{
			auto bounds = getLocalBounds().toFloat();

			g.setColour(Colours::black);
			g.fillRoundedRectangle(bounds, 0.5f);
			g.setColour(Colours::white);

			g.setGradientFill(gradient);
			// map level from -60.f / +6.f to 0 / width
			const auto scaledX = jmap(level, -60.f, +6.f, 0.f, (float)getWidth());
			g.fillRoundedRectangle(bounds.removeFromLeft(scaledX), 0.5f);
		}

		void setLevel(const float value) { level = value; }

		void resized() override
		{
			const auto bounds = getLocalBounds().toFloat();
			gradient = ColourGradient(
				Colour(0xffff0000),  // Red
				bounds.getBottomLeft(),
				Colour(0xffffc000),  // Orange
				bounds.getTopRight(),
				false
			);
			gradient.addColour(0.25, Colour(0xffffff00));   // Yellow
			gradient.addColour(0.375, Colour(0xff00ff00));  // Green
			gradient.addColour(0.5, Colour(0xff00ffff));    // Blue
			gradient.addColour(0.625, Colour(0xff8000ff));  // Purple
			gradient.addColour(0.75, Colour(0xffff80ff));   // Pink
		}
	private:
		float level = -60.0f;
		ColourGradient gradient{};
	};
}