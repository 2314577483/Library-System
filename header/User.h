//
// Created by 肖子超 on 2022/2/19.
//

#ifndef INC_100_PROJECT_USER_H
#define INC_100_PROJECT_USER_H

#include "LibraryUser.h"
#include "LibraryItem.h"
#include <vector>

namespace lb {

    class User : public LibraryUser {
    private:
        int usertype;
        std::vector<LibraryUser*> userLists;

    public:
        User() {
            name = "";
            usertype = 0;
            userLists.clear();
        }

        explicit User(std::string name) {
            name = name;
            usertype = 0;
            userLists.clear();
        }

        User(std::string name, int usertype) {
            name = name;
            usertype = usertype;
            userLists.clear();
        }

        ~User() {clearUser();}

        LibraryUser* search(std::string name) {           // changed LibraryItem to LibraryUser
            for (int i = 0; i < userLists.size(); i++){   
                if (name == userLists.at(i)->getName())   // use getter
                    return userLists.at(i);
            }
        }

        int usertype() const { return usertype; }

        std::vector<LibraryUser*> getUserLists() const { return userLists; }

        void insertUser(LibraryUser* user) {userLists.push_back(user);}

        void removeUser(LibraryUser* user) {
            for(auto it = userLists.begin(); it != userLists.end(); ++it)
                if(*it == user) userLists.erase(it);
        }

        void setUsertype(int type);

        void clearUser() {
            for(auto & userList : userLists) delete userList;
            userLists.clear();
        }
    };
}
#endif //INC_100_PROJECT_USER_H
