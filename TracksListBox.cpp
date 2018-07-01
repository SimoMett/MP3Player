//
// Created by matteo on 01/07/18.
//

#include "TracksListBox.h"

TracksListBox::TracksListBox(wxWindow * parent,wxWindowID winid) : wxListCtrl(parent,winid,wxDefaultPosition, wxDefaultSize, wxLC_REPORT )
{
    AppendColumn("Name");
    AppendColumn("Artists");
    AppendColumn("Album");
    AppendColumn("Duration");

    //Test
    long item = InsertItem(0, "track.mp3");
    SetItem(item, 1, "artista");
    SetItem(item, 2, "album");
    SetItem(item,3,"12:34");
    DeleteAllItems();
}

void TracksListBox::update(Subject *subject)
{
    DeleteAllItems();
    printTracks();
}

void TracksListBox::printTracks()
{
    //TODO Implement
}