
#ifndef DEBT_H
#define DEBT_H

#include "../header/Student.h"

using namespace std;

class Debt : public Student {
private:
	int debt;

public:
	void addDebt(int tmp) { debt += tmp; }
	void withdrawDebt(int tmp) { debt -= tmp; }

	int getDebt() { return debt; }

};

#endif // !DEBT_H

