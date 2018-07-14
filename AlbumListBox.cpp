//
// Created by matteo on 14/07/18.
//

#include "AlbumListBox.h"

AlbumListBox::AlbumListBox(wxWindow *parent, wxWindowID id) : wxListBox(parent,id)
{
    SetMinSize(wxSize(200,-1));
}