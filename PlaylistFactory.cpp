//
// Created by matteo on 16/06/18.
//

#include "PlaylistFactory.h"
#include "Mp3Player.h"

PlayList* PlaylistFactory::createPlaylist(string name)
{
    PlayList * p=new PlayList(name);
    p->load();
    if(Mp3Player::getInstancePtr()!= nullptr)
    {
        Mp3Player::getInstancePtr()->playlists.push_back(shared_ptr<PlayList>(p));
    }
    return p;
}