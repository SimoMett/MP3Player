//
// Created by matteo on 16/06/18.
//

#include "PlaylistFactory.h"

shared_ptr<PlayList> PlaylistFactory::createPlaylist(string name)
{
    shared_ptr<PlayList> p;
    p->load();
    return p;
}