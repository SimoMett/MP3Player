//
// Created by matteo on 14/07/18.
//

#ifndef MP3PLAYER_ALBUMLISTBOX_H
#define MP3PLAYER_ALBUMLISTBOX_H

#include <wx/listbox.h>
#include "Mp3Player.h"

class AlbumListBox : public wxListBox
{
public:
    AlbumListBox(wxWindow *parent, wxWindowID id);

    void update();

private:
    void printLists();
};


#endif //MP3PLAYER_ALBUMLISTBOX_H
