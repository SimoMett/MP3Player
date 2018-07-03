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
    //AppendColumn("Duration");

    //Test
    for(int i=0;i<10;i++)
    {
        string name("track"+to_string(i));
        long item = InsertItem(i,name );
        SetItem(item, 1, "artista");
        SetItem(item, 2, "album");
        //insertItem()
    }
}

void TracksListBox::update(Subject *subject)
{
    DeleteAllItems();
    display();
}

void TracksListBox::display()
{
    //TODO Implement
}

void TracksListBox::insertItem(long index, Track & track)
{
    long item=InsertItem(index,track.title);
    SetItem(item,1,track.artist);
    SetItem(item,2,track.album->getName());
    //SetItem(item,3,track.getDurationStr());
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