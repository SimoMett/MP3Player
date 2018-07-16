//
// Created by pippox7 on 16/07/18.
//

#ifndef MP3PLAYER_PLAYLISTLIST_H
#define MP3PLAYER_PLAYLISTLIST_H

#include "PlayList.h"
#include <wx/wx.h>

using namespace std;

class PlaylistList {

public:
    PlaylistList(); //loads playlists from resources at program init
    ~PlaylistList();
    void addPlaylist(string name);
    void removePlaylist(string name);
    shared_ptr<Playlist> getPlaylist(string name);
    void save();
    bool isPlayListAnAlbum(PlayList* check);

private:
    vector<shared_ptr<Playlist>> existingPlaylists;
};
#endif //MP3PLAYER_PLAYLISTLIST_H
