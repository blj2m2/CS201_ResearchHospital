// ResearchHospital.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include "DataReader.h"
#include "TransactionProcessing.h"
#include "Patient.h"

using namespace std;
DataReader file;
string fileName = "";


void PrintMainMenu(char&);
void PrintDepartmentMenu(string);
void GetMenuOption(char&);
bool VerifyOption(char&,string);

Patient patient;
Transaction transaction;


int main()
{
	vector<vector<string>> v_records;
	char option = '\0';
	try
	{
		file.ImportFile(v_records, fileName);
		transaction.ProcessFileData(v_records, patient, transaction);
		
		cout << endl;
		do
		{
			//present the menu until the person select the Q option

			PrintMainMenu(option);
			GetMenuOption(option);

			//if should happen on false condition
			if (!VerifyOption(option, "hospital"))
			{
				cout << "Please chose one of the options from the menu." << endl << endl;
				continue;
			}
			else
			{			
			
				switch (option)
				{
				case '1':
					//Print from the movie class - function needs to be written
					cout << "Heart Clinic Processing" << endl << endl;
					PrintDepartmentMenu("Heart Clinic");
					
					//Department Menu
					do
					{

						GetMenuOption(option);
						if (!VerifyOption(option, "clinic"))
						{
							cout << "Please chose one of the options from the menu." << endl << endl;
							continue;
						}
						else
						{
							switch (option)
							{
								//Add Patient
							case '1':
								cout << "Add patient placeholder" << endl;
								break;
								//Add Critical Patient
							case '2':
								cout << "Add critical patient placeholder" << endl;
								break;
								//Take out Patient for Operation
							case '3':
								cout << "Take out patient for operation placeholder" << endl;
								break;
								//Cancel Patient
							case '4':
								cout << "Cancel patient placeholder" << endl;
								break;
								//List Patients in Queue
							case '5':
								cout << "List patients in queue placeholder" << endl;
								break;
							case '6':
								//Change Patients in Queue or Exit
								transaction.PrintTransactionSummary("HC");
								cout << endl;
								PrintDepartmentMenu("Heart Clinic");
								break;
							case '7':
								//Change Patients in Queue or Exit
								transaction.PrintErrorLog();
								cout << endl;
								PrintDepartmentMenu("Heart Clinic");
								break;
							case '8':
								//Change Patients in Queue or Exit
								cout << "change patients in queue or exit placeholder" << endl;
								break;
							default:
								break;
							}
						}
						
					} while (option != '8');
					
					
					break;
				case '2':
					//Print from the song class - function needs to be written
					cout << "Pulminary Clinic Processing" << endl << endl;
					PrintDepartmentMenu("Lung Clinic");
					
					//Department Menu
					do
					{

						GetMenuOption(option);
						if (!VerifyOption(option, "clinic"))
						{
							cout << "Please chose one of the options from the menu." << endl << endl;
							continue;
						}
						else
						{
							switch (option)
							{
								//Add Patient
							case '1':
								cout << "Add patient placeholder" << endl;
								break;
								//Add Critical Patient
							case '2':
								cout << "Add critical patient placeholder" << endl;
								break;
								//Take out Patient for Operation
							case '3':
								cout << "Take out patient for operation placeholder" << endl;
								break;
								//Cancel Patient
							case '4':
								cout << "Cancel patient placeholder" << endl;
								break;
								//List Patients in Queue
							case '5':
								cout << "List patients in queue placeholder" << endl;
								break;
							case '6':
								//Change Patients in Queue or Exit
								transaction.PrintTransactionSummary("PC");
								cout << endl;
								PrintDepartmentMenu("Pulminary Clinic");
								break;
							case '7':
								//Change Patients in Queue or Exit
								transaction.PrintErrorLog();
								cout << endl;
								PrintDepartmentMenu("Pulminary Clinic");
								break;
							case '8':
								//Change Patients in Queue or Exit
								cout << "change patients in queue or exit placeholder" << endl;
								break;
							default:
								break;
							}
						}

					} while (option != '8');

					break;
				case '3':
					//Print from the move class - function needs to be written
					cout << "Plastic Surgery Processing" << endl << endl;
					PrintDepartmentMenu("Plastic Surgery");
					
					//Department Menu
					do
					{

						GetMenuOption(option);
						if (!VerifyOption(option, "clinic"))
						{
							cout << "Please chose one of the options from the menu." << endl << endl;
							continue;
						}
						else
						{
							switch (option)
							{
								//Add Patient
							case '1':
								cout << "Add patient placeholder" << endl;
								break;
								//Add Critical Patient
							case '2':
								cout << "Add critical patient placeholder" << endl;
								break;
								//Take out Patient for Operation
							case '3':
								cout << "Take out patient for operation placeholder" << endl;
								break;
								//Cancel Patient
							case '4':
								cout << "Cancel patient placeholder" << endl;
								break;
								//List Patients in Queue
							case '5':
								cout << "List patients in queue placeholder" << endl;
								break;
							case '6':
								//Change Patients in Queue or Exit
								transaction.PrintTransactionSummary("PS");
								cout << endl;
								PrintDepartmentMenu("Plastic Surgery Clinic");
								break;
							case '7':
								//Change Patients in Queue or Exit
								transaction.PrintErrorLog();
								cout << endl;
								PrintDepartmentMenu("Plastic Surgery Clinic");
								break;
							case '8':
								//Change Patients in Queue or Exit
								cout << "change patients in queue or exit placeholder" << endl;
								break;
							default:
								break;
							}
						}

					} while (option != '8');


					break;
				case '4':
					cout << "Quit" << endl << endl;
					break;

				default:
					break;
				}
			}

		} while (option != '4');
	}
	catch (runtime_error& e)
	{
		cout << e.what() << endl << endl;
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl << endl;
	}
	

}

bool VerifyOption(char& option, string optionType)
{
	if (optionType == "hospital")
	{
		bool cleanOption = false;
		if (option != 49 && option != 50 && option != 51 && option != 52)
		{

			cleanOption = false;
		}
		else
		{
			cleanOption = true;
		}
		return cleanOption;
	}
	else if (optionType == "clinic")
	{
		bool cleanOption = false;
		if (option != 49 && option != 50 && option != 51 && option != 52 && option != 53 && option != 54 && option != 55 && option != 58)
		{

			cleanOption = false;
		}
		else
		{
			cleanOption = true;
		}
		return cleanOption;
	}
	
}

void PrintMainMenu(char& option)
{
	cout << endl;
	cout << setw(20);
	cout << "WELCOME TO RESEARCH HOSPITAL" << endl;
	cout << "1: Heart Clinic" << endl;
	cout << "2: Lung Clinic" << endl;
	cout << "3: Plastic Surgery" << endl;
	cout << "4: Quit" << endl;

}

void PrintDepartmentMenu(string clinicType)
{
	cout << endl;
	cout << setw(20);
	cout << "Welcome to the " << clinicType << endl;
	cout << "1: Add Patient" << endl;
	cout << "2: Add Critical Patient" << endl;
	cout << "3: Take out Patient for Operation" << endl;
	cout << "4: Cancel Patient" << endl;
	cout << "5: List Patients in Queue" << endl;
	cout << "6: Print Transaction Summary" << endl;
	cout << "7: Print Error Log" << endl;
	cout << "8: Change Department or Exit" << endl;
}

void GetMenuOption(char& option)
{
	cout << endl << "Option: ";
	cin >> option;
	cout << endl;
	cin.clear();
	
}