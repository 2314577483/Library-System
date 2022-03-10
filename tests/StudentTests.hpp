#include "gtest/gtest.h"
#include "../header/Student.h"
#include "../src/Student.cpp"
#include "../header/Shelf.h"
#include "../src/Shelf.cpp"
#include "../header/Item.h"
#include "../src/Item.cpp"


TEST(IsLoginTest, isLogin) {
        Student tmp;
        EXPECT_EQ(true, tmp.LogIn());
}

TEST(IsLogOutTest, isLogOut) {
        Student tmp;
        EXPECT_EQ(false, tmp.LogOut());
}

TEST(NetIDTest, isIDExisted) {
        Student tmp;
        EXPECT_EQ(true, tmp.isNetIDExisted("wfeng002"));
}

TEST(PasswordTest, isPasswordMatched) {
        Student tmp;
        EXPECT_EQ(true, tmp.isPasswordMatched("wfeng002", "aa123456"));
}
