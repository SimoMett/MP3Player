//
// Created by matteo on 23/06/18.
//

#ifndef MP3PLAYER_SLIDER_H
#define MP3PLAYER_SLIDER_H


#include <wx/wx.h>
#include "Observer.h"
#include "Subject.h"
#include "Mp3Player.h"

class Slider : public Observer , public wxSlider
{
public:
    Slider(Mp3Player *_subject, wxWindow *parent, wxWindowID id, int value, int minValue, int maxValue,
           const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = wxSL_HORIZONTAL,
           const wxValidator &validator = wxDefaultValidator, const wxString &name = wxSliderNameStr);

    ~Slider();

    Mp3Player *playerInstance;
};


#endif //MP3PLAYER_SLIDER_H
