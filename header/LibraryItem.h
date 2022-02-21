//
// Created by add33 on 2/18/2022.
//

#ifndef FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_LIBRARYITEM_H
#define FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_LIBRARYITEM_H

#include <string>
#include <utility>
#include <vector>

namespace lb{
    class LibraryItem{
    protected:
        std::string name;
    public:
        LibraryItem() = default;
        virtual ~LibraryItem() = 0;
        virtual std::string getName() const { return name; };
        virtual void setName(std::string itemName) {this->name = std::move(itemName);};
        virtual std::vector<LibraryItem*> search() = 0;
    };
}

#endif //FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_LIBRARYITEM_H
