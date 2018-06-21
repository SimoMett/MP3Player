//
// Created by matteo on 14/06/18.
//
#include "MainFrame.h"


MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr,wxID_ANY,title,pos,size)
{
    //Menù Bar
    wxMenu * fileMenu=new wxMenu;
    fileMenu->Append(ID_Open,"&Open", "Open a track");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( fileMenu, "&File" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    //

    //Widgets

    volumeSlider=new wxSlider(this,wxID_ANY,90,0,100,wxPoint(0,10),wxSize(1000,1000),wxSL_HORIZONTAL,wxDefaultValidator,"VolumeSlider");
    //testButton=new wxButton(this,wxID_ANY,"TestButton",wxPoint(100,100));
    wxListCtrl * testList=new wxListCtrl(this,wxID_ANY,wxPoint(100,100),wxSize(100,100),wxLC_REPORT);
    testList->AppendColumn(wxString("Heed"),wxLIST_FORMAT_LEFT,10);
    //

    //Bindings
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