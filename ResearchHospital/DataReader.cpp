#include <iostream>
#include <sstream>
#include <exception>
#include <limits>
#include <fstream>
#include "DataReader.h"
#include "TransactionProcessing.h"



using namespace std;




//function used to import all data in the csv file and load it into a vector of vectors.
string DataReader::OpenFile(string fileName, vector<vector<string>>& v_records)
{
	ifstream inSS;
	inSS.open(fileName, ios::in);
	if (!inSS)
	{
		throw runtime_error("Unable to Read file, please run import process again.");
	}
	vector<string> row;
	string line, field;
	while (getline(inSS, line))
	{
		//clear each row prior to reading values into it
		row.clear();
		stringstream s(line);
		while (getline(s, field, ','))
		{
			row.push_back(field);
		}
		records.push_back(row);
	}inSS.close();

	cout << "Import successful" << endl;
	v_records = records;

	cout << v_records.size() << " Records Total." << endl;

	return fileName;

}
void DataReader::OpenFile(string fileName, vector<vector<string>> v_records, int transactionID, Book& book, Movie& movie, Song& song)
{
	ifstream inSS;
	int count = 0;
	inSS.open(fileName, ios::in);
	if (!inSS)
	{
		throw runtime_error("Unable to Read file, please run Import process again.");
	}
	vector<string> row;
	string line, field;


	while (getline(inSS, line))
	{
		count++;
		if (count == transactionID)
		{
			//clear each row prior to reading values into it
			row.clear();
			stringstream s(line);
			while (getline(s, field, ','))
			{
				row.push_back(field);
			}

			records.push_back(row);
		}

	}inSS.close();


	cout << "Reprocess Import successful" << endl;
	v_records = records;

	cout << v_records.size() << " Records Total." << endl;

	vector<vector<string>> config;
	importFileConfig(config);
	tProcessing.ProcessFileData(v_records, config, book, movie, song);

}


//function used to get the file path and check that the entry is correct
void DataReader::ImportFile(vector<vector<string>>& v_records)
{

	cout << "Please enter the file name that should be used for Import (ex. medialist.csv):  ";
	if (!cin)
	{
		throw runtime_error("The file name or path you entered was incorrect.");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (cin)
	{
		cin >> fileName;
	}


	OpenFile(fileName, v_records);



}
void DataReader::ImportFile(vector<vector<string>>& v_records, string& fileData)
{
	//string file;
	cout << "Please enter the file name that should be used for Import (ex. medialist.csv):  ";
	if (!cin)
	{
		throw runtime_error("The file name or path you entered was incorrect.");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (cin)
	{
		cin >> fileName;
	}
	fileData = fileName;

	OpenFile(fileName, v_records);



}



