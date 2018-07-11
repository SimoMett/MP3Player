//
// Created by matteo on 16/06/18.
//

#include "Track.h"

Track::Track(string path) : directory(path)
{
    title=path;
    title.erase(0,title.find_last_of("/")+1);
    //TODO Retrieve other infos (album name, artists, duration ...)
    artist=getArtistString();
}


//FIXME
string Track::getFrameContent(string tag)
{
    string album;

    ifstream mainFile;
    mainFile.open(directory);

    if(mainFile)
    {
        size_t posCounter=0;

        while(mainFile.good())
        {
            string line;
            getline(mainFile,line);
            size_t pos=line.find(tag);

            if(pos!=string::npos)
            {
                char * tmp=new char[4];
                size_t currentPos=pos+posCounter+1;
                currentPos+=4;//skip 4 chars
                mainFile.seekg(currentPos);
                mainFile.read(tmp,4);

                unsigned long int siz=0;

                for (int i = 0; i <4; ++i)
                    siz += tmp[i] << (24 - i * 8);

                siz--;

                delete tmp;

                mainFile.seekg(currentPos+7);//7 = 4 (size integer) + 2 (flags short integer) + 1 (null char)

                char * name=new char[siz];
                mainFile.read(name,siz);

                album= string(name);

                delete [] name;
                break;
            }
            else
                posCounter+=line.length();
        }
    }
    return album;
}

string Track::getAlbumString()
{
    return getFrameContent("TALB");
}

string Track::getArtistString()
{
    return getFrameContent("TPE1");
}