//
// Created by matteo on 14/06/18.
//
#include <wx/dir.h>
#include "Mp3Player.h"
#include "PlaylistFactory.h"
#include "AlbumFactory.h"

unique_ptr<Mp3Player> Mp3Player::currentPlayer(nullptr);
const unsigned int Mp3Player::defaultVolume=1;

void Mp3Player::Create()
{
    if(currentPlayer== nullptr)
    {
        currentPlayer=unique_ptr<Mp3Player>(new Mp3Player());
        currentPlayer->loadPlayLists();
    }
}

Mp3Player::Mp3Player() : settings(), mainLibrary(unique_ptr<PlayList>(new PlayList("#mainLibrary"))), selectedList(mainLibrary.get())
{
    srand(time(nullptr));
    setVolume(settings.getSavedVolume());
    requestUpdate();
}

Mp3Player::~Mp3Player()
{
    settings.setSavedVolume(currentPlayer->volume);

    mainLibrary->save();

    for(auto item : observers)
    {
        //FIXME there is a segmentation violation here on exit
        /*if(item!= nullptr)
            delete item;*/
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
    //This method should check every .xml file and load (if possible) every playlist
    wxDir dir("resources/playlists");

    wxString filename;
    bool cont = dir.GetFirst(&filename);

    while ( cont )
    {
        //load playlist
        string name(filename.c_str());
        name.erase(name.find_last_of("."), name.length());
        if(name.find("album_",0,5)==string::npos)
        {
            PlaylistFactory factory;
            auto pl = factory.createPlaylist(name);
            //Mp3Player::getInstancePtr()->playlists.push_back(unique_ptr<PlayList>(pl));
        }
        else
        {
            AlbumFactory factory;
            auto pl = factory.createAlbum(name);
            //Mp3Player::getInstancePtr()->playlists.push_back(unique_ptr<Album>(pl));
        }
        cont = dir.GetNext(&filename);
    }
}

void Mp3Player::changePlaylist(PlayList *list)
{
    selectedList=list;
    requestUpdate();
}

int Mp3Player::find(string text)
{
    return selectedList->findTrackIndex(text);
}