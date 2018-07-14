//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_ALBUM_H
#define MP3PLAYER_ALBUM_H

#include <wx/wx.h>
#include <wx/xml/xml.h>
#include <wx/sstream.h>
#include <wx/file.h>
#include "PlayList.h"
#include "TrackFactory.h"
#include "Bitmap.h"

using namespace std;

class Album : public PlayList
{

public:

    Album(string _name, string cover);
    virtual ~Album() override ;

    string artists;
    string date;

    const Bitmap & getCoverBitmap() const{
        return *coverBitmap;
    }

    virtual void save() override ;

private:

    unique_ptr<Bitmap> coverBitmap;
    virtual void load() override ;
    bool isCoverValid(string dir);

};


#endif //MP3PLAYER_ALBUM_H
