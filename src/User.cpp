#include "..\header\User.h"

User::User() {
	userType = 0;
}

//void User::isNewuser() {
//	if (userType == 1)
//		return true;
//	return false;
//}

void User::isStudent() {
	vector<vector<std::string>> tmp;

	std::ifstream indataFile(RECORD_FILE, ios::in);
	for (std::string row_line; std::getline(indataFile, row_line);)
	{
		tmp.emplace_back();
		std::istringstream row_stream(row_line);
		for (std::string column; std::getline(row_stream, column, ',');) {
			if (row_line.find("@ucr.edu") != string::npos) {
				if (column.find("newuser") != string::npos) {
					column.replace(column.begin(), column.end(), "Student");
				}
			}
			tmp.back().push_back(column);
		}
	}
	indataFile.close();



	// Save all string to the file
	std::ofstream outdataFile(RECORD_FILE, ios::out);

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < tmp.at(i).size(); j++) {
			outdataFile << tmp.at(i).at(j) << ",";
		}
		outdataFile << endl;
	}

	outdataFile.close();
}

void User::isLibrarian() {

	vector<vector<std::string>> tmp;

	std::ifstream indataFile(RECORD_FILE, ios::in);
	for (std::string row_line; std::getline(indataFile, row_line);)
	{
		tmp.emplace_back();
		std::istringstream row_stream(row_line);
		for (std::string column; std::getline(row_stream, column, ',');) {
			if (row_line.find("001@ucr.edu") != string::npos) {
				if (column.find("newuser") != string::npos) {
					column.replace(column.begin(), column.end(), "Librarian");
				}
			}
			tmp.back().push_back(column);
		}
	}
	indataFile.close();



	// Save all string to the file
	std::ofstream outdataFile(RECORD_FILE, ios::out);

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < tmp.at(i).size(); j++) {
			outdataFile << tmp.at(i).at(j) << ",";
		}
		outdataFile << endl;
	}

	outdataFile.close();

}