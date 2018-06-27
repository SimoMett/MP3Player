//
// Created by matteo on 14/06/18.
//

#include "Mp3Player.h"

//unique_ptr<Mp3Player> Mp3Player::currentPlayer(nullptr);
Mp3Player * Mp3Player::currentPlayer= nullptr;
const float Mp3Player::defaultVolume=1;

void Mp3Player::Create()
{
    if(currentPlayer== nullptr)
    {
        currentPlayer=new Mp3Player();
    }
}

Mp3Player::Mp3Player() : mainLibrary("#mainLibrary"), playlists(PlayList::existingLists)
{
    srand(time(nullptr));
    Settings::Istantiate();
    setVolume(Settings::getIstance()->getSavedVolume());
    requestUpdate();
}

void Mp3Player::Destroy()
{
    if(currentPlayer!= nullptr)
    {
        currentPlayer->mainLibrary.save();

        for(auto item : currentPlayer->observers)
        {
            delete item;
        }
        currentPlayer->observers.clear();
        delete currentPlayer;
    }
}

Mp3Player::~Mp3Player()
{
    currentPlayer= nullptr;
}

void Mp3Player::setVolume(float val)
{
    if(val<0 || val >100)
        val =100;
    volume=val;
    requestUpdate();
}

Track& Mp3Player::getRandomTrackFromPlaylist(PlayList &list)
{
    return list.getTrack(rand());
}

void Mp3Player::setTrackPlayPoint(int seconds)
{
    if(seconds <0 /*|| seconds>currentTrack->getDuration()*/)//currentTrack not initialised yet
        seconds=0;

    currentTrackTiming=seconds;
    requestUpdate();
}