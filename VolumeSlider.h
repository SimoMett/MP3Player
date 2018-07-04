//
// Created by matteo on 23/06/18.
//

#ifndef MP3PLAYER_VOLUMESLIDER_H
#define MP3PLAYER_VOLUMESLIDER_H

#include "Slider.h"

class VolumeSlider : public Slider {
public:
    VolumeSlider(Mp3Player *_subject, wxWindow *parent, wxWindowID id, int value, int minValue, int maxValue,
    const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = wxSL_HORIZONTAL,
    const wxValidator &validator = wxDefaultValidator, const wxString &name = wxSliderNameStr);

    ~VolumeSlider(){
        if(Mp3Player::getInstancePtr()!= nullptr)
            Mp3Player::getInstancePtr()->detachObserver(this);
    }

    virtual void OnValueChanged() override{};

    void update(Subject * subject) final ;
};


#endif //MP3PLAYER_VOLUMESLIDER_H
