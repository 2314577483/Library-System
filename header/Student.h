#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "../header/User.h"
#include "../header/LibraryUser.h"
#include "../header/Shelf.h"

using namespace std;

namespace lb {
	class Student : public User {
	private:
		string NetID;
		string password;
		bool status;

	public:
		Student() { NetID = ""; password = ""; status = false; }
		Student(string tmpID, string tmpPassword) { NetID = tmpID; password = tmpPassword; status = true; }
		
		/*LibraryUser* search(std::string name) {           
			return nullptr;
		}*/

		bool isLogined() const { return status; }
		void logIn() { status = true; }
		void logOut() { status = false; }

		void resetPassword();

		Shelf* getBook();
		void returnBook();


		// do we need the reserveBook(), searchBook()?
	};

}



#endif