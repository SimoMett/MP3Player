//
// Created by pippox7 on 16/07/18.
//
#include "PlaylistList.h"

PlaylistList::PlaylistList()
{

}

PlaylistList::~PlaylistList()
{

}

void PlaylistList::addPlaylist(shared_ptr<PlayList> playlist)
{
    existingPlaylists.push_back(playlist);
}

void PlaylistList::removePlaylist(string name)
{
    for(int i=0; i<existingPlaylists.size(); i++)
    {
        if(existingPlaylists[i]->getName() == name)
        {
            existingPlaylists.erase(existingPlaylists.begin()+i);
        }
    }

}

shared_ptr<PlayList> PlaylistList::getPlaylist(string name)
{
    for(int i=0; i<existingPlaylists.size(); i++)
    {
        if(existingPlaylists[i]->getName() == name)
        {
            return existingPlaylists[i];
        }
    }
    return nullptr;
}

void PlaylistList::save()
{
    for(int i=0; i<existingPlaylists.size(); i++)
    {
        existingPlaylists[i]->save();
    }
}

bool PlaylistList::isPlayListAnAlbum(PlayList *check)   //TODO must fix
{
    /*bool success;
    Album* p = dynamic_cast<Album*>(check);
    if(p != nullptr)
        success=true;
    else
        success=false;
    delete p;
    return success;*/
}

vector<shared_ptr<PlayList>> PlaylistList::getExistingPlaylists()
{
    return existingPlaylists;
}
