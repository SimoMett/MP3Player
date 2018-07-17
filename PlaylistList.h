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
    PlaylistList();
    ~PlaylistList();
    void addPlaylist(shared_ptr<PlayList> playlist);
    void removePlaylist(string name);
    shared_ptr<PlayList> getPlaylist(string name);
    void save();
    bool isPlayListAnAlbum(PlayList* check);

    vector<shared_ptr<PlayList>> getExistingPlaylists();
private:
    vector<shared_ptr<PlayList>> existingPlaylists;
};
#endif //MP3PLAYER_PLAYLISTLIST_H
