//
// Created by matteo on 14/06/18.
//

#ifndef MP3PLAYER_MAINAPP_H
#define MP3PLAYER_MAINAPP_H

#include <wx/wx.h>
#include "MainFrame.h"

class MainApp : public wxApp {

public:
    virtual bool OnInit() override ;
    virtual int OnExit() override ;
};

#endif //MP3PLAYER_MAINAPP_H
