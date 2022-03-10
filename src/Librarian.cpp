#include "../header/Librarian.h"
#include "../header/Item.h"
#include <fstream>
#include <vector>

Librarian::Librarian() {
	NetID = "";
	password = "";
}

bool Librarian::isNetIDExisted(string NetID) {
	std::ifstream indataFile(RECORD_FILE, std::ios::in);

	if (indataFile.is_open()) {
		while (getline(indataFile, line)) {
			if (line.find(NetID) != string::npos) {
				return 1;
			}
		}
	}
	indataFile.close();
	return 0;
}

bool Librarian::isPasswordMatched(string NetID, string Password) {
	std::ifstream indataFile(RECORD_FILE, ios::in);
	if (indataFile.is_open()) {
		while (getline(indataFile, line)) {
			if (line.find(NetID) != string::npos && line.find(Password) != string::npos) {
				return 1;
			}
		}
	}
	indataFile.close();
	return 0;
}

// to reset password, we need to find if there is the NetID is existed
// if true; go to out the data from file, then save them to the new vector
void Librarian::resetPassword(string NetID, string oldPassord, string newPassword) {
	vector<vector<std::string>> tmp;

	std::ifstream indataFile(RECORD_FILE, ios::in);
	for (std::string row_line; std::getline(indataFile, row_line);)
	{
		tmp.emplace_back();
		std::istringstream row_stream(row_line);
		for (std::string column; std::getline(row_stream, column, ',');) {
			if (row_line.find(NetID) != string::npos) {
				if (column.find(oldPassord) != string::npos) {
					column.replace(column.begin(), column.end(), newPassword);
				}
			}
			tmp.back().push_back(column);
		}
	}
	indataFile.close();

	// Save all string to the file
	std::ofstream outdataFile(RECORD_FILE, ios::out);

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < tmp.at(i).size(); j++) {
			outdataFile << tmp.at(i).at(j) << ",";
		}
		outdataFile << endl;
	}

	outdataFile.close();
}

// print list;
void Librarian::displayAccountDetails(string NetID) {
	vector<vector<std::string>> tmp;

	std::ifstream indataFile(RECORD_FILE, ios::in);
	for (std::string row_line; std::getline(indataFile, row_line);)
	{
		tmp.emplace_back();
		std::istringstream row_stream(row_line);
		for (std::string column; std::getline(row_stream, column, ',');) {
			if (row_line.find(NetID) != string::npos) {
				tmp.back().push_back(column);
			}

		}
	}
	indataFile.close();

	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());

	cout << "\t\t*            Role: " << tmp.at(0).at(1) << endl;
	cout << "\t\t*            Name: " << tmp.at(0).at(2) << endl;
	cout << "\t\t*            NetID: " << tmp.at(0).at(3) << endl;
	cout << "\t\t*            Email: " << tmp.at(0).at(4) << endl;
}

void Librarian::removeAccount(string NetID) {
	vector<vector<std::string>> tmp;

	std::ifstream indataFile(RECORD_FILE, ios::in);
	for (std::string row_line; std::getline(indataFile, row_line);)
	{
		tmp.emplace_back();
		std::istringstream row_stream(row_line);
		for (std::string column; std::getline(row_stream, column, ',');) {
			if (row_line.find(NetID) != string::npos) {
				row_line.erase();
			}
			tmp.back().push_back(column);
		}
	}
	indataFile.close();

	std::ofstream outdataFile(RECORD_FILE, ios::out);

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < tmp.at(i).size(); j++) {
			outdataFile << tmp.at(i).at(j) << ",";
		}
		outdataFile << endl;
	}

	outdataFile.close();
}

void Librarian::removeItem(string tmpID) {
	vector<string> temp;

	size_t pos = 0;
	size_t pos2 = 0;
	string line;

	std::ifstream indataFile(ITEM_FILE, ios::in);
	if (indataFile.is_open()) {
		while (getline(indataFile, line)) {
			pos = line.find(tmpID);
			if (pos != string::npos) {
				line.erase();
			}
			temp.push_back(line);
		}
	}
	indataFile.close();

	std::ofstream outdataFile(ITEM_FILE, ios::out);

	for (int i = 0; i < temp.size(); i++) {
		outdataFile << temp.at(i) << ",";
		outdataFile << endl;
	}

	outdataFile.close();
}

void Librarian::insertItemInfo(const std::string data) {
	items.push_back(data);
}

void Librarian::addBook(vector<std::string> tmpVector) {
	string tmpPublisher;
	string tmpISBN;

	cout << "\n\t\tPlease Enter the Publisher of the Book: ";

	getline(cin, tmpPublisher);

	cout << "\n\t\tPlease Enter the ISBN of the Book: ";

	getline(cin, tmpISBN);

	this->clearVector();

	for (int i = 0; i < 5; i++) {
		this->insertItemInfo(tmpVector.at(i));
	}

	this->insertItemInfo(tmpPublisher);
	this->insertItemInfo(tmpISBN);

	for (int i = 5; i < 10; i++) {
		this->insertItemInfo(tmpVector.at(i));
	}

	this->saveItemFile();
}
void Librarian::addArticle(vector<std::string> tmpVector) {
	
	this->clearVector();
	for (int i = 0; i < 10; i++) {
		this->insertItemInfo(tmpVector.at(i));
	}
	this->saveItemFile();
}
void Librarian::addVideo(vector<std::string> tmpVector) {
	string tmpDuration;

	cout << "\n\t\tHow long is this Video?: ";

	getline(cin, tmpDuration);

	this->clearVector();

	for (int i = 0; i < 5; i++) {
		this->insertItemInfo(tmpVector.at(i));
	}

	this->insertItemInfo(tmpDuration);

	for (int i = 5; i < 10; i++) {
		this->insertItemInfo(tmpVector.at(i));
	}

	this->saveItemFile();
}

void Librarian::saveItemFile() {
	std::ofstream outdataFile(ITEM_FILE, std::ios::app);

	for (int i = 0; i < items.size(); i++) {
		outdataFile << items.at(i) << ",";
	}
	outdataFile << endl;
	outdataFile.close();
}