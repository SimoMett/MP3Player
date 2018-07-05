//
// Created by matteo on 14/06/18.
//
#include <wx/dir.h>
#include "Mp3Player.h"
#include "PlaylistFactory.h"

//unique_ptr<Mp3Player> Mp3Player::currentPlayer(nullptr);
unique_ptr<Mp3Player> Mp3Player::currentPlayer(nullptr);
const unsigned int Mp3Player::defaultVolume=1;

void Mp3Player::Create()
{
    if(currentPlayer== nullptr)
    {
        currentPlayer=unique_ptr<Mp3Player>(new Mp3Player());
    }
}

Mp3Player::Mp3Player() : mainLibrary("#mainLibrary"), playlists(PlayList::existingLists), selectedList(&mainLibrary)
{
    srand(time(nullptr));
    Settings::Instantiate();
    setVolume(Settings::getInstance().getSavedVolume());
    loadPlayLists();
    requestUpdate();
}

void Mp3Player::Destroy()
{
    if(currentPlayer!= nullptr)
    {
        Settings::getInstance().setSavedVolume(currentPlayer->volume);

        Settings::Destroy();

        currentPlayer->mainLibrary.save();

        for(auto item : currentPlayer->observers)
        {
            //FIXME there is a segmentation violation here on exit
            /*if(item!= nullptr)
                delete item;*/
        }
        currentPlayer->observers.clear();
        currentPlayer= unique_ptr<Mp3Player>(nullptr);

    }
}

Mp3Player::~Mp3Player()
{

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
    PlaylistFactory factory;
    while ( cont )
    {
        //load playlist
        string name(filename.c_str());
        name.erase(name.find_last_of("."),name.length());

        if(name!="#mainLibrary")//Main library playlist is already instantiated ( and loaded by constructor)
            factory.createPlaylist(name);

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

}