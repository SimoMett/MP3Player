//
// Created by matteo on 17/07/18.
//

#include "AlbumFactory.h"

Album* AlbumFactory::createAlbum(string name)
{
    Album * a;
    for(auto & item: Mp3Player::getInstancePtr()->playlists)
    {
        if(item->getName()==name)
        {
            a= static_cast<Album*>(item.get());
            if(a!= nullptr)
                break;
        }
    }
    if(a== nullptr)
    {
        a = new Album(name);
        a->load();

        if(Mp3Player::getInstancePtr()!= nullptr)
        {
            Mp3Player::getInstancePtr()->playlists.push_back(shared_ptr<Album>(a));
        }
    }
    return a;
}