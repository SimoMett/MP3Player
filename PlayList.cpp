//
// Created by matteo on 16/06/18.
//
#include <algorithm>
#include "PlayList.h"
#include "Mp3Player.h"

PlayList::PlayList(string _name) : name(_name)
{
    Mp3Player::getMp3PlayerIstancePtr()->playlists.push_back(shared_ptr<PlayList>(this));
}

PlayList::~PlayList()
{
    auto & playlistalias= Mp3Player::getMp3PlayerIstancePtr()->playlists;
    playlistalias.erase(std::remove(playlistalias.begin(),playlistalias.end(),shared_ptr<PlayList>(this)));
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
    if(index > 0)
        removeTrack(tracks[index]);
}

bool PlayList::rename(string & newName)
{
    name=newName;
}