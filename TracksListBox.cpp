//
// Created by matteo on 01/07/18.
//

#include "TracksListBox.h"

using namespace std;

TracksListBox::TracksListBox(wxWindow * parent,wxWindowID winid) : wxListCtrl(parent,winid,wxDefaultPosition, wxDefaultSize, wxLC_REPORT )
{
    AppendColumn("Name");
    AppendColumn("Artists");
    AppendColumn("Album");
    AppendColumn("Duration");

    //Test
    for(int i=0;i<10;i++)
    {
        string name("track"+to_string(i));
        long item = InsertItem(0,name );
        SetItem(item, 1, "artista");
        SetItem(item, 2, "album");
        SetItem(item,3,"12:34");
    }

    Bind(wxEVT_LIST_ITEM_ACTIVATED, &TracksListBox::OnDoubleClick,this);
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

void TracksListBox::OnDoubleClick(wxCommandEvent &event)
{
    //TODO
    //Retrieve track from the name, then
    //media control should load the selected track
}

string TracksListBox::getSelectedItem()
{
    long index = -1;

    string result;
    while ((index = GetNextItem(index,wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != wxNOT_FOUND)
    {
        result=GetItemText(index);
    }

    return result;
}