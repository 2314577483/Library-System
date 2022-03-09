//
// Created by 肖子超 on 2022/2/19.
//

#ifndef INC_100_PROJECT_ARTICLE_H
#define INC_100_PROJECT_ARTICLE_H


#include "Item.h"


class Article: public Item{
private:
    bool peerReviewed;
public:
    bool getPeerReviewed() {return peerReviewed;}
    void setPeerReviewed(bool PeerReviewed) {peerReviewed = PeerReviewed;}

    //virtual std::vector<LibraryItem*> search();
};


#endif //INC_100_PROJECT_ARTICLE_H
