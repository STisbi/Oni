#ifdef _SALES_H
#define _SALES_H

#include <iostream>

class Sales
{
	private:
		std::string mEmployeeName;
		std::string mEmployeeNumber;
		int mPassword = 1234;
	public:
		Sales(std::string aEmployeeName, std::string aEmployeeNumber);
		std::string mEmployee_Info();
};

#endif
