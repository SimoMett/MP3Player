//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_PLAYLIST_H
#define MP3PLAYER_PLAYLIST_H

#include <string>
#include <deque>
#include <memory>

#include "Subject.h"
#include "Track.h"

using namespace std;

class PlayList : public Subject{

public:
    explicit PlayList(string _name);
    ~PlayList();

    bool addTrack(shared_ptr<Track> track);
    bool removeTrack(shared_ptr<Track> track);
    bool removeTrack(int index);
    bool rename(string newName);
    bool trackAlreadyExists(shared_ptr<Track> track);

    Track & getTrack(int index) const{
        return *(tracks[index]);
    }

    unsigned long getTracksCount() const {
        return tracks.size();
    }

    const string & getName() const{
        return name;
    }

    shared_ptr<Track> findTrack(string name) const;
    int findTrackIndex(string name);

    virtual void save();

    static bool isValidName(string name);

    virtual void load();

protected:

    string name;
    vector<shared_ptr<Track>> tracks;
};

#endif //MP3PLAYER_PLAYLIST_H
