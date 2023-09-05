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

	do {
		do {
			cout << "��������: ";
			cin >> temp;
		} while (onlyDigits(temp));
		newEmployee.salary = stod(temp);

		if (newEmployee.salary <= 0)
			cout << "����� ������ ���� ������ 0!" << endl << endl;
	} while (newEmployee.salary <= 0);
}


// ������� �� ������ ����������
void printEmployee(const employee& newEmployee) {
	cout << "���: " << newEmployee.firstName << endl;
	cout << "�������: " << newEmployee.lastName << endl;
	cout << "����� ��������: " << newEmployee.phoneNumber << endl;
	cout << "��������: " << newEmployee.salary << endl;
}

/*
// ������� �� ��������� ������� �������
int* resizeArray(int* oldArray, int& oldSize, int newSize) {
	int* newArray = new int[newSize];

	for (int i = 0; i < oldSize; i++) {
		newArray[i] = oldArray[i];
	}

	delete[] oldArray;
	oldSize = newSize;

	return newArray;
}
*/

/*
void pushBack(employee*& arr, int& size, employee value) {
	employee* newArray = new employee[size + 1];

	for (int i = 0; i < size; i++) {
		newArray[i] = arr[i];
	}

	newArray[size++] = value;

	delete[] arr;

	arr = newArray;
}
*/


// ��������!
// ������� �� ���������� ����������
void addEmployee(employee*& oldEmployee, int oldNumberEmployee, int newNumberEmployee) {
	int numberEmployees = oldNumberEmployee + newNumberEmployee; // ����� ���-�� �����������
	employee* newAddEmployee = new employee[numberEmployees];

	cout << "numberEmployees: " << numberEmployees << endl; // 3
	cout << "oldNumberEmployee: " << oldNumberEmployee << endl; // 2
	cout << "newNumberEmployee: " << newNumberEmployee << endl; // 1

	for (int i = 0; i < oldNumberEmployee; i++) {
		newAddEmployee[i] = oldEmployee[i];
	}

	for (int i = oldNumberEmployee; i < numberEmployees; i++) {
		inputEmployee(newAddEmployee[i]);
	}

	/*
	for (int i = 0; i <= newNumberEmployee; i++) {
		printEmployee(newAddEmployee[i]);
	}
	*/

	/*
	for (int i = oldNumberEmployee + 1; i < numberEmployees; i++) {
		pushBack(oldEmployee, oldNumberEmployee, newAddEmployee[i]);
	}
	*/

	cout << "Check100%" << endl;
}


// ������� �� ���������� �� �������
void sortByLastName(employee* sortLastName, int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (strcmp(sortLastName[j].lastName, sortLastName[j + 1].lastName) > 0) {
				employee temp = sortLastName[j];
				sortLastName[j] = sortLastName[j + 1];
				sortLastName[j + 1] = temp;
			}
		}
	}
}


// ������� �� ����� �� �������
void searchByLastName(employee* newEmployee, int size, string key) {
	bool found = false;
	for (int i = 0; i < size; i++) {
		if (newEmployee[i].lastName == key) {
			printEmployee(newEmployee[i]);
			found = true;
		}
	}

	if (!found)
		cout << "���� �� ������!";
}


// ������� �� ����� �� ��������� ��������
void searchBySalaryRange(employee* newEmployee, int size, double minSalary, double maxSalary) {
	bool found = false;

	for (int i = 0; i < size; i++) {
		if (newEmployee[i].salary >= minSalary && newEmployee[i].salary <= maxSalary) {
			printEmployee(newEmployee[i]);
			cout << endl;
			found = true;
		}
	}

	if (!found)
		cout << "��������� � ��������� �� " << minSalary << " �� " << maxSalary << " �� �������." << endl;
}


// ������� �� �������� ����������
void deleteEmployee(employee* newEmployee, int& size) {
	int index;
	char userChoice;

	if (size <= 0) {
		cout << "��� ����������, ������� ����� ���� �� �������." << endl;
		return;
	}

	cout << "������� ������ ��������� ��� �������� (0-" << size - 1 << "): ";
	cin >> index;

	if (index < 0 || index >= size) {
		cout << "�������� ������ ���������." << endl;
		return;
	}
	
	cout << "�� �������, ��� ������ ������� ����� ���������? (y/n): ";
	cin >> userChoice;

	if (userChoice == 'y') {
		delete[] newEmployee[index].firstName;
		delete[] newEmployee[index].lastName;
		delete[] newEmployee[index].phoneNumber;

		for (int i = index; i < size - 1; i++)
			newEmployee[i] = newEmployee[i + 1];

		size--;
		cout << "�������� �����." << endl;
	}
	else {
		cout << "�������� ��������" << endl;
	}
}


// �������� �� ������������ ����� ������:
// ������ �����
bool onlyLetters(const char* content) { 
	for (int i = 0; i < strlen(content); i++) {
		if (isdigit(content[i])) {
			cout << "�� ����� ������������ ������!" << endl << endl;
			return true;
		}
	}

	return false;
}

// ������ �����
bool onlyDigits(const char* content) { 
	for (int i = 0; i < strlen(content); i++) {
		if (isalpha(content[i]) || content[i] == ' ') {
			cout << "�� ����� ������������ ������!" << endl << endl;
			return true;
		}
	}

	return false;
}

// ���-�� ��������
bool numberOfCharacters(const char* content) { 
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