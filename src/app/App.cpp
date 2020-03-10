#include <iostream>
#include <thread>
#include <cassert>
#include <wx/wx.h>
#include "App.hpp"
#include "MainFrame.hpp"
#include "Motiv.hpp"
#include "Player.hpp"
#include "Character.hpp"


wxIMPLEMENT_APP(LeitmotivApp);

bool LeitmotivApp::OnInit()
{
    MainFrame *frame = new MainFrame( "Leitmotiv", wxPoint(0, 0), wxSize(850, 640) );
    frame->Show( true );
    return true;
}
