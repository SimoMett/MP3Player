//
// Created by matteo on 23/06/18.
//

#ifndef MP3PLAYER_TRACKSLIDER_H
#define MP3PLAYER_TRACKSLIDER_H

#include "Slider.h"

class TrackSlider : public Slider {
public:
    TrackSlider(Mp3Player *_subject, wxWindow *parent, wxWindowID id, int value, int minValue, int maxValue,
                 const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = wxSL_HORIZONTAL,
                 const wxValidator &validator = wxDefaultValidator, const wxString &name = wxSliderNameStr);

    void update(Subject * subject) final ;

    virtual void OnValueChanged() override ;
};



#endif //MP3PLAYER_TRACKSLIDER_H
