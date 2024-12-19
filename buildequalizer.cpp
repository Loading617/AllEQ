#include <wx/wx.h>
#include <wx/slider.h>

class EqualizerFrame : public wxFrame {
public:
    EqualizerFrame(const wxString& title);

private:
    void OnSliderChange(wxCommandEvent& event);

    wxSlider* bassSlider;
    wxSlider* midSlider;
    wxSlider* trebleSlider;

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(EqualizerFrame, wxFrame)
    EVT_SLIDER(wxID_ANY, EqualizerFrame::OnSliderChange)
wxEND_EVENT_TABLE()

class EqualizerApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(EqualizerApp);

bool EqualizerApp::OnInit() {
    EqualizerFrame* frame = new EqualizerFrame("System Equalizer");
    frame->Show(true);
    return true;
}

EqualizerFrame::EqualizerFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)) {
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    bassSlider = new wxSlider(this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize(300, 50), wxSL_HORIZONTAL | wxSL_LABELS);
    midSlider = new wxSlider(this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize(300, 50), wxSL_HORIZONTAL | wxSL_LABELS);
    trebleSlider = new wxSlider(this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize(300, 50), wxSL_HORIZONTAL | wxSL_LABELS);

    sizer->Add(new wxStaticText(this, wxID_ANY, "Bass"), 0, wxALL | wxALIGN_CENTER, 5);
    sizer->Add(bassSlider, 0, wxALL | wxALIGN_CENTER, 5);
    sizer->Add(new wxStaticText(this, wxID_ANY, "Mid"), 0, wxALL | wxALIGN_CENTER, 5);
    sizer->Add(midSlider, 0, wxALL | wxALIGN_CENTER, 5);
    sizer->Add(new wxStaticText(this, wxID_ANY, "Treble"), 0, wxALL | wxALIGN_CENTER, 5);
    sizer->Add(trebleSlider, 0, wxALL | wxALIGN_CENTER, 5);

    SetSizer(sizer);
}

void EqualizerFrame::OnSliderChange(wxCommandEvent& event) {
    int bass = bassSlider->GetValue();
    int mid = midSlider->GetValue();
    int treble = trebleSlider->GetValue();

    // Update equalizer settings
    wxLogMessage("Bass: %d, Mid: %d, Treble: %d", bass, mid, treble);
}
