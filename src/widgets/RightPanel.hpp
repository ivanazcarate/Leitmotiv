#ifndef __RIGHT_PANEL_H__
#define __RIGHT_PANEL_H__

#include <wx/wx.h>
#include <wx/panel.h>
#include "AudioPlayerPanel.hpp"
#include "MotivsPanel.hpp"

class RightPanel:public wxPanel{

public:
    RightPanel(wxPanel *parent);    

private:
    wxPanel *mParent;
    AudioPlayerPanel *mAudioPlayerPanel;
    MotivsPanel *mMotivsPanel; 

};


#endif // __RIGHT_PANEL_H__