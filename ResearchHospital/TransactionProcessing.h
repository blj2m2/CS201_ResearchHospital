#pragma once
#include <iostream>
#include <vector>
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
	vector<Transaction> v_transaction;

	void ProcessFileData(vector<vector<string>>&, Patient&);
	bool FieldValidation();
	void UpdateLog();
	void PrintTransactionSummary();
	void PrintErrorLog();
	void AddTransactionToErrorLog();
	void AddTransactionToLog();




};