#ifndef __newuser_h__
#define __newuser_h__

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Newuser user[100];	// the maximum of users


class Newuser {
private:
	string NetID;
	string password;
	string email;
	string studentName;
	int scount = 0;		// saved number of users
public:
	void openFile();
	void checkFile();
	void registration();
	//bool isRegistered();
};


#endif