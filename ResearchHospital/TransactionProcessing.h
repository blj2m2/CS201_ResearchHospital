#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Patient.h"


using namespace std;

class Transaction {

private:
	size_t transactionId;
	string transactionType;
	string transactionStatus;
	string transactionDescription;
	string transactionRecord;
	string transactionDateTime;
protected:


public:
	Transaction()
	{
		transactionId = 0;
		transactionType = "N/A";
		transactionStatus = "Pending";
		transactionDescription = "N/A";
		transactionRecord = "N/A";
	}

	void SetTransactionType(string);
	void SetTransactionStatus(string);
	void SetTransactionDescription(string);
	vector <Transaction> transactionQueue;

	void ProcessFileData(vector<vector<string>>&, Patient&, Transaction&);
	bool FieldValidation();
	void PrintTransactionSummary(string);
	void PrintErrorLog();
	void AddTransactionToErrorLog(string, string, string, Transaction&);
	void AddTransactionToLog(string, string, string, Transaction&);




};