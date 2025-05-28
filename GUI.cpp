#include "GUI.h"
#include "AllEQ.h"

Equalizer equalizer;

EqualizerGUI::EqualizerGUI() {
    Title("System Equalizer").Sizeable();

    Add(bass.LeftPosZ(10, 100).TopPosZ(10, 30));
    Add(mid.LeftPosZ(120, 100).TopPosZ(10, 30));
    Add(treble.LeftPosZ(230, 100).TopPosZ(10, 30));
    Add(applyButton.LeftPosZ(10, 100).TopPosZ(50, 30));

    bass.SetRange(-10, 10);
    mid.SetRange(-10, 10);
    treble.SetRange(-10, 10);
    applyButton.SetLabel("Apply");
    applyButton <<= THISBACK(OnApply);
}

void EqualizerGUI::OnApply() {
    equalizer.SetBandGains(bass.GetData(), mid.GetData(), treble.GetData());
}
