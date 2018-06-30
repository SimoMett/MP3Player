//
// Created by matteo on 14/06/18.
//

#include "MainFrame.h"
#include <wx/grid.h>
#include <wx/splitter.h>
#include <wx/slider.h>
#include <wx/statline.h>
#include "Mp3Player.h"
#include "Slider.h"
#include "PlaylistFactory.h"

MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr,wxID_ANY,title,pos,size), mediaCtrl(new wxMediaCtrl(this,ID_MediaCtrl))
{
    SetMinSize(wxSize(430,320));

    menuSetup();

    widgetsSetup();

    bindingsSetup();

    mediaCtrl->Load("resources/test.mp3");//Just for testing wxMediaCtrl
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
    Bind(wxEVT_MEDIA_LOADED, &MainFrame::OnMediaLoaded,this,ID_MediaCtrl);
    Bind(wxEVT_MENU,&MainFrame::OnNewPlayList,this,ID_NewPlayLst);
}

void MainFrame::widgetsSetup()
{
    wxBoxSizer * mainBoxSizer=new wxBoxSizer( wxVERTICAL );
    //TODO rename those bSizer1-2-3... in something more appropriate
    wxBoxSizer* bSizer2;
    bSizer2 = new wxBoxSizer( wxHORIZONTAL );

    playlistListBox = new PlaylistsListBox( this, wxID_ANY);
    playlistListBox->SetMinSize( wxSize( 200,-1 ) );

    bSizer2->Add( playlistListBox, 0, wxALL|wxEXPAND, 4 );

    wxListCtrl * tracksListCtrl = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
    tracksListCtrl->AppendColumn("Name");
    bSizer2->Add( tracksListCtrl, 1, wxALL|wxEXPAND, 5 );

    //just for test
    for(int i=0;i<15;i++)
    {
        tracksListCtrl->InsertItem(i,"track.mp3");
    }

    wxBoxSizer* bSizer3;
    bSizer3 = new wxBoxSizer( wxVERTICAL );

    wxBitmap bitmap(200,200);
    bitmap.LoadFile("resources/default_album.png");
    wxStaticBitmap * staticBitmap = new wxStaticBitmap( this, wxID_ANY, bitmap, wxDefaultPosition, wxDefaultSize, 0 );
    staticBitmap->SetMinSize( wxSize( 200,200 ) );

    bSizer3->Add( staticBitmap, 1, wxEXPAND|wxALIGN_RIGHT|wxALL, 4 );

    wxListBox * albumsListBox = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
    albumsListBox->SetMinSize(wxSize(200,-1));
    bSizer3->Add( albumsListBox, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 4 );


    bSizer2->Add( bSizer3, 0, wxEXPAND|wxTOP|wxBOTTOM|wxRIGHT, 5 );


    mainBoxSizer->Add( bSizer2, 1, wxEXPAND, 5 );

    wxStaticLine * staticLine = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    mainBoxSizer->Add( staticLine, 0, wxEXPAND | wxALL, 5 );

    trackSlider = new TrackSlider(Mp3Player::getInstancePtr(), this, ID_TrackSlider, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
    mainBoxSizer->Add( trackSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxBOTTOM|wxRIGHT, 5 );

    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer( wxHORIZONTAL );

    previousTrackButton = new wxButton( this, ID_PrevTrackButton, wxT("Prev"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer4->Add( previousTrackButton, 0, wxALL, 5 );

    playButton = new wxButton( this, ID_PlayButton, wxT("PlayPause"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer4->Add( playButton, 0, wxALL, 5 );

    nextTrackButton = new wxButton( this, ID_NextTrackButton, wxT("Next"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer4->Add( nextTrackButton, 0, wxALL, 5 );


    bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

    volumeSlider = new VolumeSlider(Mp3Player::getInstancePtr(), this, ID_VolumeSlider, 50, 0, 100, wxDefaultPosition, wxSize( 150,25 ), wxSL_HORIZONTAL );
    bSizer4->Add( volumeSlider, 0, wxTOP|wxLEFT|wxALIGN_RIGHT, 5 );


    mainBoxSizer->Add( bSizer4, 0, wxEXPAND, 5 );

    SetSizer(mainBoxSizer);
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

void MainFrame::OnTrackSlider(wxCommandEvent &event)
{
    unsigned long val=float(trackSlider->GetValue()) / trackSlider->GetMax() * mediaCtrl->Length();

    mediaCtrl->Seek(val);
}

void MainFrame::OnVolumeSlider(wxCommandEvent &event)
{
    mediaCtrl->SetVolume(volumeSlider->GetValue()/100.0);
}

void MainFrame::PlayButton(wxCommandEvent &event)
{
    switch(mediaCtrl->GetState())
    {
        case wxMEDIASTATE_STOPPED:
        {
            //TODO select a track (first track on mainLibrary)
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

void MainFrame::OnMediaLoaded(wxCommandEvent &event)
{
    //cout << "Loaded "<<mediaCtrl->GetName()<<endl;
    //cout << "Duration : "<<mediaCtrl->Length()/1000<<" Seconds"<<endl;
    //mediaCtrl->Play();
    mediaCtrl->SetVolume(volumeSlider->GetValue()/100.0);
}

void MainFrame::OnNewPlayList(wxCommandEvent &event)
{
    wxTextEntryDialog *textEntryDialog=new wxTextEntryDialog(this,"Name of new playlist","New Playlist");
    int result=textEntryDialog->ShowModal();

    if(result==wxID_OK)
    {
        string name(textEntryDialog->GetValue().c_str());

        //TODO properly check if in the "name" string there aren't any bad characters such as "/ | \"
        /*wxString wxname(textEntryDialog->GetValue());
        wxTextValidator validator(wxFILTER_NONE,&wxname);*/

        if(PlayList::isValidName(name))
        {
            PlaylistFactory factory;
            PlayList * list=factory.createPlaylist(name);
            list->save();
            //Just for test
            playListsBox->Append(name);
            //TODO append playlist to listBox (can be done in PlayList constructor? or in the factory?)
            //playlistListBox->update();//crash
        }
    }

    delete textEntryDialog;
}
#ifndef USE_NEW_GUI
void MainFrame::playlistBoxSetup()
{
    wxBoxSizer * panel=new wxBoxSizer(wxVERTICAL);
    //wxScrolled
    //wxScrollBar * bar=new wxScrollBar(this,wxID_ANY,wxDefaultPosition,wxSize(0,400),wxVERTICAL);

    playListsBox=new wxListBox(this,wxID_ANY,wxDefaultPosition,wxSize(200,300));
    //wxSize siz=GetSize();
    //panel->Add(playListsBox);
    //playListsBox->SetSize(200,siz.y);
    //TODO this listBox should resize when main frame resize

    //panel->Add(playListsBox,wxEXPAND);
    //panel->SetMinSize(430,320);
    panel->Add(playListsBox,1,wxVERTICAL);

    //SetSizerAndFit(panel);
}
#endif

wxIMPLEMENT_APP(MainApp);