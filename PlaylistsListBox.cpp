//
// Created by matteo on 30/06/18.
//

#include "PlaylistsListBox.h"
#include "PlayList.h"

PlaylistsListBox::PlaylistsListBox(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size) :
        wxListBox(parent,id,pos,size)
{
    printLists();
}

void PlaylistsListBox::update()
{
    wxListBox::Clear();
    printLists();
}

void PlaylistsListBox::printLists()
{
    unsigned int pos=1;
    for(auto item : PlayList::existingLists)
    {
        if(item->getName()=="#mainLibrary")
            wxListBox::Insert("Main Library",0);
        else
        {
            wxListBox::Insert(item->getName(),pos);
            pos++;
        }
    }
}
