//
// Created by matteo on 14/06/18.
//

#ifndef MP3PLAYER_MP3PLAYER_H
#define MP3PLAYER_MP3PLAYER_H

#include <wx/wx.h>
#include <vector>
#include <memory>
#include "Settings.h"
#include "Subject.h"
#include "PlayList.h"
class PlayList;
#include "Album.h"
#include "Track.h"
#include "TrackFactory.h"

using namespace std;

class Mp3Player : public Subject{

public:
    static void Create();
    static void Destroy();
    ~Mp3Player();

    Settings settings;
    unique_ptr<PlayList> mainLibrary;
    vector <unique_ptr<AbstractPlayList>> playlists;

    shared_ptr<Track> currentTrack;
    bool mp3Looping;

    void setVolume(unsigned int val);

    unsigned int getVolume() const {
        return volume;
    }
    void loadPlayLists();
    int find(string text);
    Track & getRandomTrackFromPlaylist(PlayList & list);

    void changePlaylist(AbstractPlayList * list);

    static Mp3Player * getInstancePtr(){
        return currentPlayer;
    }

    AbstractPlayList * getSelectedList() const {
        return selectedList;
    }

    int getCurrentTrackTiming() const {
        return currentTrackTiming;
    }

private:
    Mp3Player();
    static Mp3Player * currentPlayer;
    AbstractPlayList * selectedList;
    static const unsigned int defaultVolume;
    int currentTrackTiming;
    unsigned int volume;
};


#endif //MP3PLAYER_MP3PLAYER_H
