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

    static vector<PlayList*> existingLists;

    bool addTrack(Track* track);
    bool removeTrack(Track* track);
    bool removeTrack(int index);
    bool rename(string newName);

    Track & getTrack(int index) const{
        return *(tracks[index]);
    }
    const string & getName() const{
        return name;
    }

    virtual void save();

    static bool isValidName(string name);

protected:

    string name;
    vector<Track*> tracks;

};

#endif //MP3PLAYER_PLAYLIST_H
