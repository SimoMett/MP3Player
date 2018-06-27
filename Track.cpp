//
// Created by matteo on 16/06/18.
//

#include "Track.h"

Track::Track(string path) : directory(path)
{
    title=path;
    title.erase(0,title.find_last_of("/")+1);
    //TODO Retrieve other infos (album name, artists, duration ...)
}
