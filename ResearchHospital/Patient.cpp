#include "Patient.h"
using namespace std;

Patient::Patient(){
  first = " ";
  last = " ";
  ssn = " ";
  patientQueue = { {},{},{} };
}

Patient::Patient(string first_t, string last_t, string ssn_t, vector<vector<Patient>> patientQueue){
  first = first_t;
  last = last_t;
  ssn = ssn_t;
  patientQueue = patientQueue;
}

string Patient::GetFirst(){return first;}
string Patient::GetLast(){return last;}
string Patient::GetSSN(){return ssn;}
vector<vector<Patient>> Patient::GetPatientQueue(){return patientQueue;}

void Patient::SetFirst(string first_t){first = first_t;}
void Patient::SetLast(string last_t){last = last_t;}
void Patient::SetSSN(string ssn_t){ssn = ssn_t;}
void Patient::SetPatientQueue(vector<vector<Patient>> patientQueue_t){patientQueue = patientQueue_t;}

void Patient::AddPatient(){}
void Patient::AddCriticalPatient(){}
void Patient::RemoveForOperation(){}
void Patient::CancelPatient(){}
void Patient::ListPatient(){}
//void Patient::ChangeDepartment(){}
