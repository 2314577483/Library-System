//
// Created by add33 on 3/2/2022.
//

#ifndef FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SEARCHBYNAME_H
#define FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SEARCHBYNAME_H

#include "Search.h"


    template <class T>
    class SearchByName : public Search<T>{
    public:
        SearchByName() = default;
        bool search(const T* item, std::string arg) const override {
            if( dynamic_cast<const Item*>(item)->getName().find(arg) != std::string::npos) return true;
            return false;
        }
    };



#endif //FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SEARCHBYNAME_H
