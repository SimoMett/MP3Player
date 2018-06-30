//
// Created by matteo on 01/07/18.
//

#ifndef MP3PLAYER_TRACKSLISTBOX_H
#define MP3PLAYER_TRACKSLISTBOX_H

#include "Observer.h"

class TracksListBox : public Observer
{
public:
    TracksListBox();

    virtual void update(Subject * subject);
};


#endif //MP3PLAYER_TRACKSLISTBOX_H
