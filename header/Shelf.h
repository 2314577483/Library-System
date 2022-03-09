//
// Created by add33 on 2/18/2022.
//

#ifndef FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SHELF_H
#define FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SHELF_H

#include "LibraryItem.h"



class Shelf : public LibraryItem {
private:
    std::string shelfLocation;
    std::string shelfNumber;
public:
    Shelf();
   explicit Shelf(std::string name);
    Shelf(std::string number, std::string location);
    ~Shelf();

    //virtual std::vector<LibraryItem*> search();

    std::vector<LibraryItem*> search(std::string arg, std::vector<LibraryItem*> list) override;
    std::vector<LibraryItem*> getItemLists() const;

    void insertItem(LibraryItem*);
    void removeItem(LibraryItem*);
    void clearItem();

    std::string getShelfLocation() const;
    void setShelfLocation(std::string);

    std::string getShelfNumber() const;
    void setShelfNumber(std::string);


};



#endif //FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SHELF_H
