#include "Newuser.h"

void Newuser::openFile() {
	ofstream outFile;
	outFile.open("record.txt", ios::out);


	for (int i = 0; i < scount; i++) {
		outFile << user[i].NetID << user[i].password << endl;
	}

	outFile.close();
}

void Newuser::checkFile() {
	ifstream inFile;
	inFile.open("record.txt", ios::in);

	int scount = 0;

	for (int i = 0; !inFile.eof(); i++) {
		inFile >> user[i].NetID;
		inFile >> user[i].password;
		scount++;
	}
	scount--;
	inFile.close();
}

void Newuser::registration() {
	string pw1;
	string pw2;

	cout << "Please enter the NetID: ";
	cin >> NetID;
	cout << "Please enter the password: ";
	cin >> pw1;
	cout << "Please enter the password again: ";
	cin >> pw2;

	if (pw1 != pw2) {
		cout << "Two input password must be consistent!" << endl;
		cout << "Please enter the password again: ";
		cin >> pw2;
	}

	openFile();

}



//bool Newuser::isRegistered() {
//
//{


