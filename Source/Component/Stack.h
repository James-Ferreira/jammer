#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <JuceHeader.h>

namespace Gui
{
    inline void sliderStack(
        Array<Gui::Zlider*>& sliders,
        int interval,
        int sliderWidth,
        int sliderHeight,
        int startX,
        int startY
    )
    {
        int x = startX; // Initial x-coordinate
        int y = startY; // Initial y-coordinate

        // Loop through each slider
        for (auto* slider : sliders)
        {
            slider->setBounds(x, y, sliderWidth, sliderHeight);

            // Increment x-coordinate by the slider width and interval
            x += sliderWidth + interval;
        }
    }

}

#endif // STACK_H_INCLUDED
