//
// Created by matteo on 14/07/18.
//

#include <gtest/gtest.h>
#include <wx/file.h>
#include "../Album.h"

TEST(Album,saveAlbum)
{
    Album album("album_album1");

    album.save();

    ASSERT_TRUE(wxFileExists("resources/playlists/album_album1.xml"));
}

TEST(Album, getcover)
{
    Album album("album_album1","resources/default_album.png");

    ASSERT_TRUE(album.getCoverBitmap().getDirectory()=="resources/default_album.png");
}