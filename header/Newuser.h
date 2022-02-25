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
	std::vector<std::string> users;


public:
	Newuser();
	bool isRegistered(string line, string NetID);
	//void insertList(const std::string data);
	void insertInfo(const std::string data);
	void clear();
	void printList();
	void saveFile();
};

#endif
