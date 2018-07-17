//
// Created by pippox7 on 16/07/18.
//

#ifndef MP3PLAYER_PLAYLISTLIST_H
#define MP3PLAYER_PLAYLISTLIST_H

#include <wx/wx.h>
#include <wx/dir.h>
#include "Mp3Player.h"
#include "Album.h"

using namespace std;

class PlaylistList {

public:
    PlaylistList(){};
    ~PlaylistList();
    void addPlaylist(PlayList * list);
    void removePlaylist(PlayList * list);
    shared_ptr<PlayList> getPlaylist(string name);
    void save();
    bool isPlayListAnAlbum(PlayList* check);

    vector<shared_ptr<PlayList>> & getPlaylistListRefr()
    {
        return existingPlaylists;
    }

private:
    vector<shared_ptr<PlayList>> existingPlaylists;
};
#endif //MP3PLAYER_PLAYLISTLIST_H
