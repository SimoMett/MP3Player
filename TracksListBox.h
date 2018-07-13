//
// Created by matteo on 01/07/18.
//

#ifndef MP3PLAYER_TRACKSLISTBOX_H
#define MP3PLAYER_TRACKSLISTBOX_H

#include <string>
#include <wx/wx.h>
#include <wx/listctrl.h>
#include "Observer.h"
#include "PlayList.h"
#include "Track.h"
#include "Album.h"

class TracksListBox : public wxListCtrl, public Observer
{
public:
    TracksListBox(wxWindow * parent,wxWindowID winid);

    virtual void update(Subject * subject);

    std::string getSelectedItem();
    std::string getItemPath(long index);

    int playingTrackIndex=-1;
    int rightclickedTrackIndex=0;
    string openedFileName;


private:
    void insertItem(long index, Track & track);
    void display();
};


#endif //MP3PLAYER_TRACKSLISTBOX_H
