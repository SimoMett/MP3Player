//
// Created by matteo on 19/06/18.
//

#include <gtest/gtest.h>
#include "../Settings.h"
#include <fstream>


TEST(Settings,DefaultConstructor)
{
    Settings * s=Settings::Istantiate();

    ifstream file ("resources/settings.xml");

    ASSERT_TRUE(file.is_open());

    if(file.is_open())
        file.close();
}

TEST(Settings,TestLoadSettings)
{

}

TEST(Settings,TestSaveSettings)
{

}
