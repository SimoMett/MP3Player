//
// Created by matteo on 14/06/18.
//

#ifndef MP3PLAYER_MAINFRAME_H
#define MP3PLAYER_MAINFRAME_H

#include <memory>
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

    unique_ptr<TrackSlider> trackSlider;
    unique_ptr<VolumeSlider> volumeSlider;
    unique_ptr<wxButton> playButton;
    unique_ptr<wxButton> nextTrackButton;
    unique_ptr<wxButton> prevTrackButton;
    unique_ptr<wxMediaCtrl> mediaCtrl;
    unique_ptr<wxStaticText> currentTrackTitle;
    unique_ptr<PlaylistsListBox> playlistListBox;
    unique_ptr<TracksListBox> tracksListCtrl;
    unique_ptr<wxToggleButton> loopButton;
    unique_ptr<wxStaticBitmap> albumBitmap;

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
    void OnChangeAlbumBitmap(wxCommandEvent & event);

private:
    void menuSetup();
    void widgetsSetup();

    void bindingsSetup();
};

#endif //MP3PLAYER_MAINFRAME_H
