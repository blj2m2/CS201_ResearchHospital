#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <exception>
#include "TransactionProcessing.h"

Patient obj_patient;
Transaction obj_transaction;

void Transaction::SetTransactionType(string transactionType)
{
	this->transactionType = transactionType;
}

void Transaction::SetTransactionStatus(string transactionStatus)
{
	this->transactionStatus = transactionStatus;
}

void Transaction::SetTransactionDescription(string transactionDescription)
{
	this->transactionDescription = transactionDescription;
}

void Transaction::ProcessFileData(vector<vector<string>>& records, Patient& patients,Transaction& transaction)
{
	//process each record and upload data to transaction log
	for (auto& i : records)
	{
		try
		{
			//local patients object
			//HC, PC, PS
			//ssn check, type check, blank strings if first or last name is missing.
			
			//Heart Clinic
			//Plastic Surgery
			//Pulminary clinic

			if (i[0]== "Q")
			{
				break;
			}
			if (i[0]== "HC")
			{
				obj_patient.SetFirst(i[1]);
				obj_patient.SetLast(i[2]);
				obj_patient.SetSSN(i[3]);
				patients.patientQueue.at(0).push_back(obj_patient);
				string rawData = i[0] + "," + i[1] + "," + i[2] + "," + i[3];
				string description = i[0] + " - " + i[1] + i[2];
				AddTransactionToLog(rawData, description, i[0], transaction);
			}
			else if (i[0] == "PC")
			{
				obj_patient.SetFirst(i[1]);
				obj_patient.SetLast(i[2]);
				obj_patient.SetSSN(i[3]);
				patients.patientQueue.at(1).push_back(obj_patient);
				string rawData = i[0] + "," + i[1] + "," + i[2] + "," + i[3];
				string description = i[0] + " - " + i[1] + i[2];
				AddTransactionToLog(rawData, description, i[0], transaction);
			}
			else if (i[0] == "PS")
			{
				obj_patient.SetFirst(i[1]);
				obj_patient.SetLast(i[2]);
				obj_patient.SetSSN(i[3]);
				patients.patientQueue.at(2).push_back(obj_patient);
				string rawData = i[0] + "," + i[1] + "," + i[2] + "," + i[3];
				string description = i[0] + " - " + i[1] + i[2];
				AddTransactionToLog(rawData, description, i[0], transaction);
			}
			else
			{
				string rawData = i[0] + "," + i[1] + "," + i[2] + "," + i[3];
				string description = i[0] + " - " + i[1] + i[2];
				AddTransactionToErrorLog(rawData, description, i[0], transaction);
			}
			
		}

		
		catch (const std::exception&)
		{
				//set exceptions
		}

		
	}
	cout << "Records Processed into Objects by Clinic - Transaction Log Updated" << endl;


}

bool Transaction::FieldValidation()
{
	
	//field level validation can be added as part of processing each record.
	return false;
}



void Transaction::PrintTransactionSummary(string type)
{
	cout << setw(50);
	cout << "Heart Clinic Transactions" << endl;
	cout << setw(15) << "Transaction ID " << setw(20) << "Transaction Type " << setw(25) << "Transaction Status " << setw(25) << "Transaction Desc. " << setw(27) << "Transaction Date/Time " << endl;
	if (type == "HC")
	{
		for (auto& i : transactionQueue)
		{
			if (i.transactionType == "HC" && i.transactionStatus != "Error")
			{
				cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(25) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
			}
		}
		cout << endl;
	}

	if (type == "PS")
	{
		cout << "Plastic Surgery Clinic Transactions" << endl;
		cout << setw(15) << "Transaction ID " << setw(20) << "Transaction Type " << setw(25) << "Transaction Status " << setw(25) << "Transaction Desc. " << setw(27) << "Transaction Date/Time " << endl;
		for (auto& i : transactionQueue)
		{
			if (i.transactionType == "PS" && i.transactionStatus != "Error")
			{
				cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(25) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
			}
		}
		cout << endl;
	}
	if (type == "PC")
	{
		cout << "Pulminary Clinic Transactions" << endl;
		cout << setw(15) << "Transaction ID " << setw(20) << "Transaction Type " << setw(25) << "Transaction Status " << setw(25) << "Transaction Desc. " << setw(27) << "Transaction Date/Time " << endl;
		for (auto& i : transactionQueue)
		{
			if (i.transactionType == "PC" && i.transactionStatus != "Error")
			{
				cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(25) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
			}
		}
		cout << endl;
	}


}

void Transaction::PrintErrorLog()
{
	cout << setw(50);
	cout << "Transaction Error Log" << endl;
	//This can be split into types if necessary
	cout << setw(15) << "Transaction ID" << setw(20) << "Transaction Type" << setw(25) << "Transaction Status" << setw(25) << "Transaction Desc." << setw(27) << "Transaction Date/Time" << endl;
	for (auto& i : transactionQueue)
	{
		if (i.transactionStatus == "Error")
		{
			cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(25) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
		}
	}
}

void Transaction::AddTransactionToErrorLog(string record, string description, string clinicType, Transaction& transaction)
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	obj_transaction.transactionId = transactionQueue.size() + 1;
	obj_transaction.transactionType = clinicType;
	obj_transaction.transactionStatus = "Error";
	obj_transaction.transactionDescription = description;
	obj_transaction.transactionRecord = record;
	obj_transaction.transactionDateTime = to_string(timeinfo.tm_mon + 1) + "." + to_string(timeinfo.tm_mday) + "." + to_string(1900 + timeinfo.tm_year)
		+ " - " + to_string(timeinfo.tm_hour) + ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);
	transaction.transactionQueue.push_back(obj_transaction);
}

void Transaction::AddTransactionToLog(string record, string description, string clinicType, Transaction& transaction)
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	obj_transaction.transactionId = transactionQueue.size() + 1;
	obj_transaction.transactionType = clinicType;
	obj_transaction.transactionStatus = "Successful";
	obj_transaction.transactionDescription = description;
	obj_transaction.transactionRecord = record;
	obj_transaction.transactionDateTime = to_string(timeinfo.tm_mon + 1) + "." + to_string(timeinfo.tm_mday) + "." + to_string(1900 + timeinfo.tm_year)
		+ " - " + to_string(timeinfo.tm_hour) + ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);
	transaction.transactionQueue.push_back(obj_transaction);
}
