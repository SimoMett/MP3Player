//
// Created by pippox7 on 16/07/18.
//
#include "PlaylistList.h"

PlaylistList::PlaylistList()
{
    wxArrayString playlists;
    wxDir::GetAllFiles("resources/playlists", playlists);
    for(int i=0; i<playlists.GetCount(); i++)
    {
        existingPlaylists.push_back(new PlayList(playlists[i]));

        string path="resources/playlists/"+playlists[i]+".xml";
        wxXmlDocument doc;
        doc.Load(path);
        if(doc.GetRoot() && doc.GetRoot()->GetName()=="Playlist")
        {
            wxXmlNode * child=doc.GetRoot()->GetChildren();
            TrackFactory factory;
            while (child)
            {
                string track(child->GetNodeContent().c_str());
                if(track.length())
                {
                    existingPlaylists[i]->addTrack(factory.importTrack(string(child->GetNodeContent().c_str())));
                }
                child=child->GetNext();
            }
        }
    }
}

void PlaylistList::addPlaylist(string name)
{
    existingPlaylists.push_back(new PlayList(name));
    save();
}

void PlaylistList::removePlaylist(string name)
{
    for(int i=0; i<existingPlaylists.GetCount(); i++)
    {
        if(existingPlaylists[i]->name == name)
        {
            existingPlaylists.erase(i);
            save();
        }
    }

}

shared_ptr<Playlist> PlaylistList::getPlaylist(string name)
{
    for(int i=0; i<existingPlaylists.GetCount(); i++)
    {
        if(existingPlaylists[i]->name == name)
        {
            return existingPlaylists[i];
        }
    }
    return nullptr;
}

void PlaylistList::save()
{
    for(int i=0; i<existingPlaylists.GetCount(); i++)
    {
        existingPlaylists[i]->save();
    }
}
