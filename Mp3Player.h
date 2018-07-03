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
#include "Album.h"
#include "Track.h"
#include "TrackFactory.h"

using namespace std;

class Mp3Player : public Subject{

public:
    static void Create();
    static void Destroy();

    ~Mp3Player();

    PlayList mainLibrary;
    vector <PlayList*> & playlists;

    shared_ptr<Track> currentTrack;
    bool mp3Looping;

    void setVolume(float val);
    float getVolume() const {
        return volume;
    }
    void loadPlayLists();
    void savePlayLists();//maybe this is not necessary
    int find(string text);
    Track & getRandomTrackFromPlaylist(PlayList & list);

    void changePlaylist(PlayList * list);

    static Mp3Player * getInstancePtr(){
        return currentPlayer;
    }

    PlayList * getSelectedList() const
    {
        return selectedList;
    }

    int getCurrentTrackTiming() const {
        return currentTrackTiming;
    }

private:
    Mp3Player();
    static Mp3Player * currentPlayer;
    PlayList * selectedList;
    static const float defaultVolume;
    int currentTrackTiming;
    float volume;
};


#endif //MP3PLAYER_MP3PLAYER_H
