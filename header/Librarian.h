#ifndef __LIBRARIAN_H__
#define __LIBRARIAN_H__

#include "User.h"
#include <vector>

class Librarian : public User {
private:
	std::string NetID;
	std::string password;
	std::string line;
	double amount = 0;
	int lineNum = 0;

	std::vector<std::string> items;

public:
	Librarian();

	bool LogIn() { return true; }
	bool LogOut() { return false; }

	bool isNetIDExisted(string NetID);
	bool isPasswordMatched(string NetID, string Password);
	void resetPassword(string NetID, string oldPassord, string newPassword);
	void displayAccountDetails(string NetID);

	void removeAccount(string NetID);

	void addBook(vector<std::string> tmpVector);
	void addArticle(vector<std::string> tmpVector);
	void addVideo(vector<std::string> tmpVector);

	void removeItem(string tmpID);

	void saveItemFile();

	void insertItemInfo(const std::string data);
	void clearVector() { items.clear(); }
};

#endif


