//
// Created by matteo on 16/06/18.
//
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Album.h"

Album::Album(string _name, string cover) : AbstractPlayList(_name), artists("Unknown"), year("2018")
{
    string dir;
    if(!isCoverValid(cover))
        dir="resources/default_album.png";
    else
        dir=cover;

    coverBitmap=unique_ptr<Bitmap>(new Bitmap(dir));
}

Album::~Album()
{
    //Album::save();
}


void Album::save()
{
    string path="resources/playlists/"+name+".xml";
    wxXmlDocument doc;

    if(!wxFileExists(path))
    {
        std::ofstream outfile (path);
        outfile.close();
    }

    doc.SetVersion("1.0");
    doc.SetFileEncoding("UTF-8");

    wxXmlNode * root=new wxXmlNode(nullptr,wxXML_ELEMENT_NODE,"Album");
    doc.SetRoot(root);

    //Saving image cover directory node
    wxXmlNode * imageNode=new wxXmlNode(root,wxXML_ELEMENT_NODE,"Cover");
    wxXmlNode *imageDirNode=new wxXmlNode(wxXML_TEXT_NODE,"",coverBitmap->getDirectory());
    imageNode->AddChild(imageDirNode);

    wxXmlNode * node2=new wxXmlNode(root,wxXML_ELEMENT_NODE,"Year");
    wxXmlNode *node3=new wxXmlNode(wxXML_TEXT_NODE,"",year);
    node2->AddChild(node3);

    wxXmlNode * node4=new wxXmlNode(root,wxXML_ELEMENT_NODE,"Artists");
    wxXmlNode *node5=new wxXmlNode(wxXML_TEXT_NODE,"",artists);
    node4->AddChild(node5);
    //

    wxStringOutputStream stream;
    doc.Save(stream);

    wxFile file(path,wxFile::OpenMode::write);
    if(file.IsOpened())
    {
        file.Write(stream.GetString());
        file.Close();
    }
}


void Album::load()
{
    if(wxFileExists("resources/playlists/album_"+name+".xml"))
    {
        string path="resources/playlists/album_"+name+".xml";
        wxXmlDocument doc;
        doc.Load(path);

        string coverDir;

        if(doc.GetRoot() && doc.GetRoot()->GetName()=="Album")
        {
            wxXmlNode * child=doc.GetRoot()->GetChildren();
            TrackFactory factory;
            while (child)
            {
                if(child->GetName()=="Cover")
                {
                    string info(child->GetNodeContent().ToStdString());
                    if(info.length())
                    {
                        coverDir=info;
                    }
                }
                if(child->GetName()=="Artists")
                {
                    string info(child->GetNodeContent().ToStdString());
                    if(info.length())
                    {
                        artists=info;
                    }
                }
                if(child->GetName()=="Year")
                {
                    string info(child->GetNodeContent().ToStdString());
                    if(info.length())
                    {
                        year=info;
                    }
                }
                child=child->GetNext();
            }
        }

        if(isCoverValid(coverDir))
        {
            coverBitmap=unique_ptr<Bitmap>(new Bitmap(coverDir));
        }
    }
}

bool Album::isCoverValid(string dir)
{
    bool ok= true;

    if(!dir.length() || wxFileExists(dir))
        ok=false;

    return ok;
}

void Album::setDate()
{
    auto t = time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y");
    year=oss.str();
}

void Album::changeCoverBitmap(string file)
{
    coverBitmap->setDirectory(file);
    save();
}

bool Album::addTrack(shared_ptr<Track> track)
{
    bool ok = false;
    if (track) {
        bool found = false;
        for (auto &item: tracks)
        {
            if (item->getDirectory() == track->getDirectory()) {
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