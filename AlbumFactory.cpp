//
// Created by matteo on 17/07/18.
//

#include "AlbumFactory.h"

Album* AlbumFactory::createAlbum(string name)
{
    Album * a=new Album(name);

    Mp3Player::getInstancePtr()->playlists.push_back(move(unique_ptr<Album>(a)));

    return a;
}