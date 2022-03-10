#ifndef __ITEM_TEST_HPP__
#define __ITEM_TEST_HPP__


#include "gtest/gtest.h"

#include "../header/Item.h"

TEST(ItemTest, canGetName1) {
    Item* book1 = new Item("b1", "2010");
    EXPECT_EQ("b1", book1->getName());
    delete book1;
}

TEST(ItemTest, canGetName2) {
    Item* book1 = new Item("a1", "2010");
    EXPECT_EQ("a1", book1->getName());
    delete book1;
}

TEST(ItemTest, canGetEmptyName) {
    Item* book1 = new Item("", "2010");
    EXPECT_EQ("", book1->getName());
    delete book1;
}

TEST(ItemTest, canGetEmptyYear) {
    Item* book1 = new Item("", "");
    EXPECT_EQ("", book1->getYear());
    delete book1;
}


TEST(ItemTest, canGetYear) {
    Item* book1 = new Item("", "2010");
    EXPECT_EQ("2010", book1->getYear());
    delete book1;
}

TEST(ItemTest, canSetContent) {
    Item* book1 = new Item("b3", "2010");
    book1->setContent("Advance Algorithm");
    EXPECT_EQ("Advance Algorithm", book1->getContent());
    delete book1;
}

TEST(ItemTest, canSetContent2) {
    Item* book1 = new Item("b3", "2010");
    book1->setContent("Advance system");
    EXPECT_EQ("Advance system", book1->getContent());
    delete book1;
}

TEST(ItemTest, canGetEmptyContent) {
    Item* book1 = new Item("b3", "2010");
    EXPECT_EQ("", book1->getContent());

    delete book1;
}

TEST(ItemTest, canSetDescription) {
    Item* book1 = new Item("b3", "2010");
    book1->setDescription("Advance Algorithm");
    EXPECT_EQ("Advance Algorithm", book1->getDescription());
    delete book1;
}


TEST(ItemTest, canSetDescription2) {
    Item* book1 = new Item("b3", "2010");
    book1->setDescription("Advance system");
    EXPECT_EQ("Advance system", book1->getDescription());
    delete book1;
}

TEST(ItemTest, canGetEmptyDescription) {
    Item* book1 = new Item("b3", "2010");
    EXPECT_EQ("", book1->getDescription());
    delete book1;
}

TEST(ItemTest, canSetAvailability) {
    Item* book1 = new Item("b3", "2010");
    book1->setAvailability("borrowed");
    EXPECT_EQ("borrowed", book1->getAvailability());
    delete book1;
}

TEST(ItemTest, canSetAvailability2) {
    Item* book1 = new Item("b3", "2010");
    book1->setAvailability("borrowed");
    EXPECT_EQ("borrowed", book1->getAvailability());
    delete book1;
}

TEST(ItemTest, canGetInitialAvailability) {
    Item* book1 = new Item("b3", "2010");
    EXPECT_EQ("Avail", book1->getAvailability());
    delete book1;
}


TEST(ItemTest, canSetAuthor) {
    Item* book1 = new Item("b3", "2010");
    book1->setAuthor("Bob");
    EXPECT_EQ("Bob", book1->getAuthor());
    delete book1;
}

TEST(ItemTest, canSetAuthor2) {
    Item* book1 = new Item("b3", "2010");
    book1->setAuthor("Andy");
    EXPECT_EQ("Andy", book1->getAuthor());
    delete book1;
}

TEST(ItemTest, canGetEmptyAuthor) {
    Item* book1 = new Item("b3", "2010");
    EXPECT_EQ("", book1->getAuthor());
    delete book1;
}


#endif
