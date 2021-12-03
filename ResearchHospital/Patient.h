#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;


class Patient
{
  private:
  string first, last, ssn;
  vector<vector<string>> patientQueue;
  public:
  Patient();
  Patient(string first_t, string last_t, string ssn_t, vector<vector<string>> patientQueue);

  string GetFirst();
  string GetLast();
  string GetSSN();
  vector<vector<string>> GetPatientQueue();

  void SetFirst(string first_t);
  void SetLast(string last_t);
  void SetSSN(string ssn_t);
  void SetPatientQueue(vector<vector<string>> patientQueue_t);
  
  void AddPatient();
  void AddCriticalPatient();
  void RemoveForOperation();
  void CancelPatient();
  void ListPatient();
  void ChangeDepartment();
};


