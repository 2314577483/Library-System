#ifndef INC_100_PROJECT_VIDEO_TEST_HPP
#define INC_100_PROJECT_VIDEO_TEST_HPP

#include "gtest/gtest.h"

#include "../header/Video.h"


TEST(VideoTest, canGetDuration1) {
    Video video1;
    EXPECT_EQ("", video1.getDuration());
}

TEST(VideoTest, canGetDuration2) {
    Video video1;
    video1.setDuration("60");
    EXPECT_EQ("60", video1.getDuration());
}

#endif