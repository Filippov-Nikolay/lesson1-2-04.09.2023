#include <iostream>

using namespace std;

struct employee {
	char* firstName = new char[128];
	char* lastName = new char[128];
	char* phoneNumber = new char[128];
	double salary;
};

// Функции на добавление/чтение сотрудников
void inputEmployee(employee&);
void printEmployee(const employee&);

// Фукнция на добавление сотдруника
void addEmployee();

// Функция на удаление сотрудника
void deleteEmployee();

// Функция на поиск по фамилии
int searchByLastName(const employee);

// Функция на поиск по диапазону зарплаты
int searchBySalaryRange();

// Проверка на корректность воода данных
bool onlyDigits(const char*); // Только цифры
bool onlyLetters(const char*); // Только буквы
bool numberOfCharacters(const char*); // Кол-во символов