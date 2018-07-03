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
    for(auto item : Mp3Player::getInstancePtr()->playlists)
    {
        if(item->getName()=="lista1")
            ok=true;
    }

    ASSERT_TRUE(ok);
}

TEST(PlayList, loadMainLibrary)
{
    Mp3Player::Create();
    PlayList & lib=Mp3Player::getInstancePtr()->mainLibrary;
    TrackFactory t;

    lib.addTrack(t.importTrack("direc/file.mp3"));

    Mp3Player::Destroy();

    Mp3Player::Create();

    ASSERT_TRUE(Mp3Player::getInstancePtr()->mainLibrary.findTrack("file.mp3"));
    
    Mp3Player::Destroy();
}


TEST(PlayList, newSave)
{
    remove("resources/playlists/lista.xml");

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

TEST(PlayList,rename)
{
    PlaylistFactory f;
    PlayList * list=f.createPlaylist("lista");
    list->save();

    list->rename("lista2");

    ASSERT_TRUE(wxFileExists("resources/playlists/lista2.xml"));

    remove("resources/playlists/lista2.xml");
}

TEST(PlayList, addTrackTwice)
{
    PlaylistFactory f;
    PlayList * list=f.createPlaylist("lista");
    TrackFactory t;
    list->addTrack(t.importTrack("directory/file.mp3"));
    list->addTrack(t.importTrack("directory/file.mp3"));

    int count=0;
    for(int i=0;i<list->getTracksCount();i++)
    {
        if(list->getTrack(i).title=="file");
            count++;
    }

    ASSERT_EQ(count,1);
}