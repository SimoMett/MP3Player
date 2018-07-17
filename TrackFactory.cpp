//
// Created by matteo on 18/06/18.
//

#include "TrackFactory.h"

shared_ptr<Track> TrackFactory::importTrack(string path)
{
    shared_ptr<Track> finalPtr=nullptr;
    if(wxFileExists(path))
    {
        finalPtr=shared_ptr<Track> (new Track(path));
        if (Mp3Player::getInstancePtr() != nullptr)//Append track to mainLibrary
        {
            Mp3Player::getInstancePtr()->mainLibrary->addTrack(finalPtr);
        }
    }
    return finalPtr;
}