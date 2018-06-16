//
// Created by matteo on 14/06/18.
//

#ifndef MP3PLAYER_MP3PLAYER_H
#define MP3PLAYER_MP3PLAYER_H

#include <wx/wx.h>
#include <vector>
#include <memory>
#include "Subject.h"
#include "PlayList.h"
#include "Track.h"

using namespace std;

class Mp3Player : public Subject{

public:
    Mp3Player();

    PlayList mainLibrary;
    vector <shared_ptr<PlayList>> playlists;
    float volume;

    Track & currentTrack;

};


#endif //MP3PLAYER_MP3PLAYER_H
