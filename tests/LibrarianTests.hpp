#include "gtest/gtest.h"
#include "../header/Librarian.h"
#include "../src/Librarian.cpp"
//#include "../header/Shelf.h"
//#include "../src/Shelf.cpp"
//#include "../header/Item.h"
//#include "../src/Item.cpp"


TEST(LibrarianLoginTest, isLibrarianLogin) {
        Librarian tmp;
        EXPECT_EQ(true, tmp.LogIn());
}

TEST(LibrarianLogOutTest, isLibrarianLogOut) {
        Librarian tmp;
        EXPECT_EQ(false, tmp.LogOut());
}

TEST(LibrarianNetIDTest, isLibrarianIDExisted) {
        Librarian tmp;
        EXPECT_EQ(true, tmp.isNetIDExisted("zliu001"));
}

TEST(LibrarianPasswordTest, isLibrarianPasswordMatched) {
        Librarian tmp;
        EXPECT_EQ(true, tmp.isPasswordMatched("zliu001", "aa123456"));
}
