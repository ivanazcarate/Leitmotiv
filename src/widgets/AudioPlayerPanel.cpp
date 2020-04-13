#include "MainFrame.hpp"

AudioPlayerPanel::AudioPlayerPanel(wxPanel * parent)
       : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
    mParent = parent;
    
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *vbox_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *vbox_2 = new wxBoxSizer(wxVERTICAL);

    mPlayer = std::make_shared<Player>(1);
    mPlayer->startPlayer();
    mPlay = new wxButton(this, ID_Play, wxT("Play"),
        wxPoint(10, 5));
    mPause = new wxButton(this, ID_Pause, wxT("Pause"),
        wxPoint(10, 45));
    mStop = new wxButton(this, ID_Stop, wxT("Stop"),
        wxPoint(10, 85));
    mLoad = new wxButton(this, ID_Load, wxT("Load"),
        wxPoint(150, 5));
    Connect(ID_Play, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(AudioPlayerPanel::OnPlay));
    Connect(ID_Pause, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(AudioPlayerPanel::OnPause));
    Connect(ID_Stop, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(AudioPlayerPanel::OnStop));
    Connect(ID_Load, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(AudioPlayerPanel::OnLoad));
    vbox_1->Add(mPlay, 1, wxALIGN_CENTER, 5);
    vbox_1->Add(mPause, 1, wxALIGN_CENTER, 5);
    vbox_1->Add(mStop, 1, wxALIGN_CENTER, 5);
    vbox_2->Add(mLoad, 0.5, wxALIGN_CENTER | wxALIGN_TOP , 5);

    hbox -> Add(vbox_1, 1, wxEXPAND | wxALL, 5);
    hbox -> Add(vbox_2, 1, wxEXPAND | wxALL, 5);
    this->SetSizer(hbox);
}

void AudioPlayerPanel::OnPlay(wxCommandEvent & WXUNUSED(event))
{    
    mPlayer->play();
}

void AudioPlayerPanel::OnPause(wxCommandEvent & WXUNUSED(event))
{
    mPlayer->pause();
}

void AudioPlayerPanel::OnStop(wxCommandEvent & WXUNUSED(event))
{
    mPlayer->stop();
}

void AudioPlayerPanel::OnLoad(wxCommandEvent & WXUNUSED(event))
{
    // This code is temporary here in order
    // to test if playing audio using the GUI works
    auto m = std::make_shared<Motiv>(1,"../resources/leitmotives/lm_2.wav");
    mPlayer->setAudioFileURL(m->getAudioURL());
}

