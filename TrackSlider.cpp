//
// Created by matteo on 23/06/18.
//

#include "TrackSlider.h"

TrackSlider::TrackSlider(Subject *_subject, wxWindow *parent, wxWindowID id) :
        Slider(_subject,parent,id,0, 0, 100), timer(this)
{
    Bind(wxEVT_TIMER,&TrackSlider::OnTimer,this);
    timer.Start(500);
}

TrackSlider::~TrackSlider()
{
    timer.Stop();
}

void TrackSlider::update(Subject * subject)
{
    int currentTrackDuration=playerInstance->currentTrack->getDuration();
    float val=(playerInstance->getCurrentTrackTiming()/currentTrackDuration)*wxSlider::GetMax();

    wxSlider::SetValue(val);
}

void TrackSlider::OnValueChanged()
{
    cout<<wxSlider::GetValue()<<endl;
}

void TrackSlider::OnTimer(wxTimerEvent &event)
{
    //update();
}