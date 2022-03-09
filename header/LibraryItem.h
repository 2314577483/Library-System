//
// Created by add33 on 2/18/2022.
//

#ifndef FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_LIBRARYITEM_H
#define FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_LIBRARYITEM_H

#include <string>
#include <utility>
#include <vector>
#include "..\header\Search.h"
#define ITEM_FILE "items.csv"


class LibraryItem{
protected:
    std::string name;
    Search<LibraryItem>* searchEngine = nullptr;
    std::vector<LibraryItem*> itemLists;
    LibraryItem* location = nullptr;
public:
    LibraryItem() = default;
    virtual ~LibraryItem() = default;
    virtual std::string getName() const { return name; };
    virtual void setName(std::string itemName) {this->name = std::move(itemName);};
    virtual std::vector<LibraryItem*> search(std::string arg, std::vector<LibraryItem*> list) = 0;

    // a function to set searchEngine.
    // **The searchEngine has to be set before using the function search**
    virtual void setSearch(Search<LibraryItem>* search) {
        searchEngine = search;
        for (auto& item : itemLists) item->setSearch(search);
    }

    // a function to push an item to the item lists in the back of the list
    // param: a pointer of LibraryItem object
    // return: none
    virtual void insertItem(LibraryItem* item) { item->setLocation(this); itemLists.push_back(item); }

    virtual void setLocation(LibraryItem* location) { this->location = location; }

    virtual LibraryItem* getLocation() { return location; }
};


#endif //FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_LIBRARYITEM_H
