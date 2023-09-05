#include <iostream>
#include "EmployeeInfo.h"
#include "EmployeeInfoFile.h"

using namespace std;

int main() {
	setlocale(0, "");

	// MENU

	int quantity = 0;

	cout << "¬ведите кол-во сотрудников: ";
	cin >> quantity;

	employee* newEmployee = new employee[quantity];

	for (int i = 0; i < quantity; i++)
		inputEmployee(newEmployee[i]);
	cout << endl;

	for (int i = 0; i < quantity; i++)
		printEmployee(newEmployee[i]);
	cout << endl;

	

	cout << "\nFile info: " << endl;
	fileWrite(newEmployee);
	fileRead();

	delete newEmployee;
	newEmployee = nullptr;

	return 0;
}