//
// Created by matteo on 19/06/18.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../Settings.h"

TEST(Settings,DefaultConstructor)
{
    Settings::Instantiate();

    ifstream file ("resources/settings.xml");

    ASSERT_TRUE(file.is_open());

    if(file.is_open())
        file.close();

    Settings::Destroy();
}

TEST(Settings, SaveSettings)
{
    srand(time(nullptr));

    for(int i=0;i< 4 ; i++)
    {
        int val=rand()%100;
        Settings::Instantiate();

        Settings::getInstance().setSavedVolume(val);

        Settings::Destroy();

        Settings::Instantiate();

        ASSERT_EQ(val, Settings::getInstance().getSavedVolume());

        Settings::Destroy();
    }
}

TEST(Settings,TestNewLoadSettings)
{
    remove("resources/settings.xml");

    Settings::Instantiate();

    ASSERT_FLOAT_EQ(100, Settings::getInstance().getSavedVolume());

    Settings::Destroy();
}

TEST(Settings,TestLoadSettings)
{
    Settings::Instantiate();

    ASSERT_FLOAT_EQ(100, Settings::getInstance().getSavedVolume());

    Settings::Destroy();
}