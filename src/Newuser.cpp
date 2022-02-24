#include "Newuser.h"

Newuser::Newuser() {
	NetID = "";
	password = "";
	email = "";
	studentName = "";
}

void Newuser::clear() {
	users.clear();
}

void Newuser::insertInfo(const std::string data) {
	users.push_back(data);
}

//void Newuser::insertList(const std::vector<std::string>& users) {
//	userList.push_back(users);
//}

// read file and find if there has a NetID is same as user input
bool Newuser::isRegistered(string line, string NetID) {
	std::ifstream indataFile(RECORD_FILE, std::ios::in);

	while (getline(indataFile, line)) {
		if (line.find(NetID) != string::npos) {
			return 1;

		}
		else
			return 0;
	}

	indataFile.close();
}

// save info to the file
void Newuser::saveFile() {
	std::ofstream outdataFile(RECORD_FILE, std::ios::app);

	for (int i = 0; i < users.size(); i++) {
		outdataFile << users[i] << " ";
	}

	outdataFile << endl;
	outdataFile.close();
}

void Newuser::printList() {

	for (int i = 0; i < users.size(); i++) {
		cout << users.at(i) << " ";
	}
	cout << endl;

}

