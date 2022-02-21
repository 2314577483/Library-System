//
// Created by 肖子超 on 2022/2/19.
//

#ifndef INC_100_PROJECT_BOOK_H
#define INC_100_PROJECT_BOOK_H

#include "Item.h"
#include "BookFormat.h"
#include "BookStatus.h"

namespace lb {
    class Book: public Item{
    private:
        std::string author;
        std::string publisher;
        BookFormat format;
        std::string ISBN;
    public:
        std:: string getAuthor() {return author;}
        std:: string getPublisher() {return publisher;}
        BookFormat getFormat() {return format;}
        std::string getISBN() {return ISBN;}
        void setAuthor(std::string Author) {author = Author;}
        void setPublisher(std::string Publisher) {publisher = Publisher;}
        void setFormat(BookFormat Format) {format = Format;}
        void setISBN(std:: string ISBN) {ISBN = ISBN;}
    };
}

#endif //INC_100_PROJECT_BOOK_H
