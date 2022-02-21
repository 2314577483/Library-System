//
// Created by 肖子超 on 2022/2/19.
//

#ifndef INC_100_PROJECT_ARTICLE_H
#define INC_100_PROJECT_ARTICLE_H


#include "Item.h"

namespace lb {
    class Article: public Item{
    private:
        std::string author;
        bool peerReviewed;
    public:
        std:: string getAuthor() {return author;}
        bool getPeerReviewed() {return peerReviewed;}
        void setAuthor(std:: string Author) {author = Author;}
        void setPeerReviewed(bool PeerReviewed) {peerReviewed = PeerReviewed;}
    };
}

#endif //INC_100_PROJECT_ARTICLE_H
