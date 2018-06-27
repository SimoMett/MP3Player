//
// Created by matteo on 14/06/18.
//
#include "MainFrame.h"
#include <wx/grid.h>
#include <wx/splitter.h>
#include <wx/slider.h>
#include "Mp3Player.h"
#include "Slider.h"

MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr,wxID_ANY,title,pos,size)
{
    SetMinSize(wxSize(430,320));

    menuSetup();

    widgetsSetup();

    bindingsSetup();
}

void MainFrame::bindingsSetup()
{
    Bind(wxEVT_MENU, &MainFrame::OnOpenFile, this, ID_Open);
    Bind(wxEVT_MENU, &MainFrame::OnCreditsButton, this, ID_Credits);
    Bind(wxEVT_SCROLL_THUMBRELEASE, &MainFrame::OnTrackSlider, this, ID_TrackSlider);
    Bind(wxEVT_SLIDER,&MainFrame::OnVolumeSlider,this,ID_VolumeSlider);
    Bind(wxEVT_BUTTON, &MainFrame::PlayButton, this, ID_PlayButton);
    Bind(wxEVT_BUTTON,&MainFrame::NextTrackButton,this,ID_NextTrackButton);
    Bind(wxEVT_BUTTON,&MainFrame::PrevTrackButton,this,ID_PrevTrackButton);
    Bind(wxEVT_MEDIA_LOADED,&MainFrame::TestPlay,this,ID_MediaCtrl);
    Bind(wxEVT_MENU,&MainFrame::OnNewPlayList,this,ID_NewPlayLst);
}

void MainFrame::widgetsSetup()
{
    wxBoxSizer * mainBoxSizer=new wxBoxSizer(wxVERTICAL);

    //Slider * newSlider=new Slider(Mp3Player::getMp3PlayerIstancePtr(),Mp3Player::getMp3PlayerIstance().getVolume());
    trackSlider =new TrackSlider(Mp3Player::getMp3PlayerIstancePtr(), this, ID_TrackSlider, 80, 0, 100, wxDefaultPosition, wxSize(600, 25), wxSL_HORIZONTAL, wxDefaultValidator, "VolumeSlider");
    volumeSlider=new VolumeSlider(Mp3Player::getMp3PlayerIstancePtr(),this,ID_VolumeSlider,100,0,100,wxDefaultPosition,wxSize(150,25));

    //TODO Buttons to be replaced with bitmap Buttons
    playButton =new wxButton(this, ID_PlayButton, "PlayPause");
    nextTrackButton =new wxButton(this, ID_NextTrackButton, "Next");
    previousTrackButton =new wxButton(this, ID_PrevTrackButton, "Previous");

    //wxListCtrl * testList=new wxListCtrl(this,wxID_ANY,wxPoint(100,100),wxSize(200,200),wxLC_REPORT);
    //testList->AppendColumn(wxString("Reed"),wxLIST_FORMAT_LEFT,50);

    //Composing boxSizer
    mainBoxSizer->AddStretchSpacer();
    mainBoxSizer->Add(trackSlider, 0, wxALIGN_CENTER | wxALIGN_BOTTOM);

    wxBoxSizer * buttonSizer=new wxBoxSizer(wxHORIZONTAL);
    buttonSizer->Add(previousTrackButton, 0, wxALIGN_CENTER);
    buttonSizer->Add(playButton, 0, wxALIGN_CENTER);
    buttonSizer->Add(nextTrackButton, 0, wxALIGN_CENTER);

    mainBoxSizer->Add(buttonSizer,0,wxALIGN_CENTER_HORIZONTAL);
    buttonSizer->AddSpacer(100);
    buttonSizer->Add(volumeSlider,0,wxALIGN_RIGHT);

    SetSizer(mainBoxSizer);

    mediaCtrl=new wxMediaCtrl(this,ID_MediaCtrl);
    mediaCtrl->Load("resources/Demons - Imagine Dragons.mp3");

    //PlayLists listbox
    wxBoxSizer * panel=new wxBoxSizer(wxVERTICAL);
    //wxScrolled
    //wxScrollBar * bar=new wxScrollBar(this,wxID_ANY,wxDefaultPosition,wxSize(0,400),wxVERTICAL);
    wxListBox * playListsBox=new wxListBox(this,wxID_ANY,wxDefaultPosition,wxSize(200,200));

    panel->Add(playListsBox,wxALIGN_LEFT);

    /*for(int i=0;i<10;i++)
    {
        playListsBox->Append(string("testo"));
    }*/
}

void MainFrame::OnOpenFile(wxCommandEvent& event)
{
    //TODO Import track and play it
    //FIXME all
    wxFileCtrl * fileCtrl=new wxFileCtrl(this,wxID_ANY);
    fileCtrl->SetWildcard("MP3 files (*.mp3)|*.mp3");

    //cout << fileCtrl->GetPath()<<endl;
    fileCtrl->Show(true);

    delete fileCtrl;
}

void MainFrame::OnTrackSlider(wxCommandEvent &event)//Just for test
{
    //Just for test
    trackSlider->OnValueChanged();
}

void MainFrame::OnVolumeSlider(wxCommandEvent &event)
{
    //volumeSlider->OnValueChanged();
    //Mp3Player::getMp3PlayerIstancePtr()->setVolume(volumeSlider->GetValue());
    //cout << "Volume : "<<Mp3Player::getMp3PlayerIstance().getVolume()<<endl;
}

void MainFrame::PlayButton(wxCommandEvent &event)
{
    switch(mediaCtrl->GetState())
    {
        case wxMEDIASTATE_STOPPED:
        {
            //TODO select a track
            mediaCtrl->Play();
            break;
        }
        case wxMEDIASTATE_PAUSED:
        {
            mediaCtrl->Play();
            break;
        }
        case wxMEDIASTATE_PLAYING:
        {
            mediaCtrl->Pause();
            break;
        }
    }
}

void MainFrame::NextTrackButton(wxCommandEvent &event)
{
    //TODO
}

void MainFrame::PrevTrackButton(wxCommandEvent &event)
{
    //TODO
}

void MainFrame::OnCreditsButton(wxCommandEvent &event)
{
    wxMessageBox("Mp3Player written by:\nMatteo Simonetti\nFilippo Amidei\n\nThis application uses wxWidgets library","Credits");
}

void MainFrame::menuSetup()
{
    wxMenu * fileMenu=new wxMenu;
    fileMenu->Append(ID_Open,"&Open\tCTRL+O", "Open a track");

    wxMenu * infoMenu=new wxMenu;
    infoMenu->Append(ID_Credits,"&Credits");

    wxMenu * editMenu=new wxMenu;
    editMenu->Append(ID_NewPlayLst,"New Playlist");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( fileMenu, "&File");
    menuBar->Append(editMenu,"&Edit");
    menuBar->Append(infoMenu,"&About");
    SetMenuBar(menuBar );
    CreateStatusBar();
}

void MainFrame::TestPlay(wxCommandEvent &event)
{
    cout << "Loaded "<<mediaCtrl->GetName()<<endl;
    cout << "Duration : "<<mediaCtrl->Length()/1000<<" Seconds"<<endl;
    //mediaCtrl->Play();
    mediaCtrl->SetVolume(0.1);
}

void MainFrame::OnNewPlayList(wxCommandEvent &event)
{
    wxTextEntryDialog *textEntryDialog=new wxTextEntryDialog(this,"Name of new playlist","New Playlist");
    int result=textEntryDialog->ShowModal();
    string name(textEntryDialog->GetValue().c_str());
    if(result==wxID_OK)
    {
        if(PlayList::isValidName(name))
        {
            //TODO create playlist and append to listBox
        }
    }

    delete textEntryDialog;
}

wxIMPLEMENT_APP(MainApp);