//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_PLAYLIST_H
#define MP3PLAYER_PLAYLIST_H

#include <string>
#include <vector>
#include <memory>

#include "Track.h"

using namespace std;

class PlayList {

public:
    PlayList();


protected:

    string name;
    vector<shared_ptr<Track>> tracks;

};


#endif //MP3PLAYER_PLAYLIST_H
