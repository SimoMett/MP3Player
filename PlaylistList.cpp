//
// Created by pippox7 on 16/07/18.
//
#include "PlaylistList.h"

PlaylistList::~PlaylistList()
{
    for(auto item : existingPlaylists)
    {
        item->save();
    }
}

void PlaylistList::addPlaylist(PlayList * list)
{
    existingPlaylists.push_back(move(shared_ptr<PlayList>(list)));
    save();
}

void PlaylistList::removePlaylist(PlayList * list)
{
    bool deleted=false;
    for(std::vector<shared_ptr<PlayList>>::iterator item; item!=existingPlaylists.end() && !deleted; item++)
    {
        if((*item).get()==list)
        {
            existingPlaylists.erase(item);
            deleted=false;
        }

    }
    //existingPlaylists.erase(remove(existingPlaylists.begin(),existingPlaylists.end(),existingPlaylists,list));
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

bool PlaylistList::isPlayListAnAlbum(PlayList *check)
{
    /*bool success = false;

    if ((shared_ptr<Album> p = dynamic_cast<shared_ptr<Album>>(check)) != nullptr)
    success = true;

    return success;*/
    return false;
}