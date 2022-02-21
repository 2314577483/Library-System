#include "Newuser.h"

using namespace us;

Newuser::Newuser() {
	NetID = "";
	password = "";
	email = "";
	studentName = "";
	userList.clear();
}

void Newuser::insertInfo() {
	userList.push_back();
}

bool Newuser::isRegistered(NetID) {
	for (auto it = userList.begin(); it != userlist.end(); ++it) {
		if (*it == NetID) {
			return True;
		}
		else
			return False;
	}
}


void Newuser::registration() {

	ifstream indataFile(RECORD_FILE, ios::in);
	ofstream outdataFile(RECORD_FILE, ios::app);

	string tempNetID;
	string tempPassword;

	cout << "Please enter the NetID: ";
	cin >> tempNetID;
	if (indataFile.is_open()) {
		// verify if the input from user is exist
		while (getline(indataFile, NetID)) {
			if (NetID.find(tempNetID, 0) != string::npos) {
				cout << "This account is already regitered, please try anohter one!" << endl;
				cin.ignore();
				registration();
			}
			else {
				NetID = tempNetID;
				outdataFile << "NetID: " << NetID;
			}
			indataFile.close();
		}
	}
	cin.ignore();

	cout << "Please enter your full name: ";
	getline(cin, studentName);
	outdataFile << ", Name: " << studentName;

	//cout << "Please enter your UCR email address: ";
	//cin >> email;
	//outdataFile << ", email: " << email;

	cout << "Please set your password: ";
	cin >> password;
	cout << "Please confirm your password: ";
	cin >> tempPassword;

	// Match two input if they are equal. if not, require to input again. Otherwise, save password to the record.txt
	if (tempPassword != password) {
		cout << "Two input password must be consistent!" << endl;
		cout << "Please confirm your password again: ";
		cin >> tempPassword;
	}
	else {
		outdataFile << ", Password: " << password << endl;
		cout << "Successfully Registered!" << endl;
	}

	outdataFile.close();
}



