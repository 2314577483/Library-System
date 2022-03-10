#ifndef INC_100_PROJECT_BOOK_TEST_H
#define INC_100_PROJECT_BOOK_TEST_H

#include "gtest/gtest.h"

#include "../header/Book.h"

TEST(BookTest, canGetPublisher1) {
    Book book1;
    book1.setPublisher("A2");
    EXPECT_EQ("A2", book1.getPublisher());
}
TEST(BookTest, canGetPublisher2) {
    Book book1;
    book1.setPublisher("BBC");
    EXPECT_EQ("BBC", book1.getPublisher());
}
TEST(BookTest, canGetAuthor1) {
    Book book1;
    book1.setAuthor("SHELF1");
    EXPECT_EQ("SHELF1", book1.getAuthor());
}
TEST(BookTest, canGetAuthor2) {
    Book book1;
    book1.setAuthor("SHELF1");
    EXPECT_EQ("SHELF1", book1.getAuthor());
}


TEST(BookTest, canGetISBN) {
    Book book1;
    book1.setISBN("");
    EXPECT_EQ("", book1.getISBN());
}


TEST(BookTest, canSetISBN) {
    Book book1;
    book1.setISBN("A123");
    EXPECT_EQ("A123", book1.getISBN());
}

TEST(BookTest, canSetAuthor) {
    Book book1;
    book1.setAuthor("Allen");
    EXPECT_EQ("Allen", book1.getAuthor());
}
TEST(BookTest, canSetPublisher) {
    Book book1;
    book1.setPublisher("ADC");
    EXPECT_EQ("ADC", book1.getPublisher());
}
#endif //INC_100_PROJECT_BOOK_TEST_H
