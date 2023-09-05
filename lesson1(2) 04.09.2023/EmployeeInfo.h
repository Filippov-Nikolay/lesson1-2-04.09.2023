#include <iostream>

using namespace std;

struct employee {
	char* firstName = new char[128];
	char* lastName = new char[128];
	char* phoneNumber = new char[128];
	double salary;
};

// ������� �� ����������/������ �����������
void inputEmployee(employee&);
void printEmployee(const employee&);

// ������� �� ���������� ����������
void addEmployee(employee*, int, int);

// ������� �� �������� ����������
void deleteEmployee();

// ������� �� ���������� �� �������
int sortByLastName(const employee);

// ������� �� ����� �� ��������� ��������
int searchBySalaryRange();

// �������� �� ������������ ����� ������
bool onlyDigits(const char*); // ������ �����
bool onlyLetters(const char*); // ������ �����
bool numberOfCharacters(const char*); // ���-�� ��������