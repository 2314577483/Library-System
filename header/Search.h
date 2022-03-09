//
// Created by add33 on 3/2/2022.
//

#ifndef FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SEARCH_H
#define FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SEARCH_H

#include <string>


template <class T>
class Search {
public:
    virtual ~Search() = default;

    virtual bool search(const T* item, std::string arg) const = 0;
};



#endif //FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_SEARCH_H