//
// Created by matteo on 24/06/18.
//

#include <gtest/gtest.h>
#include "../Mp3Player.h"
#include "../PlayList.h"
#include "../PlaylistFactory.h"

TEST(PlayList,construction)
{
    Mp3Player::Create();
    PlaylistFactory f;
    PlayList * list=f.createPlaylist("lista1");

    bool ok=false;
    for(auto item : Mp3Player::getMp3PlayerIstancePtr()->playlists)
    {
        if(item->getName()=="lista1")
            ok=true;
    }

    ASSERT_EQ(ok,true);
}
