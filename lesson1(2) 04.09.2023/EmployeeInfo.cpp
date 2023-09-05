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

	do {
		do {
			cout << "Зарплата: ";
			cin >> temp;
		} while (onlyDigits(temp));
		newEmployee.salary = stod(temp);

		if (newEmployee.salary <= 0)
			cout << "Число должно быть больше 0!" << endl << endl;
	} while (newEmployee.salary <= 0);
}


// Функции на чтение сотрудника
void printEmployee(const employee& newEmployee) {
	cout << "Имя: " << newEmployee.firstName << endl;
	cout << "Фамилия: " << newEmployee.lastName << endl;
	cout << "Номер телефона: " << newEmployee.phoneNumber << endl;
	cout << "Зарплата: " << newEmployee.salary << endl;
}

/*
// Функция на изменение размера массива
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

// ДОДЕЛАТЬ
// Фукнция на добавление сотдруника
void addEmployee(employee*& oldEmployee, int oldNumberEmployee, int newNumberEmployee) {
	int numberEmployees = oldNumberEmployee + newNumberEmployee; // Общее кол-во сотрудников
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


// Функция на сортировку по фамилии
void sortByLastName(employee* sortLastName, int size) {
	cout << "Check 1" << endl;

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

/*
void sortByLastName(employee* sortLastName, int size) {

	cout << "Check 1" << endl;

	for (int i = 1; i < size; i++) {
		char* current = sortLastName[i].lastName;
		int j = i - 1;

		while (j >= 0 && compareStrings(sortLastName[j].lastName, current) > 0) {
			sortLastName[j + 1].lastName = sortLastName[j].lastName;
			sortLastName[j + 1] = sortLastName[j];
			--j;
		}

		sortLastName[j + 1].lastName = current;
	}	

	cout << "Last check!" << endl;
}
*/


// Функция на удаление сотрудника
void deleteEmployee(employee* newEmployee, int& size) {
	if (size <= 0) {
		cout << "Нет работников, которых можно было бы удалить." << endl;
		return;
	}

	int index;
	cout << "Введите индекс работника для удаления (0-" << size - 1 << "): ";
	cin >> index;

	if (index < 0 || index >= size) {
		cout << "Неверный индекс работника." << endl;
		return;
	}
	char answ;
	cout << "Вы уверены, что хотите удалить этого работника? (y/n): ";
	cin >> answ;

	if (answ == 'y') {
		delete[] newEmployee[index].firstName;
		delete[] newEmployee[index].lastName;
		delete[] newEmployee[index].phoneNumber;

		for (int i = index; i < size - 1; i++)
			newEmployee[i] = newEmployee[i + 1];

		size--;
		cout << "Работник удалён." << endl;
	}
	else {
		cout << "Удаление отменено" << endl;
	}
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