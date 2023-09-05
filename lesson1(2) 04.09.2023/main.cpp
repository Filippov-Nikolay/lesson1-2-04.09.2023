#include <iostream>
#include "EmployeeInfo.h"
#include "EmployeeInfoFile.h"

using namespace std;

int main() {
	setlocale(0, "");

	// MENU
	int userChoice = 0;
	int quantity = 0;
	int numberEmployees = 0;

	cout << "����: " << endl;
	cout << "1. ���� ������ � �����������" << endl;
	cout << "2. ����� ������ � ����������� (����)" << endl;
	cout << "3. �������� ����������" << endl;
	cout << "4. ���������� �� ������� �����������" << endl;
	cout << "5. ����� �� �� �����������" << endl;
	cout << "6. ����� �� ������� �����������" << endl;
	cout << "7. ������ ������ � ����������� � ��������� ����" << endl;
	cout << "8. ����� ������ � ����������� �� ���������� �����" << endl;
	// cout << "9. ���������� ����������(��)" << endl;
	cout << "0. �����" << endl;

	cout << "����: ";
	cin >> userChoice;
	

	employee* newEmployee = nullptr;

	if (userChoice == 1) {
		// �������� �� ������������ �����
		cout << "������� ���-�� �����������: ";
		cin >> quantity;

		numberEmployees = quantity;

		newEmployee = new employee[numberEmployees];

		// ������
		for (int i = 0; i < numberEmployees; i++)
			inputEmployee(newEmployee[i]);
		cout << endl << endl;
	}
	else if (userChoice == 2) {
		// ������
		for (int i = 0; i < numberEmployees; i++)
			printEmployee(newEmployee[i]);
		cout << endl << endl;
	}
	else if (userChoice == 3) {
		// ������� �� ���������� �� �������
		sortByLastName(newEmployee, numberEmployees);
	}
	else if (userChoice == 4) {
		
	}

	deleteEmployee(newEmployee, numberEmployees);

	// ������
	for (int i = 0; i < numberEmployees; i++)
		printEmployee(newEmployee[i]);
	cout << endl << endl;

	

	

	

	
	/*

	// ���������� ���������� (�������� ������������)
	cout << "������� ������� ����� �������� ����� �����������: ";
	cin >> quantity;

	newEmployee = new employee[numberEmployees+=quantity];

	cout << "-numberEmployees: " << numberEmployees << endl;

	for (int i = 0; i < quantity; i++) {
		addEmployee(newEmployee, numberEmployees, quantity);
	}

	// ������
	for (int i = 0; i < numberEmployees; i++)
		printEmployee(newEmployee[i]);
	cout << endl << endl;
	*/
	/*

	// ������ � ����
	for (int i = 0; i < numberEmployees; i++)
		fileWrite(newEmployee[i]);

	// ������ �����
	cout << "\nFile info: " << endl;
	fileRead();

	// ������
	for (int i = 0; i < numberEmployees; i++)
		printEmployee(newEmployee[i]);
	cout << endl << endl;
	
	
	*/

	delete newEmployee;
	newEmployee = nullptr;

	return 0;
}