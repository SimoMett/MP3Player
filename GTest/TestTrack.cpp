//
// Created by matteo on 24/06/18.
//

#include <gtest/gtest.h>
#include "../Track.h"

TEST(Track,Constructor)
{
    Track t("directory/nome.mp3");

    ASSERT_EQ("nome.mp3",t.title);
}
