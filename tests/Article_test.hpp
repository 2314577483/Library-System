//
// Created by 肖子超 on 2022/2/20.
//

#ifndef INC_100_PROJECT_ARTICLE_TEST_H
#define INC_100_PROJECT_ARTICLE_TEST_H
#include "gtest/gtest.h"

#include "../header/Article.h"


TEST(ArticleTest, canGetPeerReviewed1) {
    Article article1;
    article1.setPeerReviewed(true);
    EXPECT_EQ(true, article1.getPeerReviewed());
}


TEST(ArticleTest, canGetPeerReviewed2) {
    Article article1;
    article1.setPeerReviewed(false);
    EXPECT_EQ(false, article1.getPeerReviewed());
}

#endif //INC_100_PROJECT_ARTICLE_TEST_H
