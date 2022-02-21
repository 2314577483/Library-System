
#ifndef DEBT_H
#define DEBT_H

#include "../header/Student.h"

using namespace lb;
using namespace std;

class Debt : public Student {
private:
	int debt;
	int loan;  // do we need both?

public:
	void addDebt();
	void withdrawDebt();

	int getDebt() { return debt; }
	
	void payLoan();

	// Since we can not really extract money and store it in the system, do we really need this class?
};

#endif // !DEBT_H

