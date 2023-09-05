#include <iostream>
#include "EmployeeInfo.h"
#include "EmployeeInfoFile.h"

using namespace std;

int main() {
	setlocale(0, "");

	// MENU

	int quantity = 0;
	int numberEmployees = 0;

	// Проверка на корректность ввода
	cout << "Введите кол-во сотрудников: ";
	cin >> quantity;

	numberEmployees = quantity;

	employee* newEmployee = new employee[numberEmployees];

	// Запись
	for (int i = 0; i < numberEmployees; i++)
		inputEmployee(newEmployee[i]);
	cout << endl << endl;

	// Чтение
	for (int i = 0; i < numberEmployees; i++)
		printEmployee(newEmployee[i]);
	cout << endl << endl;

	// Добавление сотрудника (проверка корректность)
	cout << "Введите сколько нужно добавить новых сотружников: ";
	cin >> quantity;
	for (int i = 0; i < quantity; i++) {
		addEmployee(newEmployee, numberEmployees, quantity);
	}

	// Чтение
	for (int i = 0; i < numberEmployees; i++)
		printEmployee(newEmployee[i]);
	cout << endl << endl;

	/*

	// Запись в файл
	for (int i = 0; i < numberEmployees; i++)
		fileWrite(newEmployee[i]);

	// Чтение файла
	cout << "\nFile info: " << endl;
	fileRead();

	
	// Функция на сортировку по фамилии
	sortByLastName(newEmployee, numberEmployees);

	// Чтение
	for (int i = 0; i < numberEmployees; i++)
		printEmployee(newEmployee[i]);
	cout << endl << endl;
	
	
	*/

	delete newEmployee;
	newEmployee = nullptr;

	return 0;
}