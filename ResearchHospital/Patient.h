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
  
  public:
  Patient();
  Patient(string first_t, string last_t, string ssn_t, vector<vector<Patient>> patientQueue);
  vector<vector<Patient>> patientQueue;

  string GetFirst();
  string GetLast();
  string GetSSN();
  vector<vector<Patient>> GetPatientQueue();

  void SetFirst(string first_t);
  void SetLast(string last_t);
  void SetSSN(string ssn_t);
  void SetPatientQueue(vector<vector<Patient>> patientQueue_t);
  
  void AddPatient();
  void AddCriticalPatient();
  void RemoveForOperation();
  void CancelPatient();
  void ListPatient();
  void ChangeDepartment();
  
  void CancelPatient(string clinic);
};


