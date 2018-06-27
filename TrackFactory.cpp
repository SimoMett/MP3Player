//
// Created by matteo on 18/06/18.
//

#include "TrackFactory.h"

Track * TrackFactory::importTrack(string path)
{
    Track* finalPtr=new Track(path);

    return finalPtr;
}
