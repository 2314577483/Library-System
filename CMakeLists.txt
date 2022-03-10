CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)
include_directories(src)
include_directories(header)
include_directories(tests)
ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(main
        src/main.cpp
        src/Newuser.cpp
        src/Shelf.cpp
        src/Student.cpp
        src/User.cpp
        src/Item.cpp
        src/Librarian.cpp
        )

ADD_EXECUTABLE(test
        tests/unit_tests.cpp
        )

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
