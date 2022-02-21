//
// Created by add33 on 2/18/2022.
//

#include "../header/Shelf.h"

#include <utility>

using namespace lb;

// instructors
Shelf::Shelf() {
    name = "";
    location = "";
    itemLists.clear();
}

Shelf::Shelf(std::string name){
    this->name = std::move(name);
    location = "";
    itemLists.clear();
}
Shelf::Shelf(std::string name, std::string location){
    this->name = std::move(name);
    this->location = std::move(location);
    itemLists.clear();
}

// destructor
Shelf::~Shelf(){clearItem();}

//getters
std::vector<LibraryItem*> Shelf::search(){return itemLists;}    //W I P !!!
std::string Shelf::getLocation() const {return location;}
std::vector<LibraryItem*> Shelf::getItemLists() const {return itemLists;}

// a function to push an item to the item lists in the back of the list
// param: a pointer of LibraryItem object
// return: none
void Shelf::insertItem(LibraryItem* item){itemLists.push_back(item);}

// a function to remove a specific item
// param: a pointer of LibraryItem object that needs to be remove
// return: none
void Shelf::removeItem(LibraryItem* item){for(auto it = itemLists.begin(); it != itemLists.end(); ++it){if(*it == item) itemLists.erase(it);}}

// setters
void Shelf::setLocation(std::string location){this->location = std::move(location);}

// a function to remove all the items from the item lists
// return: none
void Shelf::clearItem() {
    for(auto & itemList : itemLists) delete itemList;
    itemLists.clear();
}