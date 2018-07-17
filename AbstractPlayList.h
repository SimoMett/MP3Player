//
// Created by matteo on 17/07/18.
//

#ifndef MP3PLAYER_ABSTRACTPLAYLIST_H
#define MP3PLAYER_ABSTRACTPLAYLIST_H

#include <string>
#include <vector>
#include "Track.h"

using namespace std;

class AbstractPlayList
{
public:
    explicit AbstractPlayList(string _name): name(_name){};
    virtual ~AbstractPlayList(){};

    virtual bool addTrack(shared_ptr<Track> track)=0;

    unsigned long getTracksCount() const {
        return tracks.size();
    }

    Track & getTrack(int index) const{
        return *(tracks[index]);
    }

    const string & getName() const{
        return name;
    }

    virtual void save()=0;

protected:

    string name;
    vector<shared_ptr<Track>> tracks;
};


#endif //MP3PLAYER_ABSTRACTPLAYLIST_H
