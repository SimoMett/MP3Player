//
// Created by matteo on 14/06/18.
//
#include "MainFrame.h"


MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr,wxID_ANY,title,pos,size)
{
    wxMenu * fileMenu=new wxMenu;
    fileMenu->Append(ID_Open,"&Open", "Open a track");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( fileMenu, "&File" );
    SetMenuBar( menuBar );
    CreateStatusBar();

    volumeSlider=new wxSlider(this,wxID_ANY,40,0,100);

    Bind(wxEVT_MENU,&MainFrame::OnOpenFile,this, ID_Open);
    Bind(wxEVT_SLIDER,&MainFrame::OnSlider,this);

}

void MainFrame::OnOpenFile(wxCommandEvent& event)
{
    //TODO Import track and play it
}

void MainFrame::OnSlider(wxCommandEvent &event)//Just for test
{
    //Just for test
    std::cout << volumeSlider->GetValue()<<std::endl;
}

wxIMPLEMENT_APP(MainApp);