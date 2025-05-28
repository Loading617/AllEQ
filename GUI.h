#ifndef _AllEQ_GUI_h_
#define _AllEQ_GUI_h_

#include <CtrlLib/CtrlLib.h>
using namespace Upp;

class AllEqGUI : public TopWindow {
public:
    SliderCtrl bass, mid, treble;
    Button applyButton;

    AllEqGUI();
    void OnApply();
};

#endif
