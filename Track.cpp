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
    string content;

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
                //size is ok
                char * sizePtr=new char[4];
                size_t currentPos=pos+posCounter+1;
                currentPos+=4;//skip 4 bytes, now points to char after the tag
                mainFile.seekg(currentPos);
                mainFile.read(sizePtr,4);

                unsigned long int siz=0;

                for (int i = 0; i <4; ++i)
                    siz += sizePtr[i] << (24 - i * 8);

                siz--;

                delete [] sizePtr;

                currentPos+=4;//Skip size integer bytes
                currentPos+=2;//Skip flags short integer
                //currentPos++;//Skip null char

                mainFile.seekg(currentPos);

                //Retrieve string

                char * string1=new char[siz];
                mainFile.read(string1,siz);
                content=string(string1);

                delete [] string1;
                break;
            }
            else
                posCounter+=line.length();
        }
    }
    return content;
}

string Track::getAlbumString()
{
    return getFrameContent("TALB");
}

string Track::getArtistString()
{
    return getFrameContent("TPE1");
}