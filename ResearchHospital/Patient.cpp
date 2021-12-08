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


//void Patient::CancelPatient(){}
//if SSN does not exist write error
//SSN exist - print patient info and status and remove from queue
void Patient::CancelPatient(string first_t, string last_t, string ssn_t, vector<vector<Patient>> patientQueue){
  string ssn;
  bool f = false;
  int x;

  cout << "Enter SSN of patient you would like to remove: ";
  cin >> ssn_t;
  
  for(int i = 0; ssn_t.size(); i++){
    if (stoi(ssn_t) == (ssn_t.at(i))){
      x = i; 
      f = true;
    }
  }
  if(f){
    cout << "Patient: " << ssn_t.at(x) << " " << ssn_t.at(x) << "'s appointment has been canceled." << endl;
    ssn_t.erase(ssn_t.begin()+x);
  }
  else{
    cout << "Patient " << ssn_t << " Does Not Exist" << endl;
  }
}


void Patient::ListPatient(){}
//void Patient::ChangeDepartment(){}
