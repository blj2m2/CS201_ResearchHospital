// ResearchHospital.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include "DataReader.h"
#include "TransactionProcessing.h"

using namespace std;
DataReader file;
string fileName = "";


void PrintMainMenu(char& option);
void GetMenuOption(char& option);
bool VerifyOption(char& option);


int main()
{
	vector<vector<string>> v_records;
	char options = '\0';
	try
	{
		file.ImportFile(v_records, fileName);
	}
	catch (const std::exception&)
	{
			
	}
}

bool VerifyOption(char& option)
{
	bool cleanOption = false;
	if (option != 1 && option != 2 && option != 3 && option != 4)
	{

		cleanOption = false;
	}
	else
	{
		cleanOption = true;
	}
	return cleanOption;
}

void PrintMainMenu(char& option)
{
	cout << endl;
	cout << setw(20);
	cout << "WELCOME TO RESEARCH HOSPITAL" << endl;
	cout << "1: Heart Clinic" << endl;
	cout << "2: Lung Clinic" << endl;
	cout << "3: Plastic Surgery" << endl;
	cout << "Quit" << endl;

}

void PrintDepartmentMenu(char clinicType, char& departmentOption)
{
	cout << endl;
	cout << setw(20);
	cout << "Welcome to the " << clinicType << "Clinic" << endl;
	cout << "1: Add Patient" << endl;
	cout << "2: Add Critical Patient" << endl;
	cout << "3: Take out Patient for Operation" << endl;
	cout << "3: Cancel Patient" << endl;
	cout << "3: List Patients in Queue" << endl;
	cout << "3: Change Department or Exit" << endl;
}

void GetMenuOption(char& option)
{
	cout << endl << "Option: ";
	cin >> option;
	cout << endl;
	cin.clear();
	option = toupper(option);
}