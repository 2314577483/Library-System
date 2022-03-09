#pragma once
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "User.h"

class Student :public User {
private:
	string NetID;
	string password;
	string line;
	double amount = 0;
	int lineNum = 0;

public:
	Student();


	bool LogIn() { return true; }
	bool LogOut() { return false; }

	std::string getNetID() { return NetID; }

	bool isNetIDExisted(string NetID);
	bool isPasswordMatched(string NetID, string Password);
	void resetPassword(string NetID, string oldPassord, string newPassword);
	void displayAccountDetails(string NetID);

	void borrowItem(string NetID);
	void returnItem(string NetID);

	void searchName();
	void searchYear();
	void searchAuthor();
	void searchTag();
	void searchIdentifier();

	void addDebt(string NetID, int amount);
	void showDebt(string NetID);
};


#endif


