#include <iostream>
#include <string>
#include "../src/Newuser.cpp"
#include "../header/Student.h"
#include "../header/Librarian.h"
#include "../header/LibraryUser.h"

using namespace std;


int main() {

}

void superMenu() {
	int option;
	string tmpID;
	string tmpPassword;


	do {
		cout << "********************************\n"
			<< "   Welcome to Library System!   \n"
			<< "   Please identify yourself     \n"
			<< "   1. NewUser                   \n"
			<< "   2. Student                   \n"
			<< "   3. Librarian                 \n"
			<< "   4. Quit                      \n"
			<< "********************************\n"
			<< "Please enter your choise: ";
		cin >> option;
		cout << endl;

		switch (option) {
		case 1: {
			Newuser tmpUser = Newuser();
			tmpUser.registration();
			break; }
		case 2:
			cout << "\nPlease enter your NetID: \n";
			cin >> tmpID;
			// if () {} need a way to check if the entered ID exists, checkmark++

			cout << "\nPlease enter your Password: \n";
			cin >> tmpPassword;
			// if () {} need a way to check password, checkmark++

			studentMenu(tmpID, tmpPassword); // if checkmark = 2

			break;
		case 3:
			cout << "\nPlease enter your NetID: \n";
			cin >> tmpID;
			// if () {} need a way to check if the entered ID exists, checkmark++

			cout << "\nPlease enter your Password: \n";
			cin >> tmpPassword;
			// if () {} need a way to check password, checkmark++

			librarianMenu(tmpID, tmpPassword); // if checkmark = 2

			break;
		case 4:
			cout << "Having Fun ...!" << endl;
			break;
		default:
			cout << "  WRONG OPTION!\n";
		}

	} while (option != 4);

	
}

void studentMenu(string ID, string password) {
	int option;
	Student tmp = Student(ID, password);

	do {
		cout << "********************************\n"
			<< "   Welcome to Student Menu!     \n"
			<< "   1. Search Book               \n"
			<< "   2. Borrow Book               \n"
			<< "   3. Return Book               \n"
			<< "   4. Reset Password            \n"
			<< "   5. Quit                      \n"
			<< "********************************\n"
			<< "Please enter your choise: ";
		cin >> option;
		cout << endl;

		switch (option) {
		case 1:
			// do we need searchBook()?

			break;
		case 2:
			tmp.getBook();
			break;
		case 3:
			tmp.returnBook();
			break;
		case 4:
			tmp.resetPassword();
			break;
		case 5:
			cout << "Having Fun ...!" << endl;
			break;
		default:
			cout << "  WRONG OPTION!\n";
		}
	} while (option != 5);
}

void librarianMenu(string ID, string password) {
	int option;
	Librarian tmp = Librarian(ID, password);

	do {
		cout << "********************************\n"
			<< "   Welcome to Librarian Menu!   \n"
			<< "   1. Manage Book               \n"
			<< "   2. Reset Password            \n"
			<< "   3. Quit                      \n"
			<< "********************************\n"
			<< "Please enter your choise: ";
		cin >> option;
		cout << endl;

		switch (option) {
		case 1:
			tmp.manageBook();

			break;
		case 2:
			tmp.resetPassword();
			break;
		case 3:
			cout << "Having Fun ...!" << endl;
			break;
		default:
			cout << "  WRONG OPTION!\n";
		}
	} while (option != 3);
}