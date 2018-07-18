//
// Created by matteo on 16/06/18.
//

#ifndef MP3PLAYER_ALBUM_H
#define MP3PLAYER_ALBUM_H

#include <wx/wx.h>
#include <wx/xml/xml.h>
#include <wx/sstream.h>
#include <wx/file.h>
#include "AbstractPlayList.h"
#include "Subject.h"
#include "TrackFactory.h"
#include "Bitmap.h"

using namespace std;

class Album : public AbstractPlayList, public Subject
{
public:
    explicit Album(string _name, string cover="resources/default_album.png");
    ~Album();

    string artists;
    string date;

    virtual bool addTrack(shared_ptr<Track> track) override ;

    const Bitmap & getCoverBitmap() const{
        return *coverBitmap;
    }

    void changeCoverBitmap(string file);

    virtual void save();
    void load();
private:

    unique_ptr<Bitmap> coverBitmap;

    bool isCoverValid(string dir);
    void setDate();

};


#endif //MP3PLAYER_ALBUM_H
