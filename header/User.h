#ifndef __USER_H__
#define __USER_H__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#define RECORD_FILE "record.csv"
#define ITEM_FILE "items.csv"

using namespace std;

class User {
private:
	int userType;


public:
	User();
	void isNewuser();
	void isStudent();
	void isLibrarian();
};


#endif