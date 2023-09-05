#include <iostream>
#include <string>
#include "EmployeeInfo.h"

using namespace std;

// ������� �� ���������� ����������
void inputEmployee(employee& newEmployee) {
	char* temp = new char[126];

	/*
	do {
		cout << "���: ";
		cin >> newEmployee.firstName;
	} while (onlyLetters(newEmployee.firstName));
	*/

	do {
		cout << "�������: ";
		cin >> newEmployee.lastName;
	} while (onlyLetters(newEmployee.lastName));
	
	/*
	do {
		cout << "����� ��������: ";
		cin >> newEmployee.phoneNumber;
	} while (onlyDigits(newEmployee.phoneNumber) || numberOfCharacters(newEmployee.phoneNumber));

	do {
		do {
			cout << "��������: ";
			cin >> temp;
		} while (onlyDigits(temp));
		newEmployee.salary = stod(temp);

		if (newEmployee.salary <= 0)
			cout << "����� ������ ���� ������ 0!" << endl << endl;
	} while (newEmployee.salary <= 0);
	*/
}


// ������� �� ������ ����������
void printEmployee(const employee& newEmployee) {
	// cout << "���: " << newEmployee.firstName << endl;
	cout << "�������: " << newEmployee.lastName << endl;
	// cout << "����� ��������: " << newEmployee.phoneNumber << endl;
	// cout << "��������: " << newEmployee.salary << endl;
}


// ��������
// ������� �� ���������� ����������
void addEmployee(employee* oldEmployee, int oldNumberEmployee, int newNumberEmployee) {
	cout << "Check1" << endl;
	int numberEmployees = oldNumberEmployee + newNumberEmployee;
	employee* addEmployee = new employee[numberEmployees];

	cout << "���-�� ����������� (��� + ���): " << numberEmployees << endl;

	cout << "Check2" << endl;
	for (int i = 0; i < oldNumberEmployee; i++) {
		if (i != numberEmployees) {
			addEmployee[i] = oldEmployee[i];
		}
	}
	cout << "Check3 - 100%" << endl;

	for (int i = newNumberEmployee; i < numberEmployees; i++) {
		inputEmployee(addEmployee[i]);
	}

	for (int i = 0; i < numberEmployees; i++) {
		printEmployee(addEmployee[i]);
	}
}

// ������� ��� ��������� ����� �� ��������
int compareStrings(char* a, char* b) {
	cout << "compareStrings: " << a << " " << b << endl;

	while (*a == *b) {
		++a;
		++b;
	}
	return *a - *b;
}

// ������� �� ���������� �� �������
void sortByLastName(employee* sortLastName, int size) {

	cout << "Check 1" << endl;

	for (int i = 1; i < size; i++) {
		char* current = sortLastName[i].lastName;
		int j = i - 1;

		cout << "Check: " << sortLastName[i].lastName << endl;

		while (j >= 0 && compareStrings(sortLastName[j].lastName, current) > 0) {
			sortLastName[j + 1].lastName = sortLastName[j].lastName;
			--j;
		}

		sortLastName[j + 1].lastName = current;
	}	

	cout << "Last check!" << endl;
}


// �������� �� ������������ ����� ������
bool onlyLetters(const char* content) { // ������ �����
	for (int i = 0; i < strlen(content); i++) {
		if (isdigit(content[i])) {
			cout << "�� ����� ������������ ������!" << endl << endl;
			return true;
		}
	}

	return false;
}
bool onlyDigits(const char* content) { // ������ �����
	for (int i = 0; i < strlen(content); i++) {
		if (isalpha(content[i]) || content[i] == ' ') {
			cout << "�� ����� ������������ ������!" << endl << endl;
			return true;
		}
	}

	return false;
}
bool numberOfCharacters(const char* content) { // ���-�� ��������
	if (strlen(content) < 8) {
		cout << "����� ������ ���� �� ����� 8 ��������!" << endl << endl;
		return true;
	}
	else if (strlen(content) > 10) {
		cout << "����� ������ ���� �� ������ 10 ��������!" << endl << endl;
		return true;
	}

	return false;
}