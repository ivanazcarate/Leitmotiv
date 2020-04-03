#ifndef __WORKSPACE_PANEL_H__
#define __WORKSPACE_PANEL_H__

#include <wx/wx.h>
#include <wx/panel.h>

class WorkspacePanel : public wxPanel{
public:
    WorkspacePanel(wxPanel *parent);
private:
    wxPanel *mParent;
};


#endif // __WORKSPACE_PANEL_H__