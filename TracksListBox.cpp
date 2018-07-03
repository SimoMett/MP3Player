//
// Created by matteo on 01/07/18.
//

#include "TracksListBox.h"
#include "Mp3Player.h"

using namespace std;

TracksListBox::TracksListBox(wxWindow * parent,wxWindowID winid) : wxListCtrl(parent,winid,wxDefaultPosition, wxDefaultSize, wxLC_REPORT )
{
    AppendColumn("Name");
    AppendColumn("Artists");
    AppendColumn("Album");
    //AppendColumn("Duration");

    //Test
    /*for(int i=0;i<10;i++)
    {
        string name("track"+to_string(i));
        long item = InsertItem(i,name );
        SetItem(item, 1, "artista");
        SetItem(item, 2, "album");
        //insertItem()
    }*/
    display();
}

void TracksListBox::update(Subject *subject)
{
    if(subject==Mp3Player::getInstancePtr())
    {
        DeleteAllItems();
        display();
    }
}

void TracksListBox::display()
{
    if(Mp3Player::getInstancePtr() && Mp3Player::getInstancePtr()->getSelectedList())
    {
        const PlayList &list = *(Mp3Player::getInstancePtr()->getSelectedList());

        for (int i = 0; i < list.getTracksCount(); i++)
        {
            insertItem(i, list.getTrack(i));
            //cout << i << " | "<<list.getTrack(i).title<<endl;
        }
    }
}

void TracksListBox::insertItem(long index, Track & track)
{
    string name=track.title;
    name.erase(name.find_last_of("."),name.length());
    long item=InsertItem(index,name);
    SetItem(item,1,track.artist);
    //SetItem(item,2,track.album->getName());//later
    SetItem(item,2,"TODO SETUP ALBUM");
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