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
}

TEST(Settings, SaveSettings)
{
    Settings::Instantiate();

    Settings::getInstance().setSavedVolume(20);

    Settings::Instantiate();
    ASSERT_EQ(20, Settings::getInstance().getSavedVolume());
}

TEST(Settings,TestNewLoadSettings)
{
    remove("resources/settings.xml");

    Settings::Instantiate();

    ASSERT_FLOAT_EQ(100, Settings::getInstance().getSavedVolume());
}

TEST(Settings,TestLoadSettings)
{
    Settings::Instantiate();

    ASSERT_FLOAT_EQ(100, Settings::getInstance().getSavedVolume());

}