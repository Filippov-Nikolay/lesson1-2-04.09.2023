#include <iostream>
#include "EmployeeInfo.h"
#include "EmployeeInfoFile.h"

using namespace std;

int main() {
	setlocale(0, "");

	// MENU

	int quantity = 0;
	int numberEmployees = 0;

	// �������� �� ������������ �����
	cout << "������� ���-�� �����������: ";
	cin >> quantity;

	numberEmployees = quantity;

	employee* newEmployee = new employee[numberEmployees];

	// ������
	for (int i = 0; i < numberEmployees; i++)
		inputEmployee(newEmployee[i]);
	cout << endl << endl;

	// ������
	for (int i = 0; i < numberEmployees; i++)
		printEmployee(newEmployee[i]);
	cout << endl << endl;


	sortByLastName(newEmployee, numberEmployees);

	// ������
	for (int i = 0; i < numberEmployees; i++)
		printEmployee(newEmployee[i]);
	cout << endl << endl;

	/*

	// ������ � ����
	for (int i = 0; i < numberEmployees; i++)
		fileWrite(newEmployee[i]);

	// ������ �����
	cout << "\nFile info: " << endl;
	fileRead();

	// ���������� ���������� (�������� ������������)
	cout << "������� ������� ����� �������� ����� �����������: ";
	cin >> quantity;

	for (int i = 0; i < quantity; i++) {
		cout << "Check1" << endl;

		addEmployee(newEmployee, numberEmployees, quantity);
	}
	
	*/

	delete newEmployee;
	newEmployee = nullptr;

	return 0;
}