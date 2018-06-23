//
// Created by matteo on 14/06/18.
//

#ifndef MP3PLAYER_MAINFRAME_H
#define MP3PLAYER_MAINFRAME_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include "MainApp.h"
#include "TrackSlider.h"
#include <wx/mediactrl.h>

enum
{
    ID_Open = wxID_HIGHEST+1,
    ID_TrackSlider=wxID_HIGHEST+2,
    ID_PlayButton=wxID_HIGHEST+3,
    ID_Credits=wxID_HIGHEST+4,
    ID_NextTrackButton=wxID_HIGHEST+5,
    ID_PrevTrackButton=wxID_HIGHEST+6,
    ID_VolumeSlider=wxID_HIGHEST+7,
    ID_MediaCtrl=wxID_HIGHEST+8
};

class MainFrame : public wxFrame {

public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    TrackSlider * trackSlider;
    wxButton * playButton;
    wxButton * nextTrackButton;
    wxButton * previousTrackButton;
    wxMediaCtrl * mediaCtrl;

    void OnOpenFile(wxCommandEvent& event);
    void OnSlider(wxCommandEvent & event);//Just for test
    void PlayButton(wxCommandEvent &event);
    void OnCreditsButton(wxCommandEvent & event);
    void TestPlay(wxCommandEvent & event);

private:
    void menuSetup();
    void widgetsSetup();

    void bindingsSetup();
};

#endif //MP3PLAYER_MAINFRAME_H
