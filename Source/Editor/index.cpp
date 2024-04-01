#include "../PluginEditor.h"

void JammerEditor::handleGainChange(float value)
{
    audioProcessor.rawVolume = pow(10, value / 20);
}
