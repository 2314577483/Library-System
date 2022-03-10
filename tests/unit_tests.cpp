#include "gtest/gtest.h"
#include "NewuserTests.hpp"
#include "StudentTests.hpp"
#include "LibrarianTests.hpp"
#include "ItemTests.hpp"
#include "ShelfTests.hpp"
#include "BookTests.hpp"
#include "ArticleTests.hpp"
#include "VideoTests.hpp"
#include "SearchTests.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
