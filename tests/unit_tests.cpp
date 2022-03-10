#include "gtest/gtest.h"
#include "NewuserTests.hpp"
#include "StudentTests.hpp"
#include "LibrarianTests.hpp"
#include "Item_test.hpp"
#include "Shelf_test.hpp"
#include "Book_test.h"
#include "Article_test.hpp"
#include "Video_test.hpp"
#include "Search_tests.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
