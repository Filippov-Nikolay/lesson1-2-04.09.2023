#include <iostream>
#include <fstream>
#include "EmployeeInfo.h";
#include "EmployeeInfoFile.h"

using namespace std;

void fileWrite(const employee* newEmployeeInfo) {
	ofstream text("text.txt");

	text << "FirstName: " << newEmployeeInfo->firstName << "." << endl;
	text << "LastName: " << newEmployeeInfo->lastName << "." << endl;
	text << "PhoneNumber: " << newEmployeeInfo->phoneNumber << "." << endl;
	text << "Salary: " << newEmployeeInfo->salary << "." << endl;
}
void fileRead() {
	int n = 256;
	char* buffer = new char[n] {};
	ifstream binary1("text.txt", ios::binary);

	binary1.read(buffer, n);
	cout << buffer << endl;

	delete[] buffer;

	binary1.close();
}