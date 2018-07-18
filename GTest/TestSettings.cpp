//
// Created by matteo on 19/06/18.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../Settings.h"

TEST(Settings,DefaultConstructor)
{
    Settings s;

    ifstream file ("resources/settings.xml");

    ASSERT_TRUE(file.is_open());

    if(file.is_open())
        file.close();
}

TEST(Settings, SaveSettings)
{
    srand(time(nullptr));

    for(int i=0;i< 4 ; i++)
    {
        int val=rand()%100;
        Settings * s=new Settings;

        s->setSavedVolume(val);

        delete s;

        s=new Settings;

        ASSERT_EQ(val, s->getSavedVolume());

        delete s;
    }
}

TEST(Settings,TestNewLoadSettings)
{
    remove("resources/settings.xml");

    Settings s;

    ASSERT_FLOAT_EQ(100, s.getSavedVolume());
}

TEST(Settings,TestLoadSettings)
{
    Settings s;

    ASSERT_FLOAT_EQ(100, s.getSavedVolume());
}