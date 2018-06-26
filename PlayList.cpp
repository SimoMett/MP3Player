//
// Created by matteo on 16/06/18.
//
#include <algorithm>
#include "PlayList.h"
#include "Mp3Player.h"

vector<PlayList*> PlayList::existingLists;

PlayList::PlayList(string _name) : name(_name)
{
    //XXX do not append here or it will crash
    //Mp3Player::getMp3PlayerIstancePtr()->playlists.push_back(shared_ptr<PlayList>(this));
    existingLists.push_back(this);
}

PlayList::~PlayList()
{
    auto & playlistalias= Mp3Player::getMp3PlayerIstancePtr()->playlists;
    playlistalias.erase(std::remove(playlistalias.begin(),playlistalias.end(),this));

    save();
}

bool PlayList::addTrack(shared_ptr<Track> track)
{
    tracks.push_back(track);
}

bool PlayList::removeTrack(shared_ptr<Track> track)
{
    tracks.erase(std::remove(tracks.begin(),tracks.end(),track));
}

bool PlayList::removeTrack(int index)
{
    if(index > 0)
        removeTrack(tracks[index]);
}

bool PlayList::rename(string & newName)
{
    //TODO check if there are playlists with same name, in case deny rename
    //TODO if playlist is already saved (existing xml file) rename the file also
    name=newName;
}

void PlayList::save()
{
    string path="resources/playlists/"+name+".xml";
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

    vector<wxXmlNode*> trackNodes;
    trackNodes.reserve(tracks.size());

    wxXmlNode * trackNode=new wxXmlNode(root,wxXML_ELEMENT_NODE,"Track");

    for(auto item : tracks)
    {
        wxXmlNode * tmp=new wxXmlNode(wxXML_TEXT_NODE, "", item->getDirectory());
        trackNode->AddChild(tmp);
        trackNodes.push_back(tmp);
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