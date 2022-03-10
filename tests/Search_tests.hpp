#ifndef __SEARCH_TESTS_HPP__
#define __SEARCH_TESTS_HPP__


#include "../header/Item.h"
#include "../header/AllSearches.h"
#include <iostream>
#include <sstream>
#include "gtest/gtest.h"

void print_Location(std::ostream& out, std::vector<LibraryItem* > searchResult) {
    for(auto &i : searchResult) out << i->getLocation() << " ";
    out << std::endl;
}

void print_name(std::ostream& out, std::vector<LibraryItem* > searchResult) {
    for(auto &i : searchResult) out << i->getName() << " ";
    out << std::endl;
}

TEST(SearchTest, canSearchByYear) {
    
    LibraryItem* shelf1 = new Shelf("Shelf1");

    
    LibraryItem* item1 = new Item("Book1", "2000");

    shelf1->insertItem(item1);

    std::vector<LibraryItem* > searchResult;

    SearchByYear<LibraryItem>* tmp1 = new SearchByYear<LibraryItem>();

    shelf1->setSearch(tmp1);
    searchResult = shelf1->search("2000", searchResult);


    std::stringstream ss;
    print_name(ss, searchResult);
    std::string s = ss.str();
    EXPECT_EQ("Book1 \n", s);
    delete tmp1;
    delete shelf1;
 
}

TEST(SearchTest, canSearchByYear2) {

    LibraryItem* shelf1 = new Shelf("Shelf1");
    LibraryItem* shelf2 = new Shelf("Shelf2");
    LibraryItem* shelf3 = new Shelf("Shelf3");


    LibraryItem* item1 = new Item("Book1", "2001");
    LibraryItem* item2 = new Item("Book2", "2000");
    LibraryItem* item3 = new Item("Book3", "2000");

    shelf1->insertItem(item1);
    shelf2->insertItem(item2);
    shelf3->insertItem(item3);

    std::vector<LibraryItem* > searchResult;
    SearchByYear<LibraryItem>* tmp1 = new SearchByYear<LibraryItem>();
    SearchByYear<LibraryItem>* tmp2 = new SearchByYear<LibraryItem>();
    SearchByYear<LibraryItem>* tmp3 = new SearchByYear<LibraryItem>();

    shelf1->setSearch(tmp1);
    shelf2->setSearch(tmp2);
    shelf3->setSearch(tmp3);



    searchResult = shelf1->search("2000", searchResult);
    searchResult = shelf2->search("2000", searchResult);
    searchResult = shelf3->search("2000", searchResult);


    std::stringstream ss;
    print_name(ss, searchResult);
    std::string s = ss.str();
    EXPECT_EQ("Book2 Book3 \n", s);
	delete tmp1;
	delete tmp2;
	delete tmp3;
 	delete shelf1;
   	delete shelf2;
    	delete shelf3;

}


TEST(SearchTest, canSearchByName) {

    LibraryItem* shelf1 = new Shelf("Shelf1");

    LibraryItem* item1 = new Item("Book1", "2000");


    shelf1->insertItem(item1);

    std::vector<LibraryItem* > searchResult;

    SearchByName<LibraryItem>* tmp1 = new SearchByName<LibraryItem>();

    shelf1->setSearch(tmp1);

    searchResult = shelf1->search("Book1", searchResult);

    std::stringstream ss;
    print_Location(ss, searchResult);
    std::string s = ss.str();
    EXPECT_EQ("0 \n", s);
    delete tmp1;
    delete shelf1;

}





TEST(SearchTest, canSearchByAuthor) {
  
    LibraryItem* shelf1 = new Shelf("Shelf1");
    LibraryItem* shelf2 = new Shelf("Shelf2");
    LibraryItem* shelf3 = new Shelf("Shelf3");


    LibraryItem* item1 = new Item("Book1", "2000");
    LibraryItem* item2 = new Item("Book2", "2001");
    LibraryItem* item3 = new Item("Book3", "2000");
    dynamic_cast<Item *>(item1)->setAuthor("Allen");
    dynamic_cast<Item *>(item2)->setAuthor("Bob");



    shelf1->insertItem(item1);
    shelf2->insertItem(item2);
    shelf3->insertItem(item3);

    std::vector<LibraryItem* > searchResult;

    SearchByAuthor<LibraryItem>* tmp1 = new SearchByAuthor<LibraryItem>();
    SearchByAuthor<LibraryItem>* tmp2 = new SearchByAuthor<LibraryItem>();
    SearchByAuthor<LibraryItem>* tmp3 = new SearchByAuthor<LibraryItem>();
    shelf1->setSearch(tmp1);
    shelf2->setSearch(tmp2);
    shelf3->setSearch(tmp3);

  
    searchResult = shelf1->search("Allen", searchResult);
    searchResult = shelf2->search("Allen", searchResult);
    searchResult = shelf3->search("Allen", searchResult);


    std::stringstream ss;
    print_name(ss, searchResult);
    std::string s = ss.str();
    EXPECT_EQ("Book1 \n", s);
	delete tmp1;
	delete tmp2;
	delete tmp3;        
	delete shelf1;
        delete shelf2;
        delete shelf3;



}


TEST(SearchTest, canSearchByAuthor2) {

    LibraryItem* shelf1 = new Shelf("Shelf1");
    LibraryItem* shelf2 = new Shelf("Shelf2");
    LibraryItem* shelf3 = new Shelf("Shelf3");


    LibraryItem* item1 = new Item("Book1", "2000");
    LibraryItem* item2 = new Item("Book2", "2001");
    LibraryItem* item3 = new Item("Book3", "2000");
    dynamic_cast<Item *>(item3)->setAuthor("Monica");
    dynamic_cast<Item *>(item2)->setAuthor("Bob");



    shelf1->insertItem(item1);
    shelf2->insertItem(item2);
    shelf3->insertItem(item3);

    std::vector<LibraryItem* > searchResult;

    SearchByAuthor<LibraryItem>* tmp1 = new SearchByAuthor<LibraryItem>();
    SearchByAuthor<LibraryItem>* tmp2 = new SearchByAuthor<LibraryItem>();
    SearchByAuthor<LibraryItem>* tmp3 = new SearchByAuthor<LibraryItem>();
    shelf1->setSearch(tmp1);
    shelf2->setSearch(tmp2);
    shelf3->setSearch(tmp3);


  
    searchResult = shelf1->search("Monica", searchResult);
    searchResult = shelf2->search("Monica", searchResult);
    searchResult = shelf3->search("Monica", searchResult);


    std::stringstream ss;
    print_name(ss, searchResult);
    std::string s = ss.str();

    EXPECT_EQ("Book3 \n", s);
	delete tmp1;
	delete tmp2;
	delete tmp3;        
	delete shelf1;
        delete shelf2;
        delete shelf3;
}





TEST(SearchTest, canSearchByIdentifier) {

    LibraryItem* shelf1 = new Shelf("Shelf1");
    LibraryItem* shelf2 = new Shelf("Shelf2");
    LibraryItem* shelf3 = new Shelf("Shelf3");

  
    LibraryItem* item1 = new Item("Book1", "2000");
    LibraryItem* item2 = new Item("Book2", "2001");
    LibraryItem* item3 = new Item("Book3", "2000");
    dynamic_cast<Item *>(item2)->setIdentifier("SD58867");




    shelf1->insertItem(item1);
    shelf2->insertItem(item2);
    shelf3->insertItem(item3);

    std::vector<LibraryItem* > searchResult;

   	SearchByIdentifier<LibraryItem>* tmp1 = new SearchByIdentifier<LibraryItem>();
    SearchByIdentifier<LibraryItem>* tmp2 = new SearchByIdentifier<LibraryItem>();
    SearchByIdentifier<LibraryItem>* tmp3 = new SearchByIdentifier<LibraryItem>();
    shelf1->setSearch(tmp1);
    shelf2->setSearch(tmp2);
    shelf3->setSearch(tmp3);


  
    searchResult = shelf1->search("SD58867", searchResult);
    searchResult = shelf2->search("SD58867", searchResult);
    searchResult = shelf3->search("SD58867", searchResult);


    std::stringstream ss;
    print_name(ss, searchResult);
    std::string s = ss.str();

    EXPECT_EQ("Book2 \n", s);
	delete tmp1;
	delete tmp2;
	delete tmp3;        
	delete shelf1;
        delete shelf2;
        delete shelf3;
}


TEST(SearchTest, canSearchByIdentifier2) {
 
LibraryItem* shelf1 = new Shelf("Shelf1");
LibraryItem* shelf2 = new Shelf("Shelf2");
LibraryItem* shelf3 = new Shelf("Shelf3");


LibraryItem* item1 = new Item("Book1", "2000");
LibraryItem* item2 = new Item("Book2", "2001");
LibraryItem* item3 = new Item("b3", "2000");
dynamic_cast<Item *>(item3)->setIdentifier("XS87899");




shelf1->insertItem(item1);
shelf2->insertItem(item2);
shelf3->insertItem(item3);

std::vector<LibraryItem* > searchResult;

    	SearchByIdentifier<LibraryItem>* tmp1 = new SearchByIdentifier<LibraryItem>();
    SearchByIdentifier<LibraryItem>* tmp2 = new SearchByIdentifier<LibraryItem>();
    SearchByIdentifier<LibraryItem>* tmp3 = new SearchByIdentifier<LibraryItem>();
    shelf1->setSearch(tmp1);
    shelf2->setSearch(tmp2);
    shelf3->setSearch(tmp3);



searchResult = shelf1->search("XS87899", searchResult);
searchResult = shelf2->search("XS87899", searchResult);
searchResult = shelf3->search("XS87899", searchResult);


std::stringstream ss;
print_name(ss, searchResult);
std::string s = ss.str();

EXPECT_EQ("b3 \n", s);
	delete tmp1;
	delete tmp2;
	delete tmp3;        
	delete shelf1;
        delete shelf2;
        delete shelf3;
}

#endif
