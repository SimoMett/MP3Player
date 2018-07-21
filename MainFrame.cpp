//
// Created by matteo on 14/06/18.
//

#include "MainFrame.h"

MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr,wxID_ANY,title,pos,size), mediaCtrl(new wxMediaCtrl(this,ID_MediaCtrl))
{
    SetMinSize(wxSize(500,500));

    menuSetup();

    widgetsSetup();

    bindingsSetup();

    Mp3Player::getInstancePtr()->attachObserver(tracksListCtrl.get());
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
    Bind(wxEVT_LISTBOX_DCLICK,&MainFrame::OnAlbumSelected,this,ID_AlbumLstBox);
    Bind(wxEVT_LIST_ITEM_ACTIVATED,&MainFrame::OnTracksBoxDoubleClick,this,ID_TracksListBox);
    Bind(wxEVT_LIST_ITEM_RIGHT_CLICK,&MainFrame::OnTracksBoxRightClick,this,ID_TracksListBox);
    Bind(wxEVT_LIST_ITEM_SELECTED,&MainFrame::OnTracksBoxClick,this,ID_TracksListBox);
    Bind(wxEVT_TOGGLEBUTTON,&MainFrame::OnLoopButton,this,ID_LoopButton);
    Bind(wxEVT_MEDIA_FINISHED, &MainFrame::OnMediaFinished,this,ID_MediaCtrl);
    Bind(wxEVT_MENU,&MainFrame::OnChangeAlbumBitmap,this,ID_ChangeBitmap);
    Bind(wxEVT_TEXT_ENTER,&MainFrame::OnSearch,this,ID_TrackFinder);

    albumBitmap->Connect(ID_Bitmap,wxEVT_RIGHT_UP,wxCommandEventHandler(MainFrame::OnBitmapRightClick));

}

void MainFrame::widgetsSetup()
{
    wxBoxSizer * mainBoxSizer=new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* listsSizer;
    listsSizer = new wxBoxSizer( wxHORIZONTAL );

    playlistListBox = unique_ptr<PlaylistsListBox>(new PlaylistsListBox( this, ID_PlayLstBox));
    playlistListBox->SetMinSize( wxSize( 200,-1 ) );

    listsSizer->Add( playlistListBox.get(), 0, wxALL|wxEXPAND, 4 );

    tracksListCtrl = unique_ptr<TracksListBox>(new TracksListBox(this, ID_TracksListBox));
    listsSizer->Add( tracksListCtrl.get(), 1, wxALL|wxEXPAND, 5 );

    wxBoxSizer* albumSizer;
    albumSizer = new wxBoxSizer( wxVERTICAL );

    trackFinder = unique_ptr<wxSearchCtrl>(new wxSearchCtrl( this, ID_TrackFinder, wxEmptyString, wxDefaultPosition, wxDefaultSize,wxTE_PROCESS_ENTER));
#ifndef __WXMAC__
    trackFinder->ShowSearchButton( true );
#endif
    trackFinder->ShowCancelButton( false );
    albumSizer->Add( trackFinder.get(), 0, wxALL|wxEXPAND, 5 );

    wxBitmap bitmap(200,200);
    bitmap.LoadFile("resources/default_album.png");
    albumBitmap =unique_ptr<wxStaticBitmap>(new wxStaticBitmap( this, ID_Bitmap, bitmap, wxDefaultPosition, wxDefaultSize, 0 ));
    albumBitmap->SetMinSize( wxSize( 200,200 ) );
    albumBitmap->SetMaxSize(wxSize(200,200));

    albumSizer->Add( albumBitmap.get(), 1, wxEXPAND|wxALIGN_RIGHT|wxALL, 4 );

    albumsListBox = unique_ptr<AlbumListBox>(new AlbumListBox( this, ID_AlbumLstBox));
    albumSizer->Add( albumsListBox.get(), 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 4 );

    listsSizer->Add( albumSizer, 0, wxEXPAND|wxTOP|wxBOTTOM|wxRIGHT, 5 );

    mainBoxSizer->Add( listsSizer, 1, wxEXPAND, 5 );

    wxStaticLine * staticLine = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    mainBoxSizer->Add( staticLine, 0, wxEXPAND | wxALL, 5 );

    trackSlider = unique_ptr<TrackSlider>(new TrackSlider(this, this, ID_TrackSlider));
    mainBoxSizer->Add( trackSlider.get(), 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxBOTTOM|wxRIGHT, 5 );

    wxBoxSizer* buttonSizer;
    buttonSizer = new wxBoxSizer( wxHORIZONTAL );

    prevTrackButton = unique_ptr<wxButton>(new wxButton( this, ID_PrevTrackButton, wxT("Prev"), wxDefaultPosition, wxDefaultSize, 0 ));
    buttonSizer->Add( prevTrackButton.get(), 0, wxALL, 5 );

    playButton = unique_ptr<wxButton>(new wxButton( this, ID_PlayButton, wxT("Play"), wxDefaultPosition, wxDefaultSize, 0 ));
    buttonSizer->Add( playButton.get(), 0, wxALL, 5 );

    nextTrackButton = unique_ptr<wxButton>(new wxButton( this, ID_NextTrackButton, wxT("Next"), wxDefaultPosition, wxDefaultSize, 0 ));
    buttonSizer->Add( nextTrackButton.get(), 0, wxALL, 5 );

    loopButton = unique_ptr<wxToggleButton>(new wxToggleButton( this, ID_LoopButton, wxT("Loop"), wxDefaultPosition, wxDefaultSize, 0 ));
    buttonSizer->Add( loopButton.get(), 0, wxALL, 5 );

    buttonSizer->Add( 0, 0, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer5=new wxBoxSizer( wxVERTICAL );

    currentTrackTitle = unique_ptr<wxStaticText>(new wxStaticText( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT));
    currentTrackTitle->Wrap( -1 );
    bSizer5->Add( currentTrackTitle.get(), 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    buttonSizer->Add( bSizer5, 1, wxEXPAND, 5 );

    buttonSizer->Add( 0, 0, 1, wxEXPAND, 5 );

    volumeSlider = unique_ptr<VolumeSlider>(new VolumeSlider(Mp3Player::getInstancePtr(), this, ID_VolumeSlider,
                                                             Mp3Player::getInstancePtr()->settings.getSavedVolume(), 0, 100, wxDefaultPosition, wxSize( 150,25 ), wxSL_HORIZONTAL ));
    buttonSizer->Add( volumeSlider.get(), 0, wxTOP|wxLEFT|wxALIGN_RIGHT, 5 );


    mainBoxSizer->Add( buttonSizer, 0, wxEXPAND, 5 );

    SetSizer(mainBoxSizer);
}

void MainFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, _("Open MP3 file"), "", "", "MP3 files (*.mp3)|*.mp3", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(openFileDialog.ShowModal()==wxID_OK)
    {
        TrackFactory factory;
        string path=openFileDialog.GetPath().ToStdString();//Somehow GetPath() can fail and return null string. To investigate
        if(path.length())
        {
            shared_ptr<Track> track = shared_ptr<Track>(factory.importTrack(path));
            if(track && Mp3Player::getInstancePtr()->mainLibrary->trackAlreadyExists(track))
            {
                tracksListCtrl->playingTrackIndex=tracksListCtrl->GetItemCount()-1;
                mediaCtrl->Load(track->getDirectory());
                albumsListBox->update();
            }
            else
                wxMessageBox("Track already exists","Error");
        }
        else
            wxMessageBox("Cannot open this track","Error",wxICON_ERROR);
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

    if(Mp3Player::getInstancePtr())
        Mp3Player::getInstancePtr()->setVolume(volumeSlider->GetValue());
}

void MainFrame::PlayButton(wxCommandEvent &event)
{
    switch(mediaCtrl->GetState())
    {
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
    if(tracksListCtrl->playingTrackIndex!=-1)
    {
        tracksListCtrl->playingTrackIndex=(tracksListCtrl->playingTrackIndex+1)%tracksListCtrl->GetItemCount();
        if(tracksListCtrl->playingTrackIndex>=tracksListCtrl->GetItemCount())
            tracksListCtrl->playingTrackIndex=0;

        string name=tracksListCtrl->GetItemText(tracksListCtrl->playingTrackIndex).ToStdString();
        shared_ptr<Track> track=Mp3Player::getInstancePtr()->getSelectedList()->findTrack(name);
        if(track!= nullptr)
        {
            mediaCtrl->Stop();
            mediaCtrl->Load(track->getDirectory());
        }
    }
}

void MainFrame::OnTracksBoxClick(wxCommandEvent &event)
{
    //FIXME lines below should be uncommented when Album class is fully functional
    const Track & track=*(Mp3Player::getInstancePtr()->getSelectedList()->findTrack(tracksListCtrl->getSelectedItem()));

    /*const Bitmap & bitmap=track.album->getCoverBitmap();

    albumBitmap->SetBitmap(bitmap);*/
}

void MainFrame::OnTracksBoxDoubleClick(wxCommandEvent &event)
{
    string item=tracksListCtrl->getSelectedItem();
    shared_ptr<Track> track=Mp3Player::getInstancePtr()->getSelectedList()->findTrack(item);

    if(track)
    {
        tracksListCtrl->playingTrackIndex=Mp3Player::getInstancePtr()->getSelectedList()->findTrackIndex(item);
        mediaCtrl->Load(track->getDirectory());
    }
}

void MainFrame::OnTracksBoxRightClick(wxListEvent &event)
{
    if(event.GetIndex()>=0)
    {
        tracksListCtrl->rightclickedTrackIndex=event.GetIndex(); //save index for OnAddToPlaylistClick
        void *data= reinterpret_cast<void*>(event.GetItem().GetData());
        wxMenu* popupMenu=new wxMenu;
        popupMenu->SetClientData(data);
        popupMenu->Append(ID_AddToPlaylist,"Add to playlist...");
        popupMenu->Append(ID_RemoveFromPlaylist,"Remove from playlist");
        popupMenu->Connect(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnPopupMenuClick), nullptr, this);
        //should replace with Bind(), didn't work for some reason
        PopupMenu(popupMenu);
    }

}

void MainFrame::OnPopupMenuClick(wxCommandEvent &event)
{
    void *data=static_cast<wxMenu *>(event.GetEventObject())->GetClientData();
    switch(event.GetId()) {
        case ID_AddToPlaylist:
        {
            wxArrayString choicesArray; //creates array of Playlists to display in wxSingleChoiceDialog
            long pos=0;
            for(auto & item : Mp3Player::getInstancePtr()->playlists)
            {
                if(item->getName()=="#mainLibrary" || item->getName().substr(0,6)=="album_")
                    continue;
                else
                {
                    choicesArray.Insert(item->getName(),pos);
                    pos++;
                }
            }
            wxSingleChoiceDialog playlistDialog(this,"Please choose a playlist where to add the chosen song.","Playlist List",choicesArray);
            if(playlistDialog.ShowModal()==wxID_OK)
            {
                for(auto & item : Mp3Player::getInstancePtr()->playlists)
                {
                    if(item->getName()==playlistDialog.GetStringSelection().ToStdString())
                    {
                        auto str=tracksListCtrl->getItemPath(tracksListCtrl->rightclickedTrackIndex);
                        auto tr=new Track(str);
                        item->addTrack(unique_ptr<Track>(tr));
                        item->save();
                    }
                }

            }
            break;
        }
        case ID_RemoveFromPlaylist:
        {
            //TODO remove track from playlist
            break;
        }

    }

}
void MainFrame::PrevTrackButton(wxCommandEvent &event)
{
    if(tracksListCtrl->playingTrackIndex!=-1)
    {
        tracksListCtrl->playingTrackIndex=(tracksListCtrl->playingTrackIndex-1)%tracksListCtrl->GetItemCount();
        if(tracksListCtrl->playingTrackIndex<0)
            tracksListCtrl->playingTrackIndex=tracksListCtrl->GetItemCount()-1;

        string name=tracksListCtrl->GetItemText(tracksListCtrl->playingTrackIndex).ToStdString();
        shared_ptr<Track> track=Mp3Player::getInstancePtr()->getSelectedList()->findTrack(name);
        if(track!= nullptr)
        {
            mediaCtrl->Stop();
            mediaCtrl->Load(track->getDirectory());
        }
    }
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
    menuBar->Append(infoMenu,"&Info");

    SetMenuBar(menuBar );
    CreateStatusBar();
}

void MainFrame::OnMediaLoaded(wxCommandEvent &event)
{
    trackSlider->update(this);
    mediaCtrl->SetVolume(volumeSlider->GetValue()/100.0);
    mediaCtrl->Play();
    playButton->SetLabel("Pause");

    string label=Mp3Player::getInstancePtr()->getSelectedList()->getTrack(tracksListCtrl->playingTrackIndex).title;
    label.erase(label.find_last_of("."),label.length());
    currentTrackTitle->SetLabel(label);
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
                Mp3Player::getInstancePtr()->playlists.push_back(shared_ptr<PlayList>(list));
                list->save();
                playlistListBox->update();
                exit=true;
            }
            else
                wxMessageBox("Error: Invalid name","Error",wxICON_ERROR);
        }
        else if(result==wxID_CANCEL)
            exit=true;
    }

    delete textEntryDialog;
}

void MainFrame::OnPlaylistSelected(wxCommandEvent &event)
{
    int selectedItem=playlistListBox->GetSelection();

    if(selectedItem!=wxNOT_FOUND)
    {
        PlayList *lista;

        if(playlistListBox->GetString(selectedItem)=="Main Library")
        {
            lista=Mp3Player::getInstancePtr()->mainLibrary.get();
        }
        else
        {
            for(auto & item : Mp3Player::getInstancePtr()->playlists)
            {
                if(playlistListBox->GetString(selectedItem).ToStdString()==item->getName())
                {
                    lista= static_cast<PlayList*>(item.get());//static cast because only Playlist pointers can be d-clicked
                    break;
                }
            }
        }

        Mp3Player::getInstancePtr()->changePlaylist(lista);
    }
}

void MainFrame::OnAlbumSelected(wxCommandEvent &event)
{
    int selectedItem=albumsListBox->GetSelection();

    string selectedStr=albumsListBox->GetString(selectedItem).ToStdString();

    if(selectedItem!=wxNOT_FOUND)
    {
        Album *lista;
        for(auto & item : Mp3Player::getInstancePtr()->playlists)
        {
            if ("album_"+selectedStr == item->getName())
            {
                lista = static_cast<Album *>(item.get());


                wxImage tmpcover=lista->getCoverBitmap().ConvertToImage();
                tmpcover.Rescale(200,200);
                albumBitmap->SetBitmap(tmpcover);


                wxMessageBox("Album:\t"+selectedStr+
                             "\nArtists:\t"+lista->artists+
                            "\nYear:\t"+lista->year,"Album info");
                break;
            }
        }
        //Mp3Player::getInstancePtr()->changePlaylist(lista);
    }
}

void MainFrame::OnLoopButton(wxCommandEvent &event)
{
    Mp3Player::getInstancePtr()->mp3Looping=loopButton->GetValue();
}

void MainFrame::OnMediaFinished(wxCommandEvent &event)
{
    if(Mp3Player::getInstancePtr()->mp3Looping)
    {
        mediaCtrl->Seek(0);
        mediaCtrl->Play();
    }
}

void MainFrame::OnBitmapRightClick(wxCommandEvent &event)
{
    wxMenu * menu=new wxMenu();
    menu->Append(ID_ChangeBitmap,"Change...");
    PopupMenu(menu,wxGetMousePosition()-GetScreenPosition());
}

void MainFrame::OnChangeAlbumBitmap(wxCommandEvent &event)
{
    wxFileDialog fileDialog(this, "Change album cover", "", "", "Image files (*.png;*.jpg;*.bmp)|*.png;*.jpg;*.bmp", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(fileDialog.ShowModal()==wxID_OK)
    {
        string albumName=albumsListBox->GetStringSelection().ToStdString();

        string file=fileDialog.GetPath().ToStdString();

        for(auto & item : Mp3Player::getInstancePtr()->playlists)
        {
            if(item->getName()=="album_"+albumName)
            {
                static_cast<Album*>(item.get())->changeCoverBitmap(file);
                albumBitmap->SetBitmap(static_cast<Album*>(item.get())->getCoverBitmap());
                break;
            }
        }
    }
}

void MainFrame::OnSearch(wxCommandEvent &event)
{
    int found=Mp3Player::getInstancePtr()->find(event.GetString().ToStdString());
    if(found!=-1)
    {
        for(int i=0;i<tracksListCtrl->GetItemCount();i++)
            tracksListCtrl->SetItemState(i,0,wxLIST_STATE_SELECTED);

        tracksListCtrl->SetItemState(found,wxLIST_STATE_SELECTED,wxLIST_STATE_SELECTED);
        tracksListCtrl->playingTrackIndex=found;
        mediaCtrl->Load(Mp3Player::getInstancePtr()->getSelectedList()->getTrack(found).getDirectory());
    }
    else
        wxMessageBox("Track not found","TrackFinder",wxICON_ERROR);
}

wxIMPLEMENT_APP(MainApp);