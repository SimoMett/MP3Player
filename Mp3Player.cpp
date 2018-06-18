//
// Created by matteo on 14/06/18.
//

#include "Mp3Player.h"

const float Mp3Player::defaultVolume=1;

Mp3Player::Mp3Player() : mainLibrary("#mainLibrary")
{
 cout << endl;
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