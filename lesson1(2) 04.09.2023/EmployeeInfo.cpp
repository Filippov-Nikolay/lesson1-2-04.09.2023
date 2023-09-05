#include <iostream>
#include <string>
#include "EmployeeInfo.h"

using namespace std;

// Функции на добавление сотрудника
void inputEmployee(employee& newEmployee) {
	char* temp = new char[126];

	/*
	do {
		cout << "Имя: ";
		cin >> newEmployee.firstName;
	} while (onlyLetters(newEmployee.firstName));
	*/

	do {
		cout << "Фамилия: ";
		cin >> newEmployee.lastName;
	} while (onlyLetters(newEmployee.lastName));
	
	/*
	do {
		cout << "Номер телефона: ";
		cin >> newEmployee.phoneNumber;
	} while (onlyDigits(newEmployee.phoneNumber) || numberOfCharacters(newEmployee.phoneNumber));

	do {
		do {
			cout << "Зарплата: ";
			cin >> temp;
		} while (onlyDigits(temp));
		newEmployee.salary = stod(temp);

		if (newEmployee.salary <= 0)
			cout << "Число должно быть больше 0!" << endl << endl;
	} while (newEmployee.salary <= 0);
	*/
}


// Функции на чтение сотрудника
void printEmployee(const employee& newEmployee) {
	// cout << "Имя: " << newEmployee.firstName << endl;
	cout << "Фамилия: " << newEmployee.lastName << endl;
	// cout << "Номер телефона: " << newEmployee.phoneNumber << endl;
	// cout << "Зарплата: " << newEmployee.salary << endl;
}


// ДОДЕЛАТЬ
// Фукнция на добавление сотдруника
void addEmployee(employee* oldEmployee, int oldNumberEmployee, int newNumberEmployee) {
	cout << "Check1" << endl;
	int numberEmployees = oldNumberEmployee + newNumberEmployee;
	employee* addEmployee = new employee[numberEmployees];

	cout << "Кол-во сотрудников (олд + нью): " << numberEmployees << endl;

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

// Функция для сравнения строк по алфавиту
int compareStrings(char* a, char* b) {
	cout << "compareStrings: " << a << " " << b << endl;

	while (*a == *b) {
		++a;
		++b;
	}
	return *a - *b;
}

// Функция на сортировку по фамилии
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


// Проверки на корректность воода данных
bool onlyLetters(const char* content) { // Только буквы
	for (int i = 0; i < strlen(content); i++) {
		if (isdigit(content[i])) {
			cout << "Вы ввели недопустимый символ!" << endl << endl;
			return true;
		}
	}

	return false;
}
bool onlyDigits(const char* content) { // Только цифры
	for (int i = 0; i < strlen(content); i++) {
		if (isalpha(content[i]) || content[i] == ' ') {
			cout << "Вы ввели недопустимый символ!" << endl << endl;
			return true;
		}
	}

	return false;
}
bool numberOfCharacters(const char* content) { // Кол-во символов
	if (strlen(content) < 8) {
		cout << "Длина должна быть не менее 8 символов!" << endl << endl;
		return true;
	}
	else if (strlen(content) > 10) {
		cout << "Длина должна быть не больше 10 символов!" << endl << endl;
		return true;
	}

	return false;
}