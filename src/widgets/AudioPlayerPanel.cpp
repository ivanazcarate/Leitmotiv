#include "MainFrame.hpp"

AudioPlayerPanel::AudioPlayerPanel(wxPanel * parent)
       : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
    mParent = parent;
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
}

void AudioPlayerPanel::OnPlay(wxCommandEvent & WXUNUSED(event))
{
    MainFrame *c = (MainFrame *)mParent->GetParent();
    c->mPlayer->play();
}

void AudioPlayerPanel::OnPause(wxCommandEvent & WXUNUSED(event))
{
    MainFrame *c = (MainFrame *)mParent->GetParent();
    c->mPlayer->pause();
}

void AudioPlayerPanel::OnStop(wxCommandEvent & WXUNUSED(event))
{
    MainFrame *c = (MainFrame *)mParent->GetParent();
    c->mPlayer->stop();
}

void AudioPlayerPanel::OnLoad(wxCommandEvent & WXUNUSED(event))
{
    // This code is temporary here in order
    // to test if playing audio using the GUI works
    auto m = std::make_shared<Motiv>(1,"../resources/leitmotives/lm_2.wav");
    MainFrame *c = (MainFrame *)mParent->GetParent();
    c->mPlayer->loadMotiv(m);
}

