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

	cout << "Меню: " << endl;
	cout << "1. Ввод данных о сотрудниках" << endl;
	cout << "2. Вывод данных о сотрудниках (всех)" << endl;
	cout << "3. Удаление сотрудника" << endl;
	cout << "4. Сортировка по фамилии сотрудников" << endl;
	cout << "5. Поиск по ЗП сотрудников" << endl;
	cout << "6. Поиск по фамилии сотрудников" << endl;
	cout << "7. Запись данных о сотрудниках в текстовый файл" << endl;
	cout << "8. Вывод данных о сотрудниках из текстового файла" << endl;
	// cout << "9. Добавление сотрудника(ов)" << endl;
	cout << "0. Выход" << endl;

	cout << "Ввод: ";
	cin >> userChoice;
	

	employee* newEmployee = nullptr;

	if (userChoice == 1) {
		// Проверка на корректность ввода
		cout << "Введите кол-во сотрудников: ";
		cin >> quantity;

		numberEmployees = quantity;

		newEmployee = new employee[numberEmployees];

		// Запись
		for (int i = 0; i < numberEmployees; i++)
			inputEmployee(newEmployee[i]);
		cout << endl << endl;
	}
	else if (userChoice == 2) {
		// Чтение
		for (int i = 0; i < numberEmployees; i++)
			printEmployee(newEmployee[i]);
		cout << endl << endl;
	}
	else if (userChoice == 3) {
		// Функция на сортировку по фамилии
		sortByLastName(newEmployee, numberEmployees);
	}
	else if (userChoice == 4) {
		
	}

	deleteEmployee(newEmployee, numberEmployees);

	// Чтение
	for (int i = 0; i < numberEmployees; i++)
		printEmployee(newEmployee[i]);
	cout << endl << endl;

	

	

	

	
	/*

	// Добавление сотрудника (проверка корректность)
	cout << "Введите сколько нужно добавить новых сотрудников: ";
	cin >> quantity;

	newEmployee = new employee[numberEmployees+=quantity];

	cout << "-numberEmployees: " << numberEmployees << endl;

	for (int i = 0; i < quantity; i++) {
		addEmployee(newEmployee, numberEmployees, quantity);
	}

	// Чтение
	for (int i = 0; i < numberEmployees; i++)
		printEmployee(newEmployee[i]);
	cout << endl << endl;
	*/
	/*

	// Запись в файл
	for (int i = 0; i < numberEmployees; i++)
		fileWrite(newEmployee[i]);

	// Чтение файла
	cout << "\nFile info: " << endl;
	fileRead();

	// Чтение
	for (int i = 0; i < numberEmployees; i++)
		printEmployee(newEmployee[i]);
	cout << endl << endl;
	
	
	*/

	delete newEmployee;
	newEmployee = nullptr;

	return 0;
}