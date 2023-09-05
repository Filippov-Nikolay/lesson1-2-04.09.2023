#include <iostream>

using namespace std;

struct employee {
	char* firstName = new char[128];
	char* lastName = new char[128];
	char* phoneNumber = new char[128];
	double salary;
};


// Функция на изменение размера массива
void pushBack(int*&, int&, int);

// Функции на добавление/чтение сотрудников
void inputEmployee(employee&);
void printEmployee(const employee&);

// Фукнция на добавление сотдруника
void addEmployee(employee*&, int, int);

// Функция для сравнения строк по алфавиту
int compareStrings(const char*, const char*);

// Функция на сортировку по фамилии
void sortByLastName(employee*, int);

// Функция на поиск по фамилии
void searchByLastName(employee*, int, string);

// Функция на поиск по диапазону зарплаты
void searchBySalaryRange(employee*, int, double, double);

// Функция на удаление сотрудника
void deleteEmployee(employee*, int&);

// Проверка на корректность воода данных
bool onlyDigits(const char*); // Только цифры
bool onlyLetters(const char*); // Только буквы
bool numberOfCharacters(const char*); // Кол-во символов