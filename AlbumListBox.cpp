//
// Created by matteo on 14/07/18.
//

#include "AlbumListBox.h"

AlbumListBox::AlbumListBox(wxWindow *parent, wxWindowID id) : wxListBox(parent,id)
{
    SetMinSize(wxSize(200,-1));

    printLists();
}

void AlbumListBox::update()
{
    wxListBox::Clear();
    printLists();
}

void AlbumListBox::printLists()
{
    unsigned int _pos=0;
    for(auto & item : Mp3Player::getInstancePtr()->playlists)
    {
        if(Album * list=dynamic_cast<Album*>(item.get()))
        {
            string name = list->getName();
            wxListBox::Insert(name.erase(0, string("album_").length() ), _pos);
            _pos++;
        }
    }
}