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
        playerInstance->detachObserver(shared_ptr<Observer>(this));
    }

    virtual void OnValueChanged() override{};

    void update() final ;
};


#endif //MP3PLAYER_VOLUMESLIDER_H
