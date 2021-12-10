#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;


class Patient
{
  private:
  string first, last, ssn, status;//status refers to critical/not critical status
  
  public:
  Patient();
  Patient(string first_t, string last_t, string ssn_t, string status);

  static vector<vector<Patient>> patientQueue;

  string GetFirst();
  string GetLast();
  string GetSSN();
  string GetStatus();
  vector<vector<Patient>> GetPatientQueue();

  void SetFirst(string first_t);
  void SetLast(string last_t);
  void SetSSN(string ssn_t);
  void SetStatus(string status_t);
  void SetPatientQueue(vector<vector<Patient>> patientQueue_t);
  
  void AddPatient(string clinic);
  void AddCriticalPatient(string clinic);
  void RemoveForOperation();
  void CancelPatient(string clinic);
  void ListPatient();
  //void ChangeDepartment(); function in Main

  
};



