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
    Bind(wxEVT_LISTBOX_DCLICK,&MainFrame::OnPlaylistSelected,this,ID_PlayLstBox);
}

void MainFrame::widgetsSetup()
{
    wxBoxSizer * mainBoxSizer=new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* listsSizer;
    listsSizer = new wxBoxSizer( wxHORIZONTAL );

    playlistListBox = new PlaylistsListBox( this, ID_PlayLstBox);
    playlistListBox->SetMinSize( wxSize( 200,-1 ) );

    listsSizer->Add( playlistListBox, 0, wxALL|wxEXPAND, 4 );

    tracksListCtrl = new TracksListBox( this, wxID_ANY);
    listsSizer->Add( tracksListCtrl, 1, wxALL|wxEXPAND, 5 );

    wxBoxSizer* albumSizer;
    albumSizer = new wxBoxSizer( wxVERTICAL );

    wxBitmap bitmap(200,200);
    bitmap.LoadFile("resources/default_album.png");
    wxStaticBitmap * staticBitmap = new wxStaticBitmap( this, wxID_ANY, bitmap, wxDefaultPosition, wxDefaultSize, 0 );
    staticBitmap->SetMinSize( wxSize( 200,200 ) );

    albumSizer->Add( staticBitmap, 1, wxEXPAND|wxALIGN_RIGHT|wxALL, 4 );

    wxListBox * albumsListBox = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
    albumsListBox->SetMinSize(wxSize(200,-1));
    albumSizer->Add( albumsListBox, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 4 );


    listsSizer->Add( albumSizer, 0, wxEXPAND|wxTOP|wxBOTTOM|wxRIGHT, 5 );


    mainBoxSizer->Add( listsSizer, 1, wxEXPAND, 5 );

    wxStaticLine * staticLine = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    mainBoxSizer->Add( staticLine, 0, wxEXPAND | wxALL, 5 );

    trackSlider = new TrackSlider(this, this, ID_TrackSlider);
    mainBoxSizer->Add( trackSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxBOTTOM|wxRIGHT, 5 );

    wxBoxSizer* buttonSizer;
    buttonSizer = new wxBoxSizer( wxHORIZONTAL );

    prevTrackButton = new wxButton( this, ID_PrevTrackButton, wxT("Prev"), wxDefaultPosition, wxDefaultSize, 0 );
    buttonSizer->Add( prevTrackButton, 0, wxALL, 5 );

    playButton = new wxButton( this, ID_PlayButton, wxT("Play"), wxDefaultPosition, wxDefaultSize, 0 );
    buttonSizer->Add( playButton, 0, wxALL, 5 );

    nextTrackButton = new wxButton( this, ID_NextTrackButton, wxT("Next"), wxDefaultPosition, wxDefaultSize, 0 );
    buttonSizer->Add( nextTrackButton, 0, wxALL, 5 );


    buttonSizer->Add( 0, 0, 1, wxEXPAND, 5 );

    volumeSlider = new VolumeSlider(Mp3Player::getInstancePtr(), this, ID_VolumeSlider, Settings::getIstance()->getSavedVolume(), 0, 100, wxDefaultPosition, wxSize( 150,25 ), wxSL_HORIZONTAL );
    buttonSizer->Add( volumeSlider, 0, wxTOP|wxLEFT|wxALIGN_RIGHT, 5 );

    currentTrackTitle = new wxStaticText( this, ID_CurrentTrackTitle, "lastPlayedSong", wxDefaultPosition, wxDefaultSize, 0);
    //TODO change currentTrackTitle label with current playing track title or last played song title
    mainBoxSizer->Add( currentTrackTitle, 0, wxALIGN_CENTER, 5 );


    mainBoxSizer->Add( buttonSizer, 0, wxEXPAND, 5 );

    SetSizer(mainBoxSizer);
}

void MainFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, _("Open MP3 file"), "", "", "MP3 files (*.mp3)|*.mp3", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(openFileDialog.ShowModal()==wxID_OK)
    {
        mediaCtrl->Load(openFileDialog.GetPath());
        //TODO file must be added to playlist
    }
}

void MainFrame::OnTrackSlider(wxCommandEvent &event)
{
    unsigned long val=float(trackSlider->GetValue()) / trackSlider->GetMax() * mediaCtrl->Length();

    mediaCtrl->Seek(val);
}

void MainFrame::OnVolumeSlider(wxCommandEvent &event)
{
    mediaCtrl->SetVolume(volumeSlider->GetValue()/ static_cast<float>(volumeSlider->GetMax()));
}

void MainFrame::PlayButton(wxCommandEvent &event)
{
    switch(mediaCtrl->GetState())
    {
        case wxMEDIASTATE_STOPPED:
        {
            //TODO select a track (first track on mainLibrary)
            mediaCtrl->Play();
            playButton->SetLabel("Pause");
            break;
        }
        case wxMEDIASTATE_PAUSED:
        {
            mediaCtrl->Play();
            playButton->SetLabel("Pause");
            break;
        }
        case wxMEDIASTATE_PLAYING:
        {
            mediaCtrl->Pause();
            playButton->SetLabel("Play");
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
    wxMessageBox("UTunes written by:\nMatteo Simonetti\nFilippo Amidei\n\nThis application uses wxWidgets library","Credits");
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
    mediaCtrl->SetVolume(volumeSlider->GetValue()/100.0);
}

void MainFrame::OnNewPlayList(wxCommandEvent &event)
{
    wxTextEntryDialog *textEntryDialog=new wxTextEntryDialog(this,"Name of new playlist","New Playlist");

    bool exit=false;
    while(!exit)
    {
        int result=textEntryDialog->ShowModal();
        if(result==wxID_OK)
        {
            string name(textEntryDialog->GetValue().c_str());

            //TODO properly check if in the "name" string there aren't any bad characters such as "/ | \"

            if(PlayList::isValidName(name))
            {
                PlaylistFactory factory;
                PlayList * list=factory.createPlaylist(name);
                list->save();
                playlistListBox->update();
                exit=true;
            }
            else
                wxMessageBox("Error: Invalid name");
        }
        else if(result==wxID_CANCEL)
            exit=true;
    }

    delete textEntryDialog;
}

void MainFrame::OnPlaylistSelected(wxCommandEvent &event)
{
    //TODO show playlist in tracks box
}

wxIMPLEMENT_APP(MainApp);