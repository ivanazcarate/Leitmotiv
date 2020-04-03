#include "MainFrame.hpp"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{

    // Main Panel
    mParent = new wxPanel(this, wxID_ANY);

    // Child Panels
    
    //mAudioPlayerPanel = new AudioPlayerPanel(mParent);
    mRightPanel = new RightPanel(mParent);
    mIdeasPanel = new IdeasPanel(mParent);
    mWorkspacePanel = new WorkspacePanel(mParent);
   
    // BoxSizer for the Panels
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    hbox->Add(mIdeasPanel, 1, wxEXPAND | wxALL, 0);
    hbox->Add(mWorkspacePanel, 2 , wxEXPAND | wxALL, 0);
    hbox->Add(mRightPanel, 1, wxEXPAND | wxALL, 0);
    //hbox->Add(mAudioPlayerPanel, 1, wxEXPAND | wxALL, 0);
    
    mParent->SetSizer(hbox);
 
    // Frame Menu
    wxMenu *menuProject = new wxMenu;
    menuProject->Append(ID_Project, "&Project...\tCtrl-H","");
    menuProject->AppendSeparator();
    menuProject->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuProject, "&Project" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Leitmotiv" );
    Centre();

}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "Leitmotiv Application",
                  "About Leitmotiv", wxOK | wxICON_INFORMATION );
}

void MainFrame::OnProject(wxCommandEvent& event)
{

    wxLogMessage("placeholder");
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_Project,   MainFrame::OnProject)
    EVT_MENU(wxID_EXIT,  MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()