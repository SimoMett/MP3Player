//
// Created by matteo on 14/06/18.
//

#ifndef MP3PLAYER_EVENTTABLE_H
#define MP3PLAYER_EVENTTABLE_H

#endif //MP3PLAYER_EVENTTABLE_H

enum
{
    ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(ID_Hello,   MainFrame::OnHello)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MainApp);