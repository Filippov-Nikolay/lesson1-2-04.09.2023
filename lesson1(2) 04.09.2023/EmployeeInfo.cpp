#include <iostream>
#include <string>
#include "EmployeeInfo.h"

using namespace std;

// ������� �� ���������� ����������
void inputEmployee(employee& newEmployee) {
	char* temp = new char[126];

	do {
		cout << "���: ";
		cin >> newEmployee.firstName;
	} while (onlyLetters(newEmployee.firstName));

	do {
		cout << "�������: ";
		cin >> newEmployee.lastName;
	} while (onlyLetters(newEmployee.lastName));
	
	do {
		cout << "����� ��������: ";
		cin >> newEmployee.phoneNumber;
	} while (onlyDigits(newEmployee.phoneNumber) || numberOfCharacters(newEmployee.phoneNumber));


	// ���������
	do {
		cout << "��������: ";
		cin >> temp;

		/*
		if (temp <= "0")
			cout << "����� ������ ���� ������ 0!" << endl << endl;
			*/
	} while (onlyDigits(temp));
	newEmployee.salary = stod(temp);
}

// ������� �� ������ ����������
void printEmployee(const employee& newEmployee) {
	cout << "���: " << newEmployee.firstName << endl;
	cout << "�������: " << newEmployee.lastName << endl;
	cout << "����� ��������: " << newEmployee.phoneNumber << endl;
	cout << "��������: " << newEmployee.salary << endl;
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