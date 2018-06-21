//
// Created by matteo on 14/06/18.
//
#include "MainFrame.h"
#include <wx/grid.h>
#include <wx/splitter.h>
#include <wx/slider.h>


MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr,wxID_ANY,title,pos,size)
{
    this->SetMinSize(wxSize(430,320));

    //Menù Bar
    wxMenu * fileMenu=new wxMenu;
    fileMenu->Append(ID_Open,"&Open\tCTRL+O", "Open a track");

    wxMenu * infoMenu=new wxMenu;
    infoMenu->Append(ID_Credits,"&Credits");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( fileMenu, "&File" );
    menuBar->Append(infoMenu,"&About");
    SetMenuBar( menuBar );
    CreateStatusBar();
    //

    //Widgets
    wxBoxSizer * boxSizer2=new wxBoxSizer(wxVERTICAL);

    wxSize siz(100,100);
    volumeSlider=new wxSlider(this,ID_VolumeSlider,90,0,100,wxPoint(0,10),siz,wxSL_HORIZONTAL,wxDefaultValidator,"VolumeSlider");

    playButton=new wxButton(this,ID_PlayButton,"PlayButton",wxPoint(400,200));
    boxSizer2->Add(playButton,0,wxALIGN_CENTER_VERTICAL|wxALL|wxALIGN_RIGHT,5);

    this->SetSizer(boxSizer2);

    wxListCtrl * testList=new wxListCtrl(this,wxID_ANY,wxPoint(100,100),siz,wxLC_REPORT);
    testList->AppendColumn(wxString("Reed"),wxLIST_FORMAT_LEFT,50);

    //

    //Bindings
    Bind(wxEVT_MENU,&MainFrame::OnOpenFile,this, ID_Open);
    Bind(wxEVT_SLIDER,&MainFrame::OnSlider,this,ID_VolumeSlider);
    Bind(wxEVT_BUTTON,&MainFrame::OnButton1,this,ID_PlayButton);
    //TODO Bind About->Credits menù bar option

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