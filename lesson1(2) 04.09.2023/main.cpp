#include <iostream>
#include "EmployeeInfo.h"
#include "EmployeeInfoFile.h"

using namespace std;

int main() {
	setlocale(0, "");

	// MENU
	char* temp = new char[100];
	char* UsCh = new char[strlen(temp)];
	employee* newEmployee = nullptr;
    int userChoice = 0;
	int quantity = 0;
	int numberEmployees = 0;
	int maxSalary = 0, minSalary = 0;

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

	do {
		// ��������
		do {
			cout << "����: ";
			cin >> temp;
			UsCh = new char[strlen(temp)];
		} while (onlyDigits(UsCh));


		if (userChoice == 0) {
			cout << "�� ��������!" << endl;
			break;
		}
		else if (userChoice < 0 || userChoice > 8) {
			cout << "�� ����� �������� ����� ����!" << endl << endl;
		}
		else {
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
				// ������� �� �������� ����������
				deleteEmployee(newEmployee, numberEmployees);
			}
			else if (userChoice == 4) {
				// ������� �� ���������� �� �������
				sortByLastName(newEmployee, numberEmployees);
			}
			else if (userChoice == 5) {
				// ������� �� ����� �� ��������� ��������
				searchBySalaryRange(newEmployee, numberEmployees, minSalary, maxSalary);
			}
			else if (userChoice == 6) {
				// ������� �� ����� �� �������

				cout << "������� ����: ";
				cin >> temp;

				char* key = new char[strlen(temp)];
				key = temp;

				searchByLastName(newEmployee, numberEmployees, key);

				delete[] key;
				key = nullptr;
			}
			else if (userChoice == 7) {
				// ������ � ����
				for (int i = 0; i < numberEmployees; i++)
					fileWrite(newEmployee[i]);
			}
			else if (userChoice == 8) {
				// ������ �� �����
				cout << "\nFile info: " << endl;
				fileRead();
			}
		}
	} while (userChoice != 0);
	
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

	delete newEmployee;
	newEmployee = nullptr;

	return 0;
}