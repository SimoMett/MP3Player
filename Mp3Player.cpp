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

Mp3Player::~Mp3Player()
{
    /*if(Settings::getIstance()!= nullptr)
        Settings::getIstance()->SaveSettings();*/
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
    currentTrackTiming=seconds;
    requestUpdate();
}