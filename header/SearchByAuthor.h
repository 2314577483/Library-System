//
// Created by add33 on 3/6/2022.
//

#ifndef FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SEARCHBYAUTHOR_H
#define FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SEARCHBYAUTHOR_H

#include "Search.h"


template <class T>
class SearchByAuthor : public Search<T> {
public:
    SearchByAuthor() = default;

    bool search(const T *item, std::string arg) const override {
        if (dynamic_cast<const Item *>(item)->getAuthor().find(arg) != std::string::npos) return true;
        return false;
    }

};



#endif //FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SEARCHBYAUTHOR_H
