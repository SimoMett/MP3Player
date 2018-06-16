//
// Created by matteo on 14/06/18.
//
#include "MainFrame.h"
#include "AppEventHandler.h"


MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr,wxID_ANY,title,pos,size)
{
    wxMenu * fileMenu=new wxMenu;
    fileMenu->Append(ID_Hello,"&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    fileMenu->AppendSeparator();

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( fileMenu, "&File" );
    SetMenuBar( menuBar );
    CreateStatusBar();
}