//
// Created by 肖子超 on 2022/2/19.
//

#ifndef INC_100_PROJECT_BOOK_H
#define INC_100_PROJECT_BOOK_H

#include "../header/Item.h"


class Book: public Item{
private:
    std::string publisher;
    std::string ISBN;
public:

    std:: string getPublisher() {return publisher;}
    std::string getISBN() {return ISBN;}


    void setPublisher(std::string Publisher) {publisher = Publisher;}
    void setISBN(std:: string ISBN) {ISBN = ISBN;}

    //virtual std::vector<LibraryItem*> search();
};


#endif //INC_100_PROJECT_BOOK_H
