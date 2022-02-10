#include "Newuser.h"

void Newuser::saveFile() {
	vector<string>record;

	ofstream outUFile;
	ofstream outPFile;
	outUFile.open(USERNAME_FILE, ios::app); // open username.txt and update text
	outPFile.open(PASSWORD_FILE, ios::app); // open password.txt and update text

	// save user input

	outUFile << NetID << endl;
	outPFile << password << endl;

	outUFile.close();	// close username.txt
	outPFile.close();	// close password.txt
}

void Newuser::checkFile() {
	ifstream inPFile;
	ifstream inUFile;


	inUFile.open(USERNAME_FILE, ios::in); 	// open username.txt
	inPFile.open(PASSWORD_FILE, ios::in); 	// open password.txt


	inPFile.close();	// close username.txt
	inPFile.close();	// close password.txt
}

void Newuser::registration() {
	string pw2;

	cout << "Please enter the NetID: ";
	cin >> NetID;
	cout << "Please enter the password: ";
	cin >> password;
	cout << "Please enter the password again: ";
	cin >> pw2;

	if (password != pw2) {
		int i = 0;
		while (i != 3) {
			cout << "Two input password must be consistent!" << endl;
			cout << "Please enter the password again: ";
			cin >> pw2;
			i++;
		}
	}
	else {
		cout << "Successfully Registered!" << endl;
		saveFile();
	}

}



//bool Newuser::isRegistered() {
//
//{


