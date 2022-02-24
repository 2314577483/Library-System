#include "gtest/gtest.h"

#include "newuser_test.hpp"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
