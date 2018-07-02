//
// Created by matteo on 23/06/18.
//

#ifndef MP3PLAYER_TRACKSLIDER_H
#define MP3PLAYER_TRACKSLIDER_H

#include <wx/timer.h>
#include "Slider.h"

class TrackSlider : public Slider {
public:
    TrackSlider(Subject *_subject, wxWindow *parent, wxWindowID id);
    ~TrackSlider();

    void update(Subject * subject) final ;

    virtual void OnValueChanged() override ;

private:

    wxTimer timer;
    void OnTimer(wxTimerEvent & event);
};


#endif //MP3PLAYER_TRACKSLIDER_H
