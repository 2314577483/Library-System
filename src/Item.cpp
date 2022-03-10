//
// Created by add33 on 2/18/2022.
//

#include "../header/Item.h"

// setters and getters
const std::string &Item::getYear() const {return year;}
void Item::setYear(std::string &year) {Item::year = year;}

const std::string& Item::getTag() const {return tag;}
void Item::setTag(std::string& tag) {Item::tag = tag;}

const std::string &Item::getDescription() const {return description;}
void Item::setDescription(const std::string &description) {Item::description = description;}

const std::string &Item::getContent() const {return content;}
void Item::setContent(const std::string &content) {Item::content = content;}

const std::string &Item::getIdentifier() const {return identifier;}
void Item::setIdentifier(const std::string &identifier) {Item::identifier = identifier;}

const std::string &Item::getAvailability() const {return availability;}
void Item::setAvailability(const std::string availability) {Item::availability = availability;}

bool Item::isAccess() const {return access;}
void Item::setAccess(bool access) {Item::access = access;}


Item::Item() {
    name = "";
    year = "";
    author = "";
    tag = "";
    description = "";
    content = "";
    identifier = "";
    availability = "Avail";
    access = "";
}

//Item::Item(std::string name){
//    this->name = name;
//    location = nullptr;
//    year = 0;
//    tag.clear();
//    description = "";
//    content = "";
//    identifier = "";
//    availability = unavailable;
//    access = "";
//}

Item::Item(std::string name, std::string year){
    this->name = name;
    this->year = year;
    tag = "";
    author = "";
    description = "";
    content = "";
    identifier = "";
    availability = "Avail";
    access = "";
}

Item::Item(Item& item) {
    this->name = item.getName();
    this->year = item.getYear();
    tag = item.getTag();
    author = item.getAuthor();
    description = item.getDescription();
    content = item.getContent();
    identifier = item.getIdentifier();
    availability = item.getAvailability();
    access = item.isAccess();
}

Item::~Item(){

}

// a method to clear the tag lists
// return: none
//void Item::clearTag() { tag.clear(); }

// a method to add a tag to the item
// param: a string var as a tag
// return: none
//void Item::addTag(std::string tag) {this->tag.push_back(tag);}

// a function to search the item with argument
// **need to set the searchEngine before using this function**
std::vector<LibraryItem*> Item::search(std::string arg, std::vector<LibraryItem*> list) {
    if (searchEngine != nullptr) {
        if (searchEngine->search(this, arg)) {
            list.push_back(this);
        } 
    } 
    return list;
}



