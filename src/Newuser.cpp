#include "..\header\Newuser.h"

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

// read file and find if there has a NetID is same as user input
bool Newuser::isRegistered(string NetID) {
	std::ifstream indataFile(RECORD_FILE, std::ios::in);
	string line;
	if (indataFile.is_open()) {
		while (getline(indataFile, line, ',')) {
			if (line.find(NetID) != string::npos) {
				return 1;
			}
		}
	}
	indataFile.close();
	return 0;
}

// save info to the file
void Newuser::saveFile() {

	std::ofstream outdataFile(RECORD_FILE, std::ios::app);

	for (int i = 0; i < users.size(); i++) {
		outdataFile << users.at(i) << ",";
	}
	outdataFile << endl;
	outdataFile.close();
}