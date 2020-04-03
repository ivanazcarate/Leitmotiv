/*
* This class is derived from the wxPanel class
* It contains the controls for the Audio Player
* in the GUI.
*
*/

#ifndef __AUDIO_PLAYER_PANEL_H__
#define __AUDIO_PLAYER_PANEL_H__

#include <wx/wx.h>
#include "Player.hpp"
#include <wx/panel.h>

enum
{
    ID_Play = 1,
    ID_Pause = 2,
    ID_Stop = 3,
    ID_Load = 4
};

class AudioPlayerPanel : public wxPanel
{
public:
    AudioPlayerPanel(wxPanel *parent);

    void OnPlay(wxCommandEvent & event);
    void OnPause(wxCommandEvent & event);
    void OnStop(wxCommandEvent & event);
    void OnLoad(wxCommandEvent & event);
private:
    wxButton *mPlay;
    wxButton *mPause;
    wxButton *mStop;
    wxButton *mLoad;
    wxPanel *mParent;
    std::shared_ptr<Player> mPlayer;


};



#endif // __AUDIO_PLAYER_PANEL_H__