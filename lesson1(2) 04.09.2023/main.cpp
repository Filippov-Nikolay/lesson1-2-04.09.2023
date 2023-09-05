#include <iostream>
#include <string>
#include "EmployeeInfo.h"
#include "EmployeeInfoFile.h"

using namespace std;

int main() {
	setlocale(0, "");

	// MENU
	char* temp = new char[100];
	char* key = new char[strlen(temp)];
	employee* newEmployee = nullptr;

    int userChoice = 0;
	int quantity = 0;
	int numberEmployees = 0;
	int maxSalary = 0, minSalary = 0;
	int minNumberMenu = 0, maxNumberMenu = 8;

	bool flag = false;

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
		do {
			cout << "����: ";
			cin >> temp;
		} while (onlyDigits(temp));
		userChoice = atoi(temp);

		if (userChoice == 0) {
			cout << "\n�� ��������!" << endl;
			break;
		}
		else if (userChoice < minNumberMenu || userChoice > maxNumberMenu) {
			cout << "�� ����� �������� ����� ����!" << endl << endl;
		}
		else {
			if (userChoice == 1) {
				// �������� �� ������������ �����
				cout << "\n������� ���-�� �����������: ";
				cin >> quantity;

				numberEmployees = quantity;

				newEmployee = new employee[numberEmployees];

				// ������
				for (int i = 0; i < numberEmployees; i++) {
					cout << "\n������� ���������� � " << i + 1 << "� ����������:" << endl;
					inputEmployee(newEmployee[i]);
					cout << endl;
				}
				cout << endl;

				flag = true;
			}

			if (!flag) {
				cout << "����� ������� 1� ����� ����!" << endl << endl;
			}
			else {
				if (userChoice == 2) {
					// ������/�����
					cout << endl;
					for (int i = 0; i < numberEmployees; i++) {
						printEmployee(newEmployee[i]);
						cout << endl;
					}
					cout << endl;
				}
				else if (userChoice == 3) {
					// ������� �� �������� ����������
					deleteEmployee(newEmployee, numberEmployees);
					cout << endl;
				}
				else if (userChoice == 4) {
					// ������� �� ���������� �� �������
					sortByLastName(newEmployee, numberEmployees);
				}
				else if (userChoice == 5) {
					// ������� �� ����� �� ��������� ��������
					do {
						cout << "������� �������� ��: ";
						cin >> temp;
					} while (onlyDigits(temp));
					minSalary = stod(temp);
					
					do {
						cout << "������� �������� ��: ";
						cin >> temp;
					} while (onlyDigits(temp));
					maxSalary = stod(temp);
					
					cout << endl;
					searchBySalaryRange(newEmployee, numberEmployees, minSalary, maxSalary);
				}
				else if (userChoice == 6) {
					// ������� �� ����� �� �������

					cout << "������� ����: ";
					cin >> temp;

					key = new char[strlen(temp)];
					key = temp;

					cout << endl;
					searchByLastName(newEmployee, numberEmployees, key);
					cout << endl;
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

	delete[] key;
	key = nullptr;

	delete newEmployee;
	newEmployee = nullptr;

	return 0;
}