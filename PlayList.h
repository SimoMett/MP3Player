//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_PLAYLIST_H
#define MP3PLAYER_PLAYLIST_H

#include <string>
#include <vector>
#include <memory>

#include "Subject.h"
#include "Track.h"

using namespace std;

class PlayList : public Subject{//The observer(s) will be the list-boxes

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

    unsigned long getTracksCount() const {
        return tracks.size();
    }

    const string & getName() const{
        return name;
    }

    Track * findTrack(string name) const;

    virtual void save();

    static bool isValidName(string name);

protected:

    string name;
    vector<Track*> tracks;

private:
    void load();

};

#endif //MP3PLAYER_PLAYLIST_H
