//
// Created by add33 on 2/18/2022.
//

#include "../header/Shelf.h"

#include <utility>

// instructors
Shelf::Shelf() {
    shelfLocation = "";
    shelfNumber = "";
    itemLists.clear();
}

Shelf::Shelf(std::string name){
    this->name = std::move(name);
    shelfLocation = "";
    shelfNumber = "";
    itemLists.clear();
}

Shelf::Shelf(std::string number, std::string location){
    this->shelfLocation = std::move(location);
    this->shelfNumber = std::move(number);
    itemLists.clear();
}

// destructor
Shelf::~Shelf() {clearItem();}

//getters
// a function to search the item with argument
// **need to set the searchEngine before using this function**
std::vector<LibraryItem*> Shelf::search(std::string arg, std::vector<LibraryItem*> list) {
    if (searchEngine != nullptr) for (auto& i : itemLists) list = i->search(arg, list);
    return list;
}
std::string Shelf::getShelfLocation() const {return shelfLocation;}
std::string Shelf::getShelfNumber() const {return shelfNumber;}


std::vector<LibraryItem*> Shelf::getItemLists() const {return itemLists;}

// a function to push an item to the item lists in the back of the list
// param: a pointer of LibraryItem object
// return: none
void Shelf::insertItem(LibraryItem* item) {itemLists.push_back(item);}

// a function to remove a specific item
// param: a pointer of LibraryItem object that needs to be remove
// return: none
void Shelf::removeItem(LibraryItem* item) {
    for (auto it = itemLists.begin(); it != itemLists.end(); ++it) {
        if (*it == item) itemLists.erase(it);
    }
}

// setters
void Shelf::setShelfLocation(std::string location) { this->shelfLocation = std::move(location); }
void Shelf::setShelfNumber(std::string number) { this->shelfNumber = std::move(number); }

// a function to remove all the items from the item lists
// return: none
void Shelf::clearItem() {
    for(auto & itemList : itemLists) delete itemList;
    itemLists.clear();
}