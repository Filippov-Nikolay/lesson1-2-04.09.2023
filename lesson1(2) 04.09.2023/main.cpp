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

	do {
		do {
			cout << "Ввод: ";
			cin >> temp;
		} while (onlyDigits(temp));
		userChoice = atoi(temp);

		if (userChoice == 0) {
			cout << "\nДо свидания!" << endl;
			break;
		}
		else if (userChoice < minNumberMenu || userChoice > maxNumberMenu) {
			cout << "Вы ввели неверный пункт меню!" << endl << endl;
		}
		else {
			if (userChoice == 1) {
				// Проверка на корректность ввода
				cout << "\nВведите кол-во сотрудников: ";
				cin >> quantity;

				numberEmployees = quantity;

				newEmployee = new employee[numberEmployees];

				// Запись
				for (int i = 0; i < numberEmployees; i++) {
					cout << "\nВведите информацию о " << i + 1 << "м сотруднике:" << endl;
					inputEmployee(newEmployee[i]);
					cout << endl;
				}
				cout << endl;

				flag = true;
			}

			if (!flag) {
				cout << "Нужно выбрать 1й пункт меню!" << endl << endl;
			}
			else {
				if (userChoice == 2) {
					// Чтение/Вывод
					cout << endl;
					for (int i = 0; i < numberEmployees; i++) {
						printEmployee(newEmployee[i]);
						cout << endl;
					}
					cout << endl;
				}
				else if (userChoice == 3) {
					// Функция на удаление сотрудника
					deleteEmployee(newEmployee, numberEmployees);
					cout << endl;
				}
				else if (userChoice == 4) {
					// Функция на сортировку по фамилии
					sortByLastName(newEmployee, numberEmployees);
				}
				else if (userChoice == 5) {
					// Функция на поиск по диапазону зарплаты
					do {
						cout << "Введите зарплату от: ";
						cin >> temp;
					} while (onlyDigits(temp));
					minSalary = stod(temp);
					
					do {
						cout << "Введите зарплату до: ";
						cin >> temp;
					} while (onlyDigits(temp));
					maxSalary = stod(temp);
					
					cout << endl;
					searchBySalaryRange(newEmployee, numberEmployees, minSalary, maxSalary);
				}
				else if (userChoice == 6) {
					// Функция на поиск по фамилии

					cout << "Введите ключ: ";
					cin >> temp;

					key = new char[strlen(temp)];
					key = temp;

					cout << endl;
					searchByLastName(newEmployee, numberEmployees, key);
					cout << endl;
				}
				else if (userChoice == 7) {
					// Запись в файл
					for (int i = 0; i < numberEmployees; i++)
						fileWrite(newEmployee[i]);
				}
				else if (userChoice == 8) {
					// Чтение из файла
					cout << "\nFile info: " << endl;
					fileRead();
				}
			}
		}
	} while (userChoice != 0);
	
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

	delete[] key;
	key = nullptr;

	delete newEmployee;
	newEmployee = nullptr;

	return 0;
}