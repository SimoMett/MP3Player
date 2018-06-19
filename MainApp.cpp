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
    if(argc > 1)
        cout << argv[1]<<endl;

    //SetAppDisplayName("iPoorTunez");
    MainFrame * mainFrame=new MainFrame("iPoorTunes",wxPoint(50,50),wxSize(1024,728));

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
    //TODO save settings
}