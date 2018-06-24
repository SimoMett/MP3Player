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
    explicit PlayList(string _name);
    ~PlayList();

    bool addTrack(shared_ptr<Track> track);
    bool removeTrack(shared_ptr<Track> track);
    bool removeTrack(int index);
    bool rename(string & newName);

    Track & getTrack(int index) const{
        return *(tracks[index]);
    }
    const string & getName() const{
        return name;
    }

protected:

    string name;
    vector<shared_ptr<Track>> tracks;

};

#endif //MP3PLAYER_PLAYLIST_H
