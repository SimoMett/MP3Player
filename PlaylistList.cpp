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
        string path="resources/playlists/"+existingPlaylists[i]->name+".xml";
        wxXmlDocument doc;

        if(!wxFileExists(path))
        {
            std::ofstream outfile (path);
            outfile.close();
        }
        else
            doc.Load(path);

        doc.SetVersion("1.0");
        doc.SetFileEncoding("UTF-8");

        wxXmlNode * root=new wxXmlNode(nullptr,wxXML_ELEMENT_NODE,"Playlist");
        doc.SetRoot(root);

        for(int j=existingPlaylists[i]->tracks.size()-1;i>=0;i--)
        {
            wxXmlNode *trackNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "Track");
            string dir=existingPlaylists[i]->tracks[j]->getDirectory();
            wxXmlNode *tmp = new wxXmlNode(wxXML_TEXT_NODE, "", dir);
            trackNode->AddChild(tmp);
        }

        wxStringOutputStream stream;
        doc.Save(stream);

        wxFile file(path,wxFile::OpenMode::write);
        if(file.IsOpened())
        {
            file.Write(stream.GetString());
            file.Close();
        }
    }
}
