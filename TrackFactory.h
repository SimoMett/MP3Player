//
// Created by matteo on 18/06/18.
//

#ifndef MP3PLAYER_TRACKFACTORY_H
#define MP3PLAYER_TRACKFACTORY_H

#include "Track.h"
#include <string>
#include <memory>

using namespace std;

class TrackFactory {

public:

    unique_ptr<Track> importTrack(string path);

};


#endif //MP3PLAYER_TRACKFACTORY_H
