//
// Created by matteo on 15/06/18.
//
#include <wx/splash.h>
#include "MainApp.h"
#include "AppEventHandler.h"

wxBEGIN_EVENT_TABLE(AppEventHandler, wxEvtHandler)

                EVT_CLOSE(wxSplashScreen::OnCloseWindow)
                EVT_MENU(ID_Hello,   AppEventHandler::OnHello)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MainApp);

void AppEventHandler::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void wxSplashScreen::OnCloseWindow(wxCloseEvent &event)
{
    std::cout<<"test"<<std::endl;
}

