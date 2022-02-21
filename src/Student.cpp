#include <iostream>
#include "../header/Student.h"
#include "../header/Shelf.h"
#include "../header/Book.h"

using namespace lb;

void Student::resetPassword() {
	string tmp;
	string tmpPassword;

	if (this->isLogined() == true) {
		cout << "Please Enter the new password: \n";
		cin >> tmp;
		while (tmp == this->password) {
			cout << "You can not have the same password as previous one! Please re-enter: \n";
			cin >> tmp;
		}

		cout << "Please Enter the new password again: \n";
		cin >> tmpPassword;
		while (tmp != tmpPassword) {
			cout << "Two input password must be consistent! Please re-enter: \n";
			cin >> tmpPassword;
		}

		// Still need a way to write the new password into RECORD (need to fit the NetID)

		this->password = tmp;

		cout << "Successfully reseted your password." << endl;
	}
}

Shelf* Student::getBook() {
	// Where are the Books stored?
	// If we have a txt file, need a way to search the whole file.
	// Find the book and set BookStatus to 3 or 4.
}

void Student::returnBook() {
	// Where are the Books stored?
	// If we have a txt file, need a way to search the whole file.
	// Find the book and set BookStatus to 1.
}