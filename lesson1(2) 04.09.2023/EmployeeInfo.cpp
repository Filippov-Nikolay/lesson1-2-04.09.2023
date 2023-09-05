#include <iostream>
#include <string>
#include "EmployeeInfo.h"

using namespace std;

// Функции на добавление сотрудника
void inputEmployee(employee& newEmployee) {
	char* temp = new char[126];

	do {
		cout << "Имя: ";
		cin >> newEmployee.firstName;
	} while (onlyLetters(newEmployee.firstName));

	do {
		cout << "Фамилия: ";
		cin >> newEmployee.lastName;
	} while (onlyLetters(newEmployee.lastName));
	
	do {
		cout << "Номер телефона: ";
		cin >> newEmployee.phoneNumber;
	} while (onlyDigits(newEmployee.phoneNumber) || numberOfCharacters(newEmployee.phoneNumber));


	// Исправить
	do {
		cout << "Зарплата: ";
		cin >> temp;

		/*
		if (temp <= "0")
			cout << "Число должно быть больше 0!" << endl << endl;
			*/
	} while (onlyDigits(temp));
	newEmployee.salary = stod(temp);
}

// Функции на чтение сотрудника
void printEmployee(const employee& newEmployee) {
	cout << "Имя: " << newEmployee.firstName << endl;
	cout << "Фамилия: " << newEmployee.lastName << endl;
	cout << "Номер телефона: " << newEmployee.phoneNumber << endl;
	cout << "Зарплата: " << newEmployee.salary << endl;
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