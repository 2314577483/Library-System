#ifndef __newuser_h__
#define __newuser_h__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define USERNAME_FILE "username.txt"
#define PASSWORD_FILE "password.txt"

using namespace std;


class Newuser {
private:
	string NetID;
	string password;
	string email;
	string studentName;
public:
	void saveFile();
	void checkFile();
	void registration();
	//bool isRegistered();
};

//Newuser user[100];

#endif