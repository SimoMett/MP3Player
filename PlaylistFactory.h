//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_PLAYLISTFACTORY_H
#define MP3PLAYER_PLAYLISTFACTORY_H

#include "PlayList.h"

class PlaylistFactory {

public:
    shared_ptr<PlayList> createPlaylist(string name);
};


#endif //MP3PLAYER_PLAYLISTFACTORY_H
