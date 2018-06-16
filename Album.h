//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_ALBUM_H
#define MP3PLAYER_ALBUM_H

#include <wx/wx.h>
#include "PlayList.h"

class Album : public PlayList{

public:
    Album(string _name, wxBitmap & cover): PlayList(_name), coverBitmap(cover){};

    string artists;
    string date;

    wxBitmap & getCoverBitmap() const;

private:

    wxBitmap & coverBitmap;

};


#endif //MP3PLAYER_ALBUM_H
