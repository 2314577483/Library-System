#include "..\header\Student.h"
#include "..\header\LibraryItem.h"
#include "..\header\Item.h"
#include "..\header\Shelf.h"
#include "..\header\AllSearches.h"
#include <iostream>
#include <fstream>

Student::Student() {
	NetID = "";
	password = "";
}

bool Student::isNetIDExisted(string NetID) {
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

bool Student::isPasswordMatched(string NetID, string Password) {

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
void Student::resetPassword(string NetID, string oldPassord, string newPassword) {
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
void Student::displayAccountDetails(string NetID) {
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

void Student::borrowItem(string NetID) {
	string tmpID;

	cout << "\n\t\tPlease Enter the identifier of the Book: ";
	cin >> tmpID;

	vector<string> temp;

	size_t pos = 0;
	size_t pos2 = 0;

	std::ifstream indataFile(ITEM_FILE, ios::in);
	if (indataFile.is_open()) {
		while (getline(indataFile, line)) {
			pos = line.find(tmpID);
			if (pos != string::npos) {
				pos2 = line.find("Avail");
				if (pos2 != string::npos) {
					line = line.replace(pos2, pos2, NetID);
					cout << "\n\t\tSuccessfully borrow this book" << endl;
				}
				else {
					cout << "\n\t\tThe item is not Available" << endl << endl;
				}
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

void Student::returnItem(string NetID) {
	string tmpID;

	cout << "\n\t\tPlease Enter the identifier of the Book: ";
	cin >> tmpID;

	vector<string> temp;

	size_t pos = 0;
	size_t pos2 = 0;

	std::ifstream indataFile(ITEM_FILE, ios::in);
	if (indataFile.is_open()) {
		while (getline(indataFile, line)) {
			pos = line.find(tmpID);
			if (pos != string::npos) {
				pos2 = line.find(NetID);
				if (pos2 != string::npos) {
					line = line.replace(pos2, pos2, "Avail");
					cout << "\n\t\tSuccessfully return this book" << endl;
				}
				else {
					cout << "\n\t\tIncorrect Book" << endl << endl;
				}
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

void Student::search(int searchChoice) {
	LibraryItem* shelf1 = new Shelf("Shelf1");

	std::ifstream indataFile(ITEM_FILE, ios::in);
	if (indataFile.is_open()) {
		while (getline(indataFile, line)) {
			stringstream ss(line);
			Item item;
			string tmp1;
			getline(ss, tmp1, ',');
			item.setName(tmp1);

			string tmp2;
			getline(ss, tmp2, ',');
			item.setYear(tmp2);

			string tmp3;
			getline(ss, tmp3, ',');
			item.setAuthor(tmp3);

			string tmp4;
			getline(ss, tmp4, ',');
			item.setTag(tmp4);

			string tmp5;
			getline(ss, tmp5, ',');
			item.setIdentifier(tmp5);

			LibraryItem* item1 = new Item(item);

			shelf1->insertItem(item1);

		}
	}
	indataFile.close();

	std::vector<LibraryItem* > searchResult;
	// set search category -- sample given using Year

	switch (searchChoice) {
	case 1:
		shelf1->setSearch(new SearchByName<LibraryItem>());
		break;
	case 2:
		shelf1->setSearch(new SearchByYear<LibraryItem>());
		break;
	case 3:
		shelf1->setSearch(new SearchByAuthor<LibraryItem>());
		break;
	case 4:
		shelf1->setSearch(new SearchByTag<LibraryItem>());
		break;
	case 5:
		shelf1->setSearch(new SearchByIdentifier<LibraryItem>());
		break;
	default:
		cout << "\n\t\tWrong Option!" << endl;
		break;
	}

	// get search result
	string tmpString;
	cout << "\n\t\tEnter the content: ";
	cin.ignore();
	getline(cin, tmpString);
	searchResult = shelf1->search(tmpString, searchResult);

	for (auto& i : searchResult) std::cout << "\n\t\t" << i->getName()  << std::endl;
	delete shelf1;
}

void Student::addDebt(string NetID, int amount) {

	vector<vector<std::string>> tmp;
	vector<vector<std::string>> tmp2;

	std::ifstream indataFile(RECORD_FILE, ios::in);
	for (std::string row_line; std::getline(indataFile, row_line);)
	{
		tmp.emplace_back();
		tmp2.emplace_back();
		std::istringstream row_stream(row_line);
		for (std::string column; std::getline(row_stream, column, ',');) {
			if (row_line.find(NetID) != string::npos) {
				tmp.back().push_back(column);
			}
			else {
				tmp2.back().push_back(column);
			}
		}
	}
	indataFile.close();

	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

	int oldamount = std::stoi(tmp.at(0).at(0));
	int totalamount = amount + oldamount;

	tmp.at(0).at(0) = to_string(totalamount);

	// Save all string to the file
	std::ofstream outdataFile(RECORD_FILE, ios::out);

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < tmp.at(i).size(); j++) {
			outdataFile << tmp.at(i).at(j) << ",";
		}
	}
	outdataFile << endl;
	outdataFile.close();


	sort(tmp2.begin(), tmp2.end());
	reverse(tmp2.begin(), tmp2.end());
	tmp2.erase(unique(tmp2.begin(), tmp2.end()), tmp2.end());

	std::ofstream olddataFile(RECORD_FILE, ios::app);

	for (int i = 0; i < tmp2.size(); i++) {
		for (int j = 0; j < tmp2.at(i).size(); j++) {
			olddataFile << tmp2.at(i).at(j) << ",";
		}
		olddataFile << endl;
	}

	olddataFile.close();
}

void Student::showDebt(string NetID) {

	vector<std::string> tmp;

	std::ifstream indataFile(RECORD_FILE, ios::in);
	for (std::string row_line; std::getline(indataFile, row_line);)
	{
		std::istringstream row_stream(row_line);
		for (std::string column; std::getline(row_stream, column, ',');) {
			if (row_line.find(NetID) != string::npos) {
				tmp.push_back(column);
			}
		}
	}
	indataFile.close();

	cout << "\n\t\tCurrent Debt: " << tmp.at(0) << endl;;
}

void Student::accurateSearch(string name) {

	std::ifstream indataFile(ITEM_FILE, std::ios::in);

	if (indataFile.is_open()) {
		while (getline(indataFile, line)) {
			if (line.find(name) != string::npos) {
				stringstream ss(line);

				string tmp1;
				getline(ss, tmp1, ',');
				cout << "\n\t\tName: " << tmp1 << endl;

				string tmp2;
				getline(ss, tmp2, ',');
				cout << "\n\t\tPublished Year: " << tmp2 << endl;

				string tmp3;
				getline(ss, tmp3, ',');
				cout << "\n\t\tAuthor: " << tmp3 << endl;

				string tmp4;
				getline(ss, tmp4, ',');
				cout << "\n\t\tTag: " << tmp4 << endl;
				
				if (line.find("Avail") != string::npos) {
					cout << "\n\t\tThis Item is currently borrowable." << endl;
				}
				else {
					cout << "\n\t\tThis Item is currently unavailable." << endl;
				}
			}
		}
	}
	indataFile.close();

}