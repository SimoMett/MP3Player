//
// Created by matteo on 23/06/18.
//

#include "Slider.h"

Slider::Slider(Mp3Player * _subject, wxWindow *parent, wxWindowID id, int value, int minValue, int maxValue, const wxPoint &pos,
        const wxSize &size, long style, const wxValidator &validator, const wxString &name) :
        playerInstance(_subject), wxSlider(parent,id,value,minValue,maxValue,pos,size,style,validator,name)

{
    if(playerInstance!=nullptr)
        playerInstance->attachObserver(shared_ptr<Observer>(this));
}



Slider::~Slider()
{
    playerInstance->detachObserver(shared_ptr<Observer>(this));
}