#include <iostream>

using namespace std;

struct employee {
	char* firstName = new char[128];
	char* lastName = new char[128];
	char* phoneNumber = new char[128];
	double salary;
};


// ������� �� ��������� ������� �������
void pushBack(int*&, int&, int);

/*
int* resizeArray(int*, int&, int);
*/

// ������� �� ����������/������ �����������
void inputEmployee(employee&);
void printEmployee(const employee&);

// ������� �� ���������� ����������
void addEmployee(employee*&, int, int);

// ������� ��� ��������� ����� �� ��������
int compareStrings(const char*, const char*);

// ������� �� ���������� �� �������
void sortByLastName(employee*, int);

// ������� �� ����� �� ��������� ��������
int searchBySalaryRange();

// ������� �� �������� ����������
void deleteEmployee(employee*, int&);

// �������� �� ������������ ����� ������
bool onlyDigits(const char*); // ������ �����
bool onlyLetters(const char*); // ������ �����
bool numberOfCharacters(const char*); // ���-�� ��������