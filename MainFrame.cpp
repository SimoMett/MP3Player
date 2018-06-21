//
// Created by matteo on 14/06/18.
//
#include "MainFrame.h"
#include <wx/grid.h>
#include <wx/splitter.h>
#include <wx/slider.h>


MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr,wxID_ANY,title,pos,size)
{
    //Menù Bar
    wxMenu * fileMenu=new wxMenu;
    fileMenu->Append(ID_Open,"&Open\tCTRL+O", "Open a track");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( fileMenu, "&File" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    //

    //Widgets

    wxSize siz(100,100);
    volumeSlider=new wxSlider(this,ID_VolumeSlider,90,0,100,wxPoint(0,10),siz,wxSL_HORIZONTAL,wxDefaultValidator,"VolumeSlider");
    volumeSlider->SetAutoLayout(true);
    testButton=new wxButton(this,ID_PlayButton,"PlayButton",wxPoint(100,200));

    wxListCtrl * testList=new wxListCtrl(this,wxID_ANY,wxPoint(100,100),siz,wxLC_REPORT);
    testList->AppendColumn(wxString("Heed"),wxLIST_FORMAT_LEFT,10);



    //

    //Bindings
    Bind(wxEVT_MENU,&MainFrame::OnOpenFile,this, ID_Open);
    Bind(wxEVT_SLIDER,&MainFrame::OnSlider,this,ID_VolumeSlider);
    Bind(wxEVT_BUTTON,&MainFrame::OnButton1,this,ID_PlayButton);

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

void MainFrame::OnButton1(wxCommandEvent &event)
{
    std::cout<< "playButton"<<std::endl;
}

wxIMPLEMENT_APP(MainApp);