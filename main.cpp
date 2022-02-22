#include "Newuser.h"


int main() {
	Newuser user1;

	user1.insertInfo("Zhenjie Liu");
	user1.insertInfo("12345");
	user1.insertInfo("12345@ucr.edu");
	user1.insertInfo("aa123456");


	user1.saveFile();

	user1.clear();

	return 0;
}

