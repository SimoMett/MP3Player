//
// Created by matteo on 14/06/18.
//

#ifndef MP3PLAYER_MAINFRAME_H
#define MP3PLAYER_MAINFRAME_H

#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <wx/listctrl.h>
#include <wx/mediactrl.h>
#include "MainApp.h"
#include "TrackSlider.h"
#include "VolumeSlider.h"
#include "PlaylistsListBox.h"
#include "TracksListBox.h"
#include "Subject.h"
#include "WindowIDs.h"

class MainFrame : public wxFrame , public Subject{

public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    TrackSlider * trackSlider;
    VolumeSlider * volumeSlider;
    wxButton * playButton;
    wxButton * nextTrackButton;
    wxButton * prevTrackButton;
    wxMediaCtrl * mediaCtrl;
    wxStaticText * currentTrackTitle;
    PlaylistsListBox * playlistListBox;
    TracksListBox * tracksListCtrl;
    wxToggleButton * loopButton;
    wxStaticBitmap * albumBitmap;

    void OnOpenFile(wxCommandEvent& event);
    void OnTrackSlider(wxCommandEvent &event);
    void OnVolumeSlider(wxCommandEvent & event);
    void PlayButton(wxCommandEvent &event);
    void NextTrackButton(wxCommandEvent & event);
    void PrevTrackButton(wxCommandEvent & event);
    void OnCreditsButton(wxCommandEvent & event);
    void OnMediaLoaded(wxCommandEvent &event);
    void OnNewPlayList(wxCommandEvent & event);
    void OnPlaylistSelected(wxCommandEvent & event);
    void OnTracksBoxDoubleClick(wxCommandEvent & event);
    void OnLoopButton(wxCommandEvent & event);
    void OnMediaFinished(wxCommandEvent &event);
    void OnBitmapRightClick(wxCommandEvent & event);

private:
    void menuSetup();
    void widgetsSetup();

    void bindingsSetup();
};

#endif //MP3PLAYER_MAINFRAME_H
