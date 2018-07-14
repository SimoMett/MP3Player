//
// Created by matteo on 14/07/18.
//

#ifndef MP3PLAYER_BITMAP_H
#define MP3PLAYER_BITMAP_H

#include <wx/wx.h>

using namespace std;

class Bitmap: public wxBitmap {

public:
    Bitmap(string path);

    string getDirectory() const {
        return directory;
    }

    void setDirectory(string dir) {
        directory=dir;
    }

private:
    string directory;
};


#endif //MP3PLAYER_BITMAP_H
