#ifndef __NEWUSER_H__
#define __NEWUSER_H__


#include <fstream>
#include <iostream>
#include <string>
#include <vector>


#define RECORD_FILE "record.txt"

using namespace std;

class Newuser {
private:
	std::string NetID;
	std::string password;
	std::string studentName;
	std::string email;
	std::vector<Newuser*> userList;

public:
	Newuser();
	void insertInfo(Newuser* item);
	bool isRegistered(Newuser* NetID);
	void saveFile();
	void registration();


};

#endif