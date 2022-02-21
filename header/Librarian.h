
#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "../header/User.h"

using namespace lb;
using namespace std;

class Librarian : public User {
private:
	string NetID;
	string password;
	bool status;

public:
	Librarian() { NetID = ""; password = ""; status = false; }
	Librarian(string tmpID, string tmpPassword) { NetID = tmpID; password = tmpPassword; status = true; }

	LibraryUser* search(std::string name) {
		// why do we need this function?
	}

	bool isLogined() const { return status; }
	void logIn() { status = true; }
	void logOut() { status = false; }

	void resetPassword();
	
	void manageBook();

};



#endif //LIBRARIAN_H

