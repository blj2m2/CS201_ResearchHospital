#include "TransactionProcessing.h"

void Transaction::SetTransactionType(string)
{
}

void Transaction::SetTransactionStatus(string)
{
}

void Transaction::SetTransactionDescription(string)
{
}

void Transaction::ProcessFileData(vector<vector<string>>& records, Patient& patient)
{
	//process each record and upload data to transaction log
	for (auto& i : records)
	{

	}

}

bool Transaction::FieldValidation()
{
	return false;
}

void Transaction::UpdateLog()
{
}

void Transaction::PrintTransactionSummary()
{
}

void Transaction::PrintErrorLog()
{
}

void Transaction::AddTransactionToErrorLog()
{
}

void Transaction::AddTransactionToLog()
{
}
