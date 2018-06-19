//
// Created by matteo on 14/06/18.
//

#ifndef MP3PLAYER_MAINFRAME_H
#define MP3PLAYER_MAINFRAME_H

#include <wx/wx.h>
#include "MainApp.h"

enum
{
    ID_Hello = 1
};

class MainFrame : public wxFrame {

public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    void OnHello(wxCommandEvent& event);


};

#endif //MP3PLAYER_MAINFRAME_H
