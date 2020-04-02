#include "IdeasPanel.hpp"

IdeasPanel::IdeasPanel(wxPanel *parent)
    : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
    mParent = parent;
    mNewIdea = new wxButton(this, 0, wxT("New Idea"),
                            wxPoint(10, 5));
}