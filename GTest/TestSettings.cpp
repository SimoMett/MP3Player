//
// Created by matteo on 19/06/18.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../Settings.h"

TEST(Settings,DefaultConstructor)
{
    Settings * s=Settings::Istantiate();

    ifstream file ("resources/settings.xml");

    ASSERT_TRUE(file.is_open());

    if(file.is_open())
        file.close();
}

TEST(Settings,TestNewLoadSettings)
{
    remove("resources/settings.xml");

    Settings * s=Settings::Istantiate();

    ASSERT_FLOAT_EQ(100,s->getSavedVolume());

    delete s;
}

TEST(Settings,TestLoadSettings)
{
    Settings * s=Settings::Istantiate();

    ASSERT_FLOAT_EQ(100,s->getSavedVolume());

    delete s;
}



TEST(Settings, SaveSettings)
{
    Settings * s=Settings::Istantiate();

    s->setSavedVolume(20);

    delete s;

    s=Settings::Istantiate();
    ASSERT_EQ(20,s->getSavedVolume());

    delete s;
}