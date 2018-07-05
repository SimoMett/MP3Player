//
// Created by matteo on 24/06/18.
//

#include <memory>
#include <gtest/gtest.h>
#include "../Mp3Player.h"

TEST(Mp3Player,Contructor)
{
    Mp3Player::Create();
    Mp3Player & p=*(Mp3Player::getInstancePtr());
    ASSERT_EQ("#mainLibrary",p.mainLibrary.getName());
    Mp3Player::Destroy();
}

TEST(Mp3Player,Destructor)
{
    Mp3Player::Create();

    Mp3Player::Destroy();
}

TEST(Mp3Player,setVolume)
{
    Mp3Player::Create();
    Mp3Player &p=*(Mp3Player::getInstancePtr());
    p.setVolume(124);
    ASSERT_FLOAT_EQ(100,p.getVolume());
    p.setVolume(-2);
    ASSERT_FLOAT_EQ(100,p.getVolume());
    float normalVal=57;
    p.setVolume(normalVal);
    ASSERT_FLOAT_EQ(normalVal,p.getVolume());
    Mp3Player::Destroy();
}