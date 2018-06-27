//
// Created by matteo on 18/06/18.
//

#include "TrackFactory.h"

Track * TrackFactory::importTrack(string path)
{
    Track* finalPtr=new Track(path);
    if(Mp3Player::getMp3PlayerIstancePtr()!= nullptr)//Append track to mainLibrary
        Mp3Player::getMp3PlayerIstancePtr()->mainLibrary.addTrack(finalPtr);
    return finalPtr;
}
