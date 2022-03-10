#include "gtest/gtest.h"
#include "../header/Newuser.h"
#include "../src/Newuser.cpp"
#include "../header/User.h"
#include "../src/User.cpp"


TEST(IsRegisteredTest, IsRegistered) {
        Newuser user1;
        EXPECT_EQ(true, user1.isRegistered("wfeng002"));
}

TEST(IsRegisteredTest, NotRegistered) {
        Newuser user2;
        EXPECT_EQ(false, user2.isRegistered("wfeng111"));
}
