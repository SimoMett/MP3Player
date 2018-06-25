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

    ASSERT_TRUE(ok);
}

TEST(PlayList, save)
{
    PlaylistFactory f;
    PlayList * list=f.createPlaylist("lista");
    TrackFactory t;
    list->addTrack(t.importTrack("directory/file.mp3"));
    list->save();

    ifstream file ("resources/playlists/lista.xml");

    ASSERT_TRUE(file.is_open());

    if(file.is_open())
        file.close();
}