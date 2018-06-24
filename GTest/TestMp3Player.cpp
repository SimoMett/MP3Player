//
// Created by matteo on 24/06/18.
//

#include <gtest/gtest.h>
#include "../Mp3Player.h"

TEST(Mp3Player,Contructor)
{
    Mp3Player * p=new Mp3Player();
    ASSERT_EQ("#mainLibrary",p->mainLibrary.getName());
}

TEST(Mp3Player,setVolume)
{
    Mp3Player p;
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
    Mp3Player p;
    p.setTrackPlayPoint(20);
    ASSERT_EQ(20,p.getCurrentTrackTiming());
}
