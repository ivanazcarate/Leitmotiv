#include "RightPanel.hpp"

RightPanel::RightPanel(wxPanel *parent)
    :wxPanel(parent,-1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
    mParent = parent;
    wxBoxSizer *hbox = new wxBoxSizer(wxVERTICAL);

    mAudioPlayerPanel = new AudioPlayerPanel(this);
    mMotivsPanel = new MotivsPanel(this);

    hbox->Add(mMotivsPanel, 1, wxEXPAND | wxALL, 0);
    hbox->Add(mAudioPlayerPanel, 0.1, wxEXPAND | wxALL, 0);

    this->SetSizer(hbox);


}