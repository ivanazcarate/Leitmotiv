#include "WorkspacePanel.hpp"

WorkspacePanel::WorkspacePanel(wxPanel *parent)
    : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
    mParent = parent;
}

