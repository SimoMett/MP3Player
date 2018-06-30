//
// Created by matteo on 30/06/18.
//

#ifndef MP3PLAYER_PLAYLISTSLISTBOX_H
#define MP3PLAYER_PLAYLISTSLISTBOX_H

#include <wx/wx.h>

class PlaylistsListBox :public wxListBox
{
public:
    PlaylistsListBox(wxWindow *parent, wxWindowID id, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize);

    void update();

private:
    void printLists();
};


#endif //MP3PLAYER_PLAYLISTSLISTBOX_H
