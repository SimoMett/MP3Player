//
// Created by matteo on 30/06/18.
//

#ifndef MP3PLAYER_PLAYLISTSLISTBOX_H
#define MP3PLAYER_PLAYLISTSLISTBOX_H

#include <wx/wx.h>
#include "Observer.h"

class PlaylistsListBox :public wxListBox, public Observer
{
public:
    PlaylistsListBox();

};


#endif //MP3PLAYER_PLAYLISTSLISTBOX_H
