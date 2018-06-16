//
// Created by matteo on 15/06/18.
//

#ifndef MP3PLAYER_APPEVENTHANDLER_H
#define MP3PLAYER_APPEVENTHANDLER_H

#include <wx/wx.h>

enum
{
    ID_Hello = 2
};


class AppEventHandler : public wxEvtHandler{

public:
wxDECLARE_EVENT_TABLE();

private:
    void OnHello(wxCommandEvent& event);

};


#endif //MP3PLAYER_APPEVENTHANDLER_H
