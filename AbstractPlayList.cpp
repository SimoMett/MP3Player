//
// Created by matteo on 17/07/18.
//

#include <algorithm>
#include "AbstractPlayList.h"

shared_ptr<Track> AbstractPlayList::findTrack(string name) const
{
    shared_ptr<Track> ptr(nullptr);
    for(auto item : tracks)
    {
        if(item->title.find(name)!=string::npos)
        {
            ptr=item;
            break;
        }
    }
    return ptr;
}

int AbstractPlayList::findTrackIndex(string name) const
{
    int index=-1;

    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    for(int i=0;i<tracks.size() && index==-1;i++)
    {
        string trackName=tracks[i]->title;
        std::transform(trackName.begin(), trackName.end(), trackName.begin(), ::tolower);
        if(trackName.find(name)!=string::npos)
        {
            index=i;
        }
    }

    return index;
}