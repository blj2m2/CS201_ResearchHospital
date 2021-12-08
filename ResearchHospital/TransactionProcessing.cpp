#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <exception>
#include "TransactionProcessing.h"

Patient obj_patient;

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

void Transaction::ProcessFileData(vector<vector<string>>& records, Patient& patients)
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
			if (i[0]== "HC")
			{
				obj_patient.SetFirst(i[1]);
				obj_patient.SetLast(i[2]);
				obj_patient.SetSSN(i[3]);
				patients.patientQueue.at(0).push_back(obj_patient);
			}
			if (i[0] == "PC")
			{
				obj_patient.SetFirst(i[1]);
				obj_patient.SetLast(i[2]);
				obj_patient.SetSSN(i[3]);
				patients.patientQueue.at(0).push_back(obj_patient);
			}
			if (i[0] == "PS")
			{
				obj_patient.SetFirst(i[1]);
				obj_patient.SetLast(i[2]);
				obj_patient.SetSSN(i[3]);
				patients.patientQueue.at(0).push_back(obj_patient);
			}



			//Add patient obj_patient to vector of patients - this is stored in the patients that was 
			// passed in by reference
			//Add a new transaction to record process
			//Add a new error if the transaction failed

		}
		catch (const std::exception&)
		{
				//set exceptions
		}
	}



}

bool Transaction::FieldValidation()
{
	
	//field level validation can be added as part of processing each record.
	return false;
}



void Transaction::PrintTransactionSummary()
{
	cout << setw(50);
	cout << " Hospital Transaction Listing" << endl;
	//This can be split into types if necessary
	cout << setw(15) << "Transaction ID " << setw(20) << "Transaction Type " << setw(25) << "Transaction Status " << setw(47) << "Transaction Desc. " << setw(27) << "Transaction Date/Time " << endl;
	/*for (auto& i : v_transaction)
	{
		if (i.transactionType == "Movie" && i.transactionStatus != "Error")
		{
			cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(47) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
		}
	}*/

}

void Transaction::PrintErrorLog()
{
	cout << setw(50);
	cout << "Transaction Error Log" << endl;
	//This can be split into types if necessary
	cout << setw(15) << "Transaction ID" << setw(20) << "Transaction Type" << setw(25) << "Transaction Status" << setw(67) << "Transaction Desc." << setw(27) << "Transaction Date/Time" << endl;
	/*for (auto& i : v_transaction)
	{
		if (i.transactionType == "Movie" && i.transactionStatus == "Error")
		{
			cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(67) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
		}
	}*/
}

void Transaction::AddTransactionToErrorLog()
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	string rawData;
	//..This can be updated once we have a valid vector for transactions

	/*movie.GetSingleRecord(rawData);
	l_objTransaction.transactionId = v_transaction.size() + 1;
	l_objTransaction.transactionType = type;
	l_objTransaction.transactionStatus = "Error";
	l_objTransaction.transactionDescription = error;
	l_objTransaction.transactionRecord = rawData;
	l_objTransaction.transactionDateTime = to_string(timeinfo.tm_mon + 1) + "." + to_string(timeinfo.tm_mday) + "." + to_string(1900 + timeinfo.tm_year)
		+ " - " + to_string(timeinfo.tm_hour) + ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);
	v_transaction.push_back(l_objTransaction);*/
}

void Transaction::AddTransactionToLog()
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	string rawData;
	//..This can be updated once we have a valid vector for transactions

	/*movie.GetSingleRecord(rawData);
	l_objTransaction.transactionId = v_transaction.size() + 1;
	l_objTransaction.transactionType = type;
	l_objTransaction.transactionStatus = "Successful";
	l_objTransaction.transactionDescription = movie.GetTitle();
	l_objTransaction.transactionRecord = rawData;
	l_objTransaction.transactionDateTime = to_string(timeinfo.tm_mon + 1) + "." + to_string(timeinfo.tm_mday) + "." + to_string(1900 + timeinfo.tm_year)
		+ " - " + to_string(timeinfo.tm_hour) + ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);
	v_transaction.push_back(l_objTransaction);*/
}
