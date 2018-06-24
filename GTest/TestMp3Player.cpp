//
// Created by matteo on 24/06/18.
//

#include <gtest/gtest.h>
#include "../Mp3Player.h"

TEST(Mp3Player,Contructor)
{
    Mp3Player::Create();
    Mp3Player * p=Mp3Player::getMp3PlayerIstancePtr();
    ASSERT_EQ("#mainLibrary",p->mainLibrary.getName());
}

TEST(Mp3Player,setVolume)
{
    Mp3Player::Create();
    Mp3Player &p=*(Mp3Player::getMp3PlayerIstancePtr());
    p.setVolume(124);
    ASSERT_FLOAT_EQ(100,p.getVolume());
    p.setVolume(-2);
    ASSERT_FLOAT_EQ(100,p.getVolume());
    float normalVal=57;
    p.setVolume(normalVal);
    ASSERT_FLOAT_EQ(normalVal,p.getVolume());
}

TEST(Mp3Player,setTrackPlaypoint)
{
    Mp3Player::Create();
    Mp3Player &p=*(Mp3Player::getMp3PlayerIstancePtr());
    p.setTrackPlayPoint(20);
    ASSERT_EQ(20,p.getCurrentTrackTiming());
}
