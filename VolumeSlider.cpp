//
// Created by matteo on 23/06/18.
//

#include "VolumeSlider.h"

VolumeSlider::VolumeSlider(Mp3Player *_subject, wxWindow *parent, wxWindowID id, int value, int minValue, int maxValue,
                           const wxPoint &pos, const wxSize &size, long style, const wxValidator &validator, const wxString &name) :
        Slider(_subject,parent,id,value,minValue,maxValue,pos,size,style,validator,name) {}

void VolumeSlider::update(Subject * subject)
{
    wxSlider::SetValue(Mp3Player::getInstancePtr()->getVolume());
}