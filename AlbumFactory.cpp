//
// Created by matteo on 17/07/18.
//

#include "AlbumFactory.h"

Album* AlbumFactory::createAlbum(string name)
{
    Album * a=new Album(name);
    a->load();
    if(Mp3Player::getInstancePtr()!= nullptr)
    {
        Mp3Player::getInstancePtr()->playlists.push_back(shared_ptr<Album>(a));
    }
    return a;
}