//
// Created by add33 on 2/18/2022.
//

#ifndef FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SHELF_H
#define FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SHELF_H

#include "LibraryItem.h"

namespace lb {

    class Shelf : public LibraryItem {
    private:
        std::string location;
        std::vector<LibraryItem*> itemLists;
    public:
        Shelf();
        explicit Shelf(std::string name);
        Shelf(std::string name, std::string location);
        ~Shelf() override;
        std::vector<LibraryItem*> search() override;
        std::string getLocation() const;
        std::vector<LibraryItem*> getItemLists() const;
        void insertItem(LibraryItem*);
        void removeItem(LibraryItem*);
        void setLocation(std::string);
        void clearItem();

    };
}


#endif //FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SHELF_H
