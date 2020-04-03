#ifndef __MOTIVS_PANEL_H__
#define __MOTIVS_PANEL_H__

#include <wx/wx.h>
#include <wx/panel.h>

class MotivsPanel:public wxPanel{

public:
    MotivsPanel(wxPanel * parent);    

private:
    wxPanel *mParent;
};


#endif // __MOTIVS_PANEL_H__