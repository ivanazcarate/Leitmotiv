/*
* Main Frame of the Application.
*
*/

#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include <wx/wx.h>
#include "Motiv.hpp"
#include "AudioPlayerPanel.hpp"
#include "IdeasPanel.hpp"

enum
{
    ID_Project = 1
};

class MainFrame: public wxFrame
{
    void OnProject(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
public:
    MainFrame( const wxString &title, const wxPoint &pos, const wxSize &size );
    wxPanel *mParent;
    AudioPlayerPanel *mAudioPlayerPanel;
    IdeasPanel *mIdeasPanel;
};

#endif