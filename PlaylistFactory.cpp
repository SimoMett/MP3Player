//
// Created by matteo on 16/06/18.
//

#include "PlaylistFactory.h"
#include "Mp3Player.h"

PlayList* PlaylistFactory::createPlaylist(string name)
{
    PlayList * p=new PlayList(name);
    p->load();
    return p;
}