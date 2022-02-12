#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
//#include <vector>

#define RECORD_FILE "record.txt"
//#define PASSWORD_FILE "password.txt"

using namespace std;

class Newuser {
public:
	Newuser() {};
	//void saveFile();
	//void checkFile();
	void registration();
	//bool isRegistered();

private:
	string NetID;
	string password;
	string studentName;
	string email;
};

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

int main() {

	Newuser u;

	// check if there is a record.txt exists
	// False -> create new record.txt file
	ifstream indataFile(RECORD_FILE);
	if (!indataFile) {
		ofstream outdataFile(RECORD_FILE, ios::out);
		outdataFile << "NetID: , Name: , Password:"<<endl;		
		outdataFile.close();
	}

	cout << "************************************************************************************************" << endl;
	cout << "\t\t\t\tWelcome to registratin system!" << endl;
	cout << "************************************************************************************************" << endl;

	u.registration();

	return 0;
}
