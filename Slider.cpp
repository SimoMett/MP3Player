//
// Created by matteo on 23/06/18.
//

#include "Slider.h"

Slider::Slider(Subject * _subject, wxWindow *parent, wxWindowID id, int value, int minValue, int maxValue, const wxPoint &pos,
        const wxSize &size, long style, const wxValidator &validator, const wxString &name) :
        wxSlider(parent,id,value,minValue,maxValue,pos,size,style,validator,name)

{
    if(Mp3Player::getInstancePtr()!=nullptr)
        Mp3Player::getInstancePtr()->attachObserver(this);
}

Slider::~Slider() {}