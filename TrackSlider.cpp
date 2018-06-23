//
// Created by matteo on 23/06/18.
//

#include "TrackSlider.h"

TrackSlider::TrackSlider(Mp3Player *_subject, wxWindow *parent, wxWindowID id, int value, int minValue, int maxValue,
                           const wxPoint &pos, const wxSize &size, long style, const wxValidator &validator, const wxString &name) :
        Slider(_subject,parent,id,value,minValue,maxValue,pos,size,style,validator,name){}

void TrackSlider::update()
{
    int currentTrackDuration=playerInstance->currentTrack->getDuration();
    float val=(playerInstance->getCurrentTrackTiming()/currentTrackDuration)*wxSlider::GetMax();

    wxSlider::SetValue(val);
}