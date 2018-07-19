//
// Created by matteo on 14/06/18.
//
#include <wx/dir.h>
#include "Mp3Player.h"
#include "PlaylistFactory.h"
#include "AlbumFactory.h"

Mp3Player * Mp3Player::currentPlayer=nullptr;
const unsigned int Mp3Player::defaultVolume=1;

void Mp3Player::Create()
{
    if(currentPlayer== nullptr)
    {
        currentPlayer=new Mp3Player();
        currentPlayer->loadPlayLists();
    }
}

void Mp3Player::Destroy()
{
    if(currentPlayer!= nullptr)
    {
        delete currentPlayer;
        currentPlayer= nullptr;
    }
}

Mp3Player::Mp3Player()
{
    srand(time(nullptr));
    setVolume(settings.getSavedVolume());
    requestUpdate();
}

Mp3Player::~Mp3Player()
{
    settings.setSavedVolume(currentPlayer->volume);

    for(auto item : observers)
    {
        //there is a segmentation violation here on exit (cause: destruction of a wxWidgets object)
        /*if(item!= nullptr)
            delete item;*/
    }

    mainLibrary->save();
    for(auto & item : playlists)
    {
        if(item->getName()!="#mainLibrary")
            item->save();
    }
    observers.clear();
}

void Mp3Player::setVolume(unsigned int val)
{
    if(val >100)
        val =100;
    volume=val;
    requestUpdate();
}

Track& Mp3Player::getRandomTrackFromPlaylist(PlayList &list)
{
    return list.getTrack(rand());
}

void Mp3Player::loadPlayLists()
{
    mainLibrary=shared_ptr<PlayList>(new PlayList("#mainLibrary"));

    playlists.push_back(mainLibrary);

    if(!wxFileExists("resources/playlists/#mainLibrary.xml"))
        mainLibrary->save();

    mainLibrary->load();
    selectedList=mainLibrary.get();

    //This method should check every .xml file and load (if possible) every playlist
    wxDir dir("resources/playlists");

    wxString filename;
    bool cont = dir.GetFirst(&filename);

    PlaylistFactory factory;
    while ( cont )
    {
        //load playlist
        string name(filename.c_str());
        name.erase(name.find_last_of("."), name.length());
        if(name.substr(0,6)!="album_" && name != "#mainLibrary")
        {

            auto pl = factory.createPlaylist(name);
            Mp3Player::getInstancePtr()->playlists.push_back(shared_ptr<PlayList>(pl));
        }
        //Mp3player loads only playlists
        //Album will be loaded by tracks on creation
        /*else
        {
            AlbumFactory factory;
            auto pl = factory.createAlbum(name);
            //Mp3Player::getInstancePtr()->playlists.push_back(unique_ptr<Album>(pl));//already imported
        }*/
        cont = dir.GetNext(&filename);
    }
}

void Mp3Player::changePlaylist(AbstractPlayList *list)
{
    selectedList=list;
    requestUpdate();
}

int Mp3Player::find(string text)
{
    return selectedList->findTrackIndex(text);
}