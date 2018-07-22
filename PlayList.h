//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_PLAYLIST_H
#define MP3PLAYER_PLAYLIST_H

#include <string>
#include <deque>
#include <memory>

#include "AbstractPlayList.h"
#include "Subject.h"
#include "Track.h"

using namespace std;

class PlayList : public AbstractPlayList, public Subject{

public:
    explicit PlayList(string _name);
    ~PlayList();

    virtual bool addTrack(shared_ptr<Track> track) override ;
    virtual bool removeTrack(shared_ptr<Track> track) override ;
    bool rename(string newName);
    bool trackAlreadyExists(shared_ptr<Track> track);

    virtual shared_ptr<Track> findTrack(string name) const override ;
    virtual int findTrackIndex(string name) const override ;

    virtual void save() override ;

    static bool isValidName(string name);

    virtual void load();
};

#endif //MP3PLAYER_PLAYLIST_H
