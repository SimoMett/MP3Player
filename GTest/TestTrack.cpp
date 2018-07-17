//
// Created by matteo on 24/06/18.
//

#include <memory>
#include <gtest/gtest.h>
#include "../Mp3Player.h"
#include "../Track.h"

TEST(Track,Constructor)
{
    Mp3Player::Create();
    TrackFactory trackFactory;
    shared_ptr<Track> t=trackFactory.importTrack("nome.mp3");

    ASSERT_EQ("nome.mp3",t->title);

    ASSERT_TRUE((*Mp3Player::getInstancePtr()->mainLibrary).findTrack("nome.mp3")!= nullptr);

    Mp3Player::Destroy();
}