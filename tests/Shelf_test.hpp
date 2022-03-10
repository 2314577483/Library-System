#ifndef __Shelf_TEST_HPP__
#define __Shelf_TEST_HPP__

#include "gtest/gtest.h"


#include "../header/Item.h"
#include "../header/Shelf.h"


TEST(ShelfTest, canGetLocation1) {
    Shelf* shelf1 = new Shelf("SHELF1", "A2");
    EXPECT_EQ("A2", shelf1->getShelfLocation());
    delete shelf1;
}

TEST(ShelfTest, canGetLocation2) {
    Shelf* shelf1 = new Shelf("SHELF1");
    EXPECT_EQ("", shelf1->getShelfLocation());
    delete shelf1;
}

TEST(ShelfTest, canInsertItem1) {
    Shelf* shelf1 = new Shelf("SHELF1");
    LibraryItem* book1 = new Item();
    book1->setName("BOOK1");
    shelf1->insertItem(book1);
    std::vector<LibraryItem*> itemList = shelf1->getItemLists();
    EXPECT_EQ("BOOK1", itemList.at(0)->getName());
    //delete book1;
    shelf1->clearItem();
    delete shelf1;
}


TEST(ShelfTest, canInsertItem2) {
    Shelf* shelf1 = new Shelf("SHELF1");
    LibraryItem* book1 = new Item();
    book1->setName("BOOK1");
    LibraryItem* book2 = new Item();
    book2->setName("BOOK2");

    shelf1->insertItem(book1);
    shelf1->insertItem(book2);
    std::vector<LibraryItem*> itemList = shelf1->getItemLists();
    EXPECT_EQ("BOOK2", itemList.at(1)->getName());
    shelf1->clearItem();
    //delete book1;
    //delete book1;
    delete shelf1;

}


TEST(ShelfTest, canRemoveItem1) {
    Shelf* shelf1 = new Shelf("SHELF1");

    LibraryItem* book1 = new Item();
    book1->setName("BOOK1");
    LibraryItem* book2 = new Item();
    book2->setName("BOOK2");
    LibraryItem* book3 = new Item();
    book3->setName("BOOK3");

    shelf1->insertItem(book1);
    shelf1->insertItem(book2);
    shelf1->insertItem(book3);
    shelf1->removeItem(book2);
    delete book2;
    EXPECT_EQ("BOOK3", shelf1->getItemLists().at(1)->getName());
    //delete book1;
    //delete book2;
    //delete book3;
    shelf1->clearItem();
    delete shelf1;
}


TEST(ShelfTest, canRemoveItem2) {
    Shelf* shelf1 = new Shelf("SHELF1");

    LibraryItem* book1 = new Item();
    book1->setName("BOOK1");
    LibraryItem* book2 = new Item();
    book2->setName("BOOK2");
    LibraryItem* book3 = new Item();
    book3->setName("BOOK3");
    LibraryItem* book4 = new Item();
    book4->setName("BOOK4");

    shelf1->insertItem(book1);
    shelf1->insertItem(book2);
    shelf1->insertItem(book3);
    shelf1->insertItem(book4);
    shelf1->removeItem(book2);
    delete book2;
    EXPECT_EQ("BOOK4", shelf1->getItemLists().at(2)->getName());
    //delete book1;
    //delete book2;
    //delete book3;
    //delete book4;
    shelf1->clearItem();
    delete shelf1;


}

TEST(ShelfTest, canSetLocation) {
    Shelf* shelf1 = new Shelf("ShelfA1");
    shelf1->setShelfLocation("FirstFloor");
    EXPECT_EQ("FirstFloor", shelf1->getShelfLocation());
    delete shelf1;
}
#endif
