#include "../PluginEditor.h"

void JammerEditor::handleGainChange(float value)
{
    audioProcessor.rawVolume = pow(10, value / 20);
}

void JammerEditor::handleDriveChange(float value)
{
    audioProcessor.drive = value;
}

void JammerEditor::handleRangeChange(float value)
{
    audioProcessor.range = value;
}

void JammerEditor::handleBlendChange(float value)
{
    audioProcessor.blend = value;
}
