//
// Created by matteo on 14/06/18.
//
#include <memory>
#include <wx/splash.h>

#include "MainApp.h"
#include "MainFrame.h"

bool MainApp::OnInit()
{
    SetAppDisplayName("iPoorTunez");
    std::unique_ptr<MainFrame> mainFrame(new MainFrame("iPoorTunes",wxPoint(50,50),wxSize(1024,728)));
    if(mainFrame)
    {
        wxBitmap bitmap("splash_screen.png",wxBITMAP_TYPE_PNG);
        std::cout<<"test"<<std::endl;
        wxSplashScreen splash(bitmap,wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,2000,nullptr,-1);
        wxYield();
        wxMilliSleep(2000);
        mainFrame->Show(true);
    }
    return mainFrame!= nullptr;
}