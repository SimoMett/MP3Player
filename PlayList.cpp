//
// Created by matteo on 16/06/18.
//
#include <algorithm>
#include "PlayList.h"

PlayList::PlayList(string _name) : name(_name)
{
    //TODO append to Mp3Player list of playlst
}

bool PlayList::addTrack(shared_ptr<Track> track)
{
    tracks.push_back(track);
}

bool PlayList::removeTrack(shared_ptr<Track> track)
{
    tracks.erase(std::remove(tracks.begin(),tracks.end(),track));
}

bool PlayList::removeTrack(int index)
{
    //TODO implement
}

bool PlayList::rename(string & newName)
{
    name=newName;
}