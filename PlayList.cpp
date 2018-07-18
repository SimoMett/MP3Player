//
// Created by matteo on 16/06/18.
//
#include <wx/dir.h>
#include <algorithm>
#include "PlayList.h"
#include "Mp3Player.h"

PlayList::PlayList(string _name) : AbstractPlayList(_name)
{
    if(Mp3Player::getInstancePtr())
    {
        //Mp3Player::getInstancePtr()->playlists.push_back(unique_ptr<PlayList>(this));
    }
}

PlayList::~PlayList()
{
    //Mp3Player::getInstancePtr()->playlists.erase(std::remove(Mp3Player::getInstancePtr()->playlists.begin(),Mp3Player::getInstancePtr()->playlists.end(),this));
    save();
}

bool PlayList::addTrack(shared_ptr<Track> track)
{
    bool ok = false;
    if(track)
    {
        bool found = false;
        for (auto &item: tracks)
        {
            if (item->getDirectory() == track->getDirectory())
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            tracks.push_back(track);
            ok = true;
        }
        requestUpdate();
        if (Mp3Player::getInstancePtr())
            Mp3Player::getInstancePtr()->requestUpdate();
    }
    return ok;
}

bool PlayList::removeTrack(shared_ptr<Track> track)
{
    tracks.erase(std::remove(tracks.begin(),tracks.end(),track));
    requestUpdate();
}

bool PlayList::removeTrack(int index)
{
    bool success=false;
    if(index > 0 || index > tracks.size())
    {
        removeTrack(tracks[index]);
        success=true;
    }
    return success;
}

shared_ptr<Track> PlayList::findTrack(string name) const
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

int PlayList::findTrackIndex(string name)
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

bool PlayList::rename(string newName)
{
    bool existingName=false;
    bool success=false;
    for(auto & item : Mp3Player::getInstancePtr()->playlists)
    {
        if(item->getName()==newName)
        {
            existingName= true;
            break;
        }
    }
    if(!existingName && !wxFileExists("resources/playlists/"+newName+".xml"))
    {
        if(wxFileExists("resources/playlists/"+name+".xml"))
            wxRenameFile("resources/playlists/"+name+".xml","resources/playlists/"+newName+".xml", false);

        name=newName;
        save();
        success=true;
    }
    return success;
}

void PlayList::load()
{
    if(wxFileExists("resources/playlists/"+name+".xml"))
    {
        string path="resources/playlists/"+name+".xml";
        wxXmlDocument doc;
        doc.Load(path);
        if(doc.GetRoot() && doc.GetRoot()->GetName()=="Playlist")
        {
            wxXmlNode * child=doc.GetRoot()->GetChildren();
            TrackFactory factory;
            while (child)
            {
                string track(child->GetNodeContent().ToStdString());
                if(track.length())
                {
                    auto tstr=string(child->GetNodeContent().ToStdString());
                    auto t=factory.importTrack(tstr);
                    this->addTrack(t);
                }
                child=child->GetNext();
            }
        }
    }
}

void PlayList::save()
{
    if(!wxDirExists("resources/playlists"))//if dir not exists, create it
        wxDir dir("resources/playlists");

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

    //deque<wxXmlNode*> trackNodes;
    //trackNodes.reserve(tracks.size());

    for(int i=tracks.size()-1;i>=0;i--)
    {
        wxXmlNode *trackNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "Track");
        string dir=tracks[i]->getDirectory();
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

bool PlayList::isValidName(string name)
{
    bool valid=false;

    string finalPath="resources/playlists/"+name+".xml";

    if(!wxFileExists(finalPath))
        valid=true;

    if(!name.length())
        valid=false;

    return valid;
}
bool PlayList::trackAlreadyExists(shared_ptr<Track> track)
{
    bool exists = false;
    for(auto item : tracks)
        if(track==item)
            exists = true;
    return exists;
}