#include "Newuser.h"

Newuser::Newuser() {
	NetID = "";
	password = "";
	email = "";
	studentName = "";
	userList.clear();
}

//void Newuser::insertInfo(Newuser* item) {
//	userList.push_back(item);
//}
//
//bool Newuser::isRegistered(Newuser* NetID) {
//	std::fstream indataFile(RECORD_FILE, std::ios::in);
//	for (auto it = userList.begin(); it != userList.end(); ++it) {
//		if (*it == NetID) {
//			return 1;
//		}
//		else
//			return 0;
//	}
//	
//}


void Newuser::registration() {
	std::ofstream outdataFile(RECORD_FILE, std::ios::app);
	vector<string> tempList;

	std::cout << "Please enter the NetID: ";
	getline(cin, NetID);
	tempList.push_back(NetID);

	std::cout << "Please enter the name: ";
	getline(cin, studentName);
	tempList.push_back(studentName);

	std::cout << "Please enter the email: ";
	std::cin >> email;
	tempList.push_back(email);

	string tempPassword;
	std::cout << "Please enter the password: ";
	std::cin >> tempPassword;

	std::cout << "Please confirm the password: ";
	std::cin >> password;

	while (tempPassword != password) {
		std::cout << "Two input password must be consistent!\n";
		std::cout << "Please enter again: ";
		cin >> password;
	}
	tempList.push_back(password);

	outdataFile << endl;
	for (auto& e : tempList) {
		outdataFile << e << " ";
	}

	outdataFile.close();
	tempList.clear();
}

int main() {
	Newuser user1;
	user1.registration();

	cout << "Successfully registered!" << endl;
	return 0;
}


