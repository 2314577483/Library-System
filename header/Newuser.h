#ifndef __NEWUSER_H__
#define __NEWUSER_H__

#include "User.h"

namespace us {
	class Newuser : public User {
	private:
		std::string NetID;
		std::string password;
		std::string studentName;
		std::string email;
		std::vector<User*> userList;

	public:
		Newuser();
		void insertInfo();
		bool isRegistered(NetID);

	};
}
#endif