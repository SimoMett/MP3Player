//
// Created by matteo on 17/07/18.
//

#include "AlbumFactory.h"

Album* AlbumFactory::createAlbum(string name)
{
    Album * a = new Album(name);
    a->load();
    return a;
}