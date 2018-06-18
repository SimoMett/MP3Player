//
// Created by matteo on 18/06/18.
//

#include "TrackFactory.h"

unique_ptr<Track> TrackFactory::importTrack(string path)
{
    unique_ptr<Track> finalPtr(new Track(path));
    return finalPtr;
}
