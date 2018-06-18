//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_TRACK_H
#define MP3PLAYER_TRACK_H

class Album;

#include <string>
#include <memory>
//#include "Album.h"

using namespace std;

class Track {

public:

    Track(string path): directory(path){};

    string title;
    string artist;
    shared_ptr<Album> album;
    string genre;
    //bool like;

    int getDuration() const{
        return duration;
    }
    const string & getDirectory() const{
        return directory;
    }

private:

    int duration;
    string directory;
};


#endif //MP3PLAYER_TRACK_H
