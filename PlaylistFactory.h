//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_PLAYLISTFACTORY_H
#define MP3PLAYER_PLAYLISTFACTORY_H

#include "PlayList.h"


class PlaylistFactory {

public:
    PlayList * createPlaylist(string name)
    {
        return new PlayList(name);
    }

};


#endif //MP3PLAYER_PLAYLISTFACTORY_H
