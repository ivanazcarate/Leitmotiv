#ifndef __IDEAS_PANEL__H__
#define __IDEAS_PANEL__H__

#include <wx/wx.h>


class IdeasPanel : public wxPanel{
public:
    IdeasPanel(wxPanel* parent);
    wxPanel *mParent;
    wxButton *mNewIdea;
};

#endif // __IDEAS_PANEL_H__