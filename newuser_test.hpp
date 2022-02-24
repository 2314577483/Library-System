#ifndef __NEWUSER_TEST_HPP__
#define __NEWUSER_TEST_HPP__

#include "gtest/gtest.h"

#include "header/Newuser.h"
#include "src/Newuser.cpp"

TEST(NewuserTest, AddStudentName){
   Newuser user1;
   user1.insertInfo("Leo");
   user1.printList();
   std::string output = testing::internal::GetCapturedStdout();
   EXPECT_EQ(output, "Leo");
}

TEST(NewuserTest, AddNameNetIDEmailPassword){
   Newuser user1;
   user1.insertInfo("Leo");
   user1.insertInfo("12345");
   user1.insertInfo("12345@ucr.edu");
   user1.insertInfo("aa12345");
   user1.printList();
   std::string output = testing::internal::GetCapturedStdout();
   EXPECT_EQ(output, "Leo 12345 12345@ucr.edu aa12345");
}

TEST(NewuserTest, ClearList){
   Newuser user1;
   user1.clear();
   user1.printList();
   std::string output = testing::internal::GetCapturedStdout();
   EXPECT_EQ(output, "");
}

TEST(NewuserTest, AddUserAndClearList){
   Newuser user1;
   user1.insertInfo("Leo"); 
   user1.clear();
   user1.printList();
   std::string output = testing::internal::GetCapturedStdout();
   EXPECT_EQ(output, "");
}
#endif
