//
// Created by matteo on 14/06/18.
//
#include "MainFrame.h"
#include <wx/grid.h>
#include <wx/splitter.h>
#include <wx/slider.h>
#include "Mp3Player.h"


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
    wxBoxSizer * mainBoxSizer=new wxBoxSizer(wxVERTICAL);

    volumeSlider=new wxSlider(this,ID_VolumeSlider,80,0,100,wxPoint(0,10),wxSize(500,25),wxSL_HORIZONTAL,wxDefaultValidator,"VolumeSlider");

    playButton=new wxButton(this,ID_PlayButton,"PlayButton");
    nextTrackButton=new wxButton(this,ID_NextTrackButton,"NextTrack");
    previousTrackButton=new wxButton(this,ID_PrevTrackButton,"PrevTrack");

    //wxListCtrl * testList=new wxListCtrl(this,wxID_ANY,wxPoint(100,100),wxSize(200,200),wxLC_REPORT);
    //testList->AppendColumn(wxString("Reed"),wxLIST_FORMAT_LEFT,50);

    //Composing boxSizer
    mainBoxSizer->AddStretchSpacer(1);
    mainBoxSizer->Add(volumeSlider,0,wxALIGN_CENTER|wxALIGN_BOTTOM);


    wxBoxSizer * buttonSizer=new wxBoxSizer(wxHORIZONTAL);//TODO Align this boxSizer

    buttonSizer->Add(previousTrackButton,0,wxALIGN_CENTER);
    buttonSizer->Add(playButton,0,wxALIGN_CENTER);
    buttonSizer->Add(nextTrackButton,0,wxALIGN_CENTER);
    mainBoxSizer->Add(buttonSizer);

    this->SetSizer(mainBoxSizer);
    //

    //Bindings
    Bind(wxEVT_MENU,&MainFrame::OnOpenFile,this, ID_Open);
    Bind(wxEVT_SLIDER,&MainFrame::OnSlider,this,ID_VolumeSlider);
    Bind(wxEVT_BUTTON,&MainFrame::OnButton1,this,ID_PlayButton);
    //TODO Bind About->Credits menù bar option
    //TODO Bind NextTrackButton
    //TODO Bind PrevTrackButton
    //


    shared_ptr<Mp3Player> player(new Mp3Player());

}

void MainFrame::OnOpenFile(wxCommandEvent& event)
{
    //TODO Import track and play it
    wxFileCtrl * fileCtrl=new wxFileCtrl(this,wxID_ANY);
    fileCtrl->SetWildcard("MP3 files (*.mp3)|*.mp3");

    cout << fileCtrl->GetPath()<<endl;

    delete fileCtrl;
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