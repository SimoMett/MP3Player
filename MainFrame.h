//
// Created by matteo on 14/06/18.
//

#ifndef MP3PLAYER_MAINFRAME_H
#define MP3PLAYER_MAINFRAME_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include "MainApp.h"

enum
{
    ID_Open = 1
};

class MainFrame : public wxFrame {

public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    wxSlider * volumeSlider;
    wxButton * testButton;

    void OnOpenFile(wxCommandEvent& event);
    void OnSlider(wxCommandEvent & event);//Just for test
};

#endif //MP3PLAYER_MAINFRAME_H
