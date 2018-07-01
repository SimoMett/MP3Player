//
// Created by matteo on 01/07/18.
//

#ifndef MP3PLAYER_TRACKSLISTBOX_H
#define MP3PLAYER_TRACKSLISTBOX_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include "Observer.h"

class TracksListBox : public wxListCtrl, public Observer
{
public:
    TracksListBox(wxWindow * parent,wxWindowID winid=wxID_ANY);

    virtual void update(Subject * subject);

private:
    void printTracks();
};


#endif //MP3PLAYER_TRACKSLISTBOX_H
