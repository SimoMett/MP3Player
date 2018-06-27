//
// Created by matteo on 24/06/18.
//

#include <gtest/gtest.h>
#include "../Mp3Player.h"
#include "../Track.h"

TEST(Track,Constructor)
{
    Mp3Player::Create();
    Track t("directory/nome.mp3");

    ASSERT_EQ("nome.mp3",t.title);


}
