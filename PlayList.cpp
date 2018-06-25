//
// Created by matteo on 16/06/18.
//
#include <algorithm>
#include "PlayList.h"
#include "Mp3Player.h"

PlayList::PlayList(string _name) : name(_name)
{
    //XXX do not append here or it will crash
    //Mp3Player::getMp3PlayerIstancePtr()->playlists.push_back(shared_ptr<PlayList>(this));
    //cout << (Mp3Player::getMp3PlayerIstancePtr())<<endl;
}

PlayList::~PlayList()
{
    auto & playlistalias= Mp3Player::getMp3PlayerIstancePtr()->playlists;
    playlistalias.erase(std::remove(playlistalias.begin(),playlistalias.end(),shared_ptr<PlayList>(this)));

    save();
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
    //TODO check if there are playlists with same name, in case deny rename
    //TODO if playlist is already saved (existing xml file) rename the file also
    name=newName;
}

void PlayList::save()
{
    //TODO
}