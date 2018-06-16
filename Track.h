//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_TRACK_H
#define MP3PLAYER_TRACK_H

#include <string>

using namespace std;

class Track {

public:
    Track();

    string title;
    string artist;
    string album;
    string genre;
    //bool like;

    int getDuration();
    string & getDirectory();

private:

    int duration;
    string directory;

};


#endif //MP3PLAYER_TRACK_H
