#ifndef __USER_H__
#define __USER_H__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define RECORD_FILE "record.txt"

namespace us {
	class User {
	private:
		int userType;

	public:
		bool isNewuser();
		bool isStudent();
		bool isNewuser();
	};
}


#endif