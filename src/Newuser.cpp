#include "Newuser.h"


Newuser::Newuser() {
	NetID = "";
	password = "";
	email = "";
	studentName = "";
	userList.clear();
}

void Newuser::insertInfo(Newuser* item) {
	userList.push_back(item);
}

bool Newuser::isRegistered(Newuser* NetID) {
	std::fstream indataFile(RECORD_FILE, std::ios::in);
	for (auto it = userList.begin(); it != userList.end(); ++it) {
		if (*it == NetID) {
			return 1;
		}
		else
			return 0;
	}
	indataFile.close();
}

void Newuser::saveFile() {

	std::ofstream outdataFile(RECORD_FILE, std::ios::app);
	for (auto it = userList.begin(); it != userList.end(); ++it) {
		outdataFile << studentName << NetID << email << password << std::endl;
	}

	outdataFile.close();
}

void Newuser::registration() {

	std::cout << "Please enter the name: ";
	std::cin >> studentName;


	std::cout << "Please enter the NetID: ";
	std::cin >> NetID;

	std::cout << "Please enter the email: ";
	std::cin >> email;


}



//int main() {
//
//	Newuser user1;
//	user1.registration();
//	
//	
//	return 0;
//}


