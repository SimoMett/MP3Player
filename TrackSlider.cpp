//
// Created by matteo on 23/06/18.
//

#include "TrackSlider.h"
#include "MainFrame.h"

TrackSlider::TrackSlider(Subject *_subject, wxWindow *parent, wxWindowID id) :
        Slider(_subject,parent,id,0, 0, 2000), timer(this), subject(_subject)
{
    Bind(wxEVT_TIMER,&TrackSlider::OnTimer,this);
    timer.Start(1000);
}

TrackSlider::~TrackSlider()
{
    timer.Stop();
}

void TrackSlider::update(Subject * subject)
{
    //actually this is pretty nosense. I messed up something
    if(subject==this->subject)
    {
        if(MainFrame* ptr=dynamic_cast<MainFrame*>(subject))
        {
            int val= static_cast<int>(ptr->mediaCtrl->Tell()*1.0/ptr->mediaCtrl->Length() * GetMax());

            wxSlider::SetValue(val);
        }
    }
}

void TrackSlider::OnTimer(wxTimerEvent &event)
{
    update(subject);
}