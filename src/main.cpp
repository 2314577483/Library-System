#include "../header/Newuser.h"
#include "../header/User.h"
#include "../header/Student.h"
#include "../header/Librarian.h"
//#include "windows.h"


#include <chrono>
#include <thread>
#include <iostream>

void SuccessfullyLogoutDisplayMenu() {
	system("cls");
	cout << "\n\t\t*************************************************\n";
	cout << "\t\t*                                               *\n";
	cout << "\t\t**         Successfully log out!               **\n";
	cout << "\t\t*                                               *\n";
	cout << "\t\t*************************************************\n";
}

void SuccessfullyResetPasswordDisplayMenu() {
	system("cls");
	cout << "\n\t\t*************************************************\n";
	cout << "\t\t*                                               *\n";
	cout << "\t\t*          Successfully reset password!         *\n";
	cout << "\t\t*                                               *\n";
	cout << "\t\t*           Please wait a moment...             *\n";
	cout << "\t\t*************************************************\n";

	this_thread::sleep_for(chrono::milliseconds(2000));
}

void SuccessfullyLoginDisplayMenu() {
	system("cls");
	cout << "\n\t\t*************************************************\n";
	cout << "\t\t*                                               *\n";
	cout << "\t\t*            Successfully Login!                *\n";
	cout << "\t\t*                                               *\n";
	cout << "\t\t*           Please wait a moment...             *\n";
	cout << "\t\t*************************************************\n";

	this_thread::sleep_for(chrono::milliseconds(2000));
}

vector<std::string> addItem() {
	vector<std::string> tmpVector;
	string tmpName;
	string tmpYear;
	string tmpAuthor;
	string tmpID;
	string tmpDes;
	string tmpTag;
	string tmpCont;
	string tmpAvail;
	string tmpShelf;
	string tmpLocation;

	cout << "\n\t\tPlease Enter the Name of the Item: ";
	cin.ignore();
	getline(cin, tmpName);
	tmpVector.push_back(tmpName);
	cout << "\n\t\tPlease Enter the published year of the Item: ";
	cin >> tmpYear;
	tmpVector.push_back(tmpYear);
	cout << "\n\t\tPlease Enter the Author of the Item: ";
	cin.ignore();
	getline(cin, tmpAuthor);
	tmpVector.push_back(tmpAuthor);
	cout << "\n\t\tPlease Enter the Tag of the Item: ";
	getline(cin, tmpTag);
	tmpVector.push_back(tmpTag);
	cout << "\n\t\tPlease Enter the Identifier of the Item: ";
	getline(cin, tmpID);
	tmpVector.push_back(tmpID);
	cout << "\n\t\tPlease Enter the description of the Item: ";
	getline(cin, tmpDes);
	tmpVector.push_back(tmpDes);
	cout << "\n\t\tPlease Enter the simple content of the Item: ";
	getline(cin, tmpCont);
	tmpVector.push_back(tmpCont);
	cout << "\n\t\tPlease Enter the availability of the Item: ";
	getline(cin, tmpAvail);
	tmpVector.push_back(tmpAvail);
	cout << "\n\t\tWhich shelf would you like to put the Item on?  ";
	getline(cin, tmpShelf);
	tmpVector.push_back(tmpShelf);
	cout << "\n\t\tWhere would you like to put your Item on the shelf? ";
	getline(cin, tmpLocation);
	tmpVector.push_back(tmpLocation);

	return tmpVector;
}

void AddItemMenu(Librarian user) {
	int choice;
	vector<std::string> tmpVector;
	string tmp;

	do {
		cout << "\t\t********************************************\n";
		cout << "\t\t*                                          *\n";
		cout << "\t\t**          1.Add Book                    **\n";
		cout << "\t\t**          2.Add Article                 **\n";
		cout << "\t\t**          3.Add Video                   **\n";
		cout << "\t\t**          0.Quit                        **\n";
		cout << "\t\t*                                          *\n";
		cout << "\t\t********************************************\n";
		cout << "\n\t\tPlease enter your choice: ";
		cin >> choice;

		

		switch (choice) {
		case 1:
			tmpVector = addItem();
			user.addBook(tmpVector);
			break;
		case 2:
			tmpVector = addItem();
			user.addArticle(tmpVector);
			break;
		case 3:
			tmpVector = addItem();
			user.addVideo(tmpVector);
			break;
		case 0:
			SuccessfullyLogoutDisplayMenu();
			break;
		default:
			cout << "\t\tWrong Input!" << endl;
		}

	} while (choice != 0);
}

void LibraianFunctionDsiplayMenu() {
	cout << "\n\t\t********************************************\n";
	cout << "\t\t*                                          *\n";
	cout << "\t\t**      Welcome to the library system!    **\n";
	cout << "\t\t**          1.Remove Account              **\n";
	cout << "\t\t**          2.Display Account Detail      **\n";
	cout << "\t\t**          3.Reset Password              **\n";
	cout << "\t\t**          4.Add Item                    **\n";
	cout << "\t\t**          5.Remove Item                 **\n";
	cout << "\t\t**          0.Quit                        **\n";
	cout << "\t\t*                                          *\n";
	cout << "\t\t********************************************\n";
	cout << "\n\t\tPlease enter your choice: ";
}

void LibraianLoginMenu() {
	Librarian user4;
	string tempNetID;
	string oldPassword;
	string newPassword;

	cout << "\n\t\tPlease enter the NetID: ";
	cin.ignore();
	getline(cin, tempNetID);

	while (tempNetID.find("001") == std::string::npos) {
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "\t\tPlease enter a valid libraian account: ";
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		//	FOREGROUND_GREEN | FOREGROUND_BLUE);
		getline(cin, tempNetID);
	}

	while (user4.isNetIDExisted(tempNetID) != 1) {
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "\t\tAccount is not existed! Please try again: ";
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		//	FOREGROUND_GREEN | FOREGROUND_BLUE);
		cin.ignore();
		getline(cin, tempNetID);
	}

	cout << "\n\t\tPlease enter the password: ";
	getline(cin, oldPassword);
	while (user4.isPasswordMatched(tempNetID, oldPassword) != 1) {
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "\n\t\tThe password is incorrect! Please try again: ";
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		//	FOREGROUND_GREEN | FOREGROUND_BLUE);
		getline(cin, oldPassword);
	}

	// finished login;
	user4.LogIn();

	SuccessfullyLoginDisplayMenu();

	int choice;
	string tmpID;
	do {
		LibraianFunctionDsiplayMenu();
		std::cin >> choice;
		string rAccount;
		string key;
		switch (choice) {
		case 1:
			cout << "\n\t\tPlease enter the NetID you want to remove: ";
			std::cin >> rAccount;

			while (user4.isNetIDExisted(tempNetID) != 1) {
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "\n\t\tAccount is not existed! Please try again: ";
				cin.ignore();
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
				//	FOREGROUND_GREEN | FOREGROUND_BLUE);
				getline(cin, tempNetID);
			}
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << "\n\t\tAttention: Account removal is an irreversible process!";
			cout << "\n\t\tAre you sure to remove this account? (Y/N): ";

			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
			//	FOREGROUND_GREEN | FOREGROUND_BLUE);

			cin >> key;
			if (key == "Y" || key == "y") {
				user4.removeAccount(rAccount);

				system("cls");
				cout << "\t\t*************************************************\n";
				cout << "\t\t*                                               *\n";
				cout << "\t\t**         Successfully remove account!        **\n";
				cout << "\t\t*                                               *\n";
				cout << "\t\t*************************************************\n";
				user4.LogIn();

			}
			else {
				system("cls");
				cout << "\t\t*************************************************\n";
				cout << "\t\t*                                               *\n";
				cout << "\t\t**         Unsuccessfully remove account!      **\n";
				cout << "\t\t*                                               *\n";
				cout << "\t\t*************************************************\n";
				user4.LogIn();
			}
			break;
		case 2:
			cout << "\n\t\t********************************************\n";
			cout << "\t\t*                                          *\n";
			cout << "\t\t*            Account Information           *\n";
			cout << "\t\t*                                          *\n";
			user4.displayAccountDetails(tempNetID);
			cout << "\t\t*                                          *\n";
			cout << "\t\t********************************************\n";

			cout << "\n\t\t"; system("PAUSE");

			user4.LogIn();
			break;
		case 3:
			cout << "\n\t\tPlease enter new password: ";
			cin >> newPassword;
			user4.resetPassword(tempNetID, oldPassword, newPassword);

			SuccessfullyResetPasswordDisplayMenu();
			user4.LogIn();
			break;
		case 4:
			AddItemMenu(user4);
			break;
		case 5:
			cout << "\n\t\tPlease Enter the identifier of the Book: ";
			cin >> tmpID;
			user4.removeItem(tmpID);
			cout << "\n\t\tSuccessfully remove the item!";
			break;
		case 0:
			SuccessfullyLogoutDisplayMenu();
			user4.LogOut();
			break;
		default:
			cout << "\t\tWrong Input!" << endl;
		}
	} while (choice != 0);

}

void StudentFunctionDsiplayMenu() {
	cout << "\n\t\t********************************************\n";
	cout << "\t\t*                                          *\n";
	cout << "\t\t**      Welcome to the library system!    **\n";
	cout << "\t\t**          1.Reset Password              **\n";
	cout << "\t\t**          2.Display Account Detail      **\n";
	cout << "\t\t**          3.Search                      **\n";
	cout << "\t\t**          4.Accurate Search             **\n";
	cout << "\t\t**          5.Borrow an item              **\n";
	cout << "\t\t**          6.Return an item              **\n";
	cout << "\t\t**          7.Show Debt                   **\n";
	cout << "\t\t**          8.Add Debt                    **\n";
	cout << "\t\t**          0.Quit                        **\n";
	cout << "\t\t*                                          *\n";
	cout << "\t\t********************************************\n";
	cout << "\n\t\tPlease enter your choice: ";
}

void StudentLoginMenu() {
	Student user2;

	string tempNetID;
	string oldPassword;


	cout << "\n\t\tPlease enter the NetID: ";
	cin.ignore();
	getline(cin, tempNetID);
	while (user2.isNetIDExisted(tempNetID) != 1) {
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "\n\t\tAccount is not existed! Please try again: ";
		cin.ignore();
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		//	FOREGROUND_GREEN | FOREGROUND_BLUE);
		getline(cin, tempNetID);
	}

	cout << "\n\t\tPlease enter the password: ";
	getline(cin, oldPassword);
	while (user2.isPasswordMatched(tempNetID, oldPassword) != 1) {
		cout << "\n\t\tThe password is incorrect! Please try again: ";
		getline(cin, oldPassword);
	}	

	// finished login;
	user2.LogIn();

	SuccessfullyLoginDisplayMenu();

	// goto stuent function menu
	system("cls");
	
	int choice;
	int searchChoice;
	string tmpName;
	
	do {
		StudentFunctionDsiplayMenu();
		std::cin >> choice;
		string newPassword;
		switch (choice) {
		case 1:
			std::cout << "\n\t\tPlease enter new password: ";
			std::cin >> newPassword;
			//getline(cin, newPassword);
			user2.resetPassword(tempNetID, oldPassword, newPassword);

			SuccessfullyResetPasswordDisplayMenu();
			user2.LogIn();
			break;
		case 2:
			cout << "\n\t\t********************************************\n";
			cout << "\t\t*                                          *\n";
			cout << "\t\t*            Account Information           *\n";
			cout << "\t\t*                                          *\n";
			user2.displayAccountDetails(tempNetID);
			cout << "\t\t*                                          *\n";
			cout << "\t\t********************************************\n";

			cout << "\n\t\t"; system("PAUSE");

			user2.LogIn();
			break;
		case 3:
			cout << "\n\t\t********************************************\n";
			cout << "\t\t*                                          *\n";
			cout << "\t\t*               Search Menu                *\n";
			cout << "\t\t*      1. Search By Name                   *\n";
			cout << "\t\t*      2. Search By Year                   *\n";
			cout << "\t\t*      3. Search By Author                 *\n";
			cout << "\t\t*      4. Search By Tag                    *\n";
			cout << "\t\t*      5. Search By ID                     *\n";
			cout << "\t\t*                                          *\n";
			cout << "\t\t********************************************\n";
			cout << "\t\tEnter the Option: ";
			cin >> searchChoice;
			user2.search(searchChoice);
			
			break;
		case 4:
			cout << "\n\t\tEnter the Name: ";
			cin.ignore();
			getline(cin, tmpName);
			user2.accurateSearch(tmpName);
			break;
		case 5:
			user2.borrowItem(tempNetID);
			break;
		case 6:
			user2.returnItem(tempNetID);
			break;
		case 7:
			user2.showDebt(tempNetID);
			break;
		case 8:
			int money;
			cout << "\n\t\tHow much money you want to add: ";

			cin >> money;

			user2.addDebt(tempNetID, money);

			system("cls");
			cout << "\t\t*************************************************\n";
			cout << "\t\t*                                               *\n";
			cout << "\t\t*            Successfully topup                 *\n";
			cout << "\t\t*                                               *\n";
			cout << "\t\t*           Please wait a moment...             *\n";
			cout << "\t\t*************************************************\n";

			this_thread::sleep_for(chrono::milliseconds(2000));

			user2.LogIn();
			break;
		case 0:
			SuccessfullyLogoutDisplayMenu();
			user2.LogOut();
			break;
		default:
			std::cout << "\t\tWrong Input !" << std::endl;
		}
	} while (choice != 0);

}

void RegisterFunction() {
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
	//	FOREGROUND_GREEN | FOREGROUND_BLUE);

	Newuser user1;

	string tempstudentName, tempNetID, tempEmail, tempPassword;

	// define usertype
	user1.insertInfo("0");
	user1.insertInfo("newuser");
	
	cout << "\n\t\tPlease enter the NetID: ";
	cin >> tempNetID;

	
	if (tempNetID.size() < 7) {
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "\n\t\tInvalid NetID! Please try another one";

		return RegisterFunction();
	}
	else if (user1.isRegistered(tempNetID) == 1) {
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "\n\t\tThis account is registered! Please try another one!";

		return RegisterFunction();
	
	}
	
	cout << "\n\t\tPlease enter the email address: ";
	cin >> tempEmail;
	while (tempEmail.find("@") == std::string::npos) {
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "\n\t\tInvalid email address! Please try another one";
		cin.ignore();
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		//	FOREGROUND_GREEN | FOREGROUND_BLUE);
		cin >> tempEmail;
	}

	cout << "\n\t\tPlease enter the password: ";
	cin >> tempPassword;

	string tempPassword2;
	cout << "\n\t\tPlease confirm the paswword: ";
	cin >> tempPassword2;

	while (tempPassword2 != tempPassword) {
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "\n\t\tTwo input password must be consistent!";
		// set console output color
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		//	FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "\n\t\tPlease confirm the paswword again: ";
		cin >> tempPassword2;
	}

	cout << "\n\t\tPlease enter the name: ";
	cin >> tempstudentName;

	user1.insertInfo(tempstudentName);
	user1.insertInfo(tempNetID);
	user1.insertInfo(tempEmail);
	user1.insertInfo(tempPassword);

	user1.saveFile();

	system("cls");
	cout << "\t\t************************************************\n";
	cout << "\t\t*                                              *\n";
	cout << "\t\t*        Successfully Registered!              *\n";
	cout << "\t\t*        Please reopen program to login.       *\n";
	cout << "\t\t*                                              *\n";
	cout << "\t\t************************************************\n";
	
}

void WelcomeDisplayMenu() {
	cout << "\n\t\t********************************************\n";
	cout << "\t\t*                                          *\n";
	cout << "\t\t**     Welcome to the library system!     **\n";
	cout << "\t\t**               1.Student Login          **\n";
	cout << "\t\t**               2.Libraian Login         **\n";
	cout << "\t\t**               3.Register               **\n";
	cout << "\t\t**               0.Quit                   **\n";
	cout << "\t\t*                                          *\n";
	cout << "\t\t********************************************\n";
	cout << "\n\t\tPlease enter your choice: ";
}

int main() {
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
	//	FOREGROUND_GREEN | FOREGROUND_BLUE);

	User user3;
	int choice;

	do {
		WelcomeDisplayMenu();

		std::cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			cout << "\t\t****************************************************\n";
			cout << "\t\t*                                                  *\n";
			cout << "\t\t**      Welcome to the Student login system!      **\n";
			cout << "\t\t*                                                  *\n";
			cout << "\t\t****************************************************\n";

			StudentLoginMenu();
			break;
		case 2:
			system("cls");
			cout << "\t\t****************************************************\n";
			cout << "\t\t*                                                  *\n";
			cout << "\t\t**     Welcome to the Librarian login system!     **\n";
			cout << "\t\t*                                                  *\n";
			cout << "\t\t****************************************************\n";

			LibraianLoginMenu();
			break;
		case 3:
			system("cls");
			cout << "\t\t********************************************\n";
			cout << "\t\t*                                          *\n";
			cout << "\t\t**     Welcome to the register system!    **\n";
			cout << "\t\t*                                          *\n";
			cout << "\t\t********************************************\n";

			RegisterFunction();
			user3.isLibrarian();
			user3.isStudent();
			break;
		case 0:
			system("cls");
                        cout << "\t\t***************************************************\n";
                        cout << "\t\t*                                                 *\n";
                        cout << "\t\t** Thanks for using our system, have a good day! **\n";
                        cout << "\t\t*                                                 *\n";
                        cout << "\t\t***************************************************\n";

			break;
		default:
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << "\t\tPlease enter a valid key! \n";

			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
			//	FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	} while (choice != 0);

	return 0;
}
