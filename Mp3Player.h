//
// Created by matteo on 14/06/18.
//

#ifndef MP3PLAYER_MP3PLAYER_H
#define MP3PLAYER_MP3PLAYER_H

#include <wx/wx.h>
#include <vector>
#include <memory>
#include <random>
#include "Settings.h"
#include "Subject.h"
#include "PlayList.h"
#include "Album.h"
#include "Track.h"
#include "TrackFactory.h"

using namespace std;

class Mp3Player : public Subject{

public:
    Mp3Player();

    PlayList mainLibrary;
    vector <shared_ptr<PlayList>> playlists;
    float volume;
    shared_ptr<Track> currentTrack;
    bool mp3Looping;

    void loadPlayLists();
    void savePlayLists();
    int find(string text);
    Track & getRandomTrackFromPlaylist(PlayList & list);
    void setTrackPlayPoint(int seconds);

private:
    unique_ptr<Mp3Player> currentPlayer;
    static const float defaultVolume;
    int currentTrackTiming;

};


#endif //MP3PLAYER_MP3PLAYER_H
