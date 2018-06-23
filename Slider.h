//
// Created by matteo on 23/06/18.
//

#ifndef MP3PLAYER_SLIDER_H
#define MP3PLAYER_SLIDER_H

#include "Observer.h"
#include "Subject.h"

class Slider : public Observer
{
public:
    Slider();

    //Mp3Player * playerInstance;
    Subject * subject;
    int sliderValue;

};


#endif //MP3PLAYER_SLIDER_H
