//
// Created by matteo on 14/06/18.
//
#include <memory>
#include <wx/splash.h>
#include <wx/wx.h>

#include "MainApp.h"
#include "MainFrame.h"

using namespace std;

bool MainApp::OnInit()
{
    Mp3Player::Create();

    if(argc > 1)
        cout << argv[1]<<endl;

    MainFrame * mainFrame=new MainFrame("UTunes",wxPoint(50,50),wxSize(1024,728));

    //if(mainFrame!= nullptr) //è sempre vera??
    wxBitmap bitmap("resources/splash_screen.png",wxBITMAP_TYPE_PNG);
    wxSplashScreen splash(bitmap,wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,2000,nullptr,-1);
    wxYield();
    wxSleep(2);
    mainFrame->Show(true);

    return mainFrame!= nullptr;
}

int MainApp::OnExit()
{
    Mp3Player::Destroy();
}