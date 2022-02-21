//
// Created by add33 on 2/18/2022.
//

#include "../header/Item.h"

// setters and getters
lb::Shelf *lb::Item::getLocation() const {return location;}

void lb::Item::setLocation(lb::Shelf *location) {Item::location = location;}

int lb::Item::getYear() const {return year;}

void lb::Item::setYear(int year) {Item::year = year;}

const std::vector<std::string> &lb::Item::getTag() const {return tag;}

void lb::Item::setTag(const std::vector<std::string> &tag) {Item::tag = tag;}

const std::string &lb::Item::getDescription() const {return description;}

void lb::Item::setDescription(const std::string &description) {Item::description = description;}

const std::string &lb::Item::getContent() const {return content;}

void lb::Item::setContent(const std::string &content) {Item::content = content;}

const std::string &lb::Item::getIdentifier() const {return identifier;}

void lb::Item::setIdentifier(const std::string &identifier) {Item::identifier = identifier;}

lb::BookStatus lb::Item::getAvailability() const {return availability;}

void lb::Item::setAvailability(lb::BookStatus availability) {Item::availability = availability;}

bool lb::Item::isAccess() const {return access;}

void lb::Item::setAccess(bool access) {Item::access = access;}

using namespace lb;
Item::Item() {
    name = "";
    location = nullptr;
    year = 0;
    tag.clear();
    description = "";
    content = "";
    identifier = "";
    availability = unavailable;
    access = "";
}

Item::Item(std::string name){
    this->name = name;
    location = nullptr;
    year = 0;
    tag.clear();
    description = "";
    content = "";
    identifier = "";
    availability = unavailable;
    access = "";
}

Item::Item(std::string name, int year){
    this->name = name;
    this->year = year;
    location = nullptr;
    year = 0;
    tag.clear();
    description = "";
    content = "";
    identifier = "";
    availability = unavailable;
    access = "";
}

Item::~Item(){
    delete location;
    tag.clear();
}

// a method to clear the tag lists
// return: none
void Item::clearTag() { tag.clear(); }

// a method to add a tag to the item
// param: a string var as a tag
// return: none
void Item::addTag(std::string tag) {this->tag.push_back(tag);}

// W I P
// a method that return the search result
// param:
// return: a list as the search result
std::vector<LibraryItem *> Item::search() {
    std::vector<LibraryItem *> result;
    return result;
}



