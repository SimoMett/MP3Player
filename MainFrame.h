//
// Created by matteo on 14/06/18.
//

#ifndef MP3PLAYER_MAINFRAME_H
#define MP3PLAYER_MAINFRAME_H

#include <wx/wx.h>
#include "MainApp.h"

class MainFrame : public wxFrame {

public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
};

#endif //MP3PLAYER_MAINFRAME_H
