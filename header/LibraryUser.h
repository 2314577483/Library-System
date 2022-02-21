//
// Created by 肖子超 on 2022/2/19.
//

#ifndef INC_100_PROJECT_LIBRARYUSER_H
#define INC_100_PROJECT_LIBRARYUSER_H
#include <string>
#include <utility>
#include <vector>

namespace lb{
    class LibraryUser{
    protected:
        std::string name;

    public:
        LibraryUser() = default;
        virtual ~LibraryUser() = 0;
        virtual std::string getName() const {return name;}
        virtual void setName(std::string userName) {this->name = std::move(userName);}
        ///virtual std::vector<LibraryUser*> search() = 0;  // why do we need this function?
    };
}
#endif //INC_100_PROJECT_LIBRARYUSER_H
