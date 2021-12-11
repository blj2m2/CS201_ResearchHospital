#include <iostream>
#include "Patient.h"
#include "TransactionProcessing.h"



using namespace std;

Patient v_patient;

Patient::Patient(){
  first = " ";
  last = " ";
  ssn = " ";
  status = " ";
 
}

Patient::Patient(string first_t, string last_t, string ssn_t, string status_t)
{
    first = first_t;
    last = last_t;
    ssn = ssn_t;
    status = status_t;
}



Patient::Patient(string first_t, string last_t, string ssn_t, vector<Patient> patientQueue){
  first = first_t;
  last = last_t;
  ssn = ssn_t;
  status = "";
}

string Patient::GetFirst(){return first;}
string Patient::GetLast(){return last;}
string Patient::GetSSN(){return ssn;}
string Patient::GetStatus() { return status; }
//vector<Patient>Patient::GetPatientQueue(){return patientQueue;}

void Patient::SetFirst(string first_t){first = first_t;}
void Patient::SetLast(string last_t){last = last_t;}
void Patient::SetSSN(string ssn_t){ssn = ssn_t;}
//void Patient::SetPatientQueue(vector<Patient> patientQueue_t){patientQueue = patientQueue_t;}

void Patient::AddPatient(string clinic) {
    int index;//index of clinic
    if (clinic == "HC") {// HC == heart clinic
        index = 0;
    }
    else if (clinic == "PS") {//PS == plastic surgery
        index = 1;
    }
    else if (clinic == "PC") {//PC == lung clinic
        index = 2;
    }

    if (index < 0 || index > 2) {
        cout << "Invalid Clinic\n";
    }
    else if (patientQueue.size() == 10) {
        cout << "Clinic is at capacity\n";
    }
    else if (index >= 0 && index <= 2) {
        string first_t, last_t, ssn_t, status_t;
        cout << "Enter Status:\n";
        cin >> status_t;
        v_patient.status = status_t;
        cout << "Enter First Name:\n";
        cin >> first_t;
        v_patient.first = first_t;
        cout << "Enter Last Name:\n";
        cin >> last_t;
        v_patient.last = last_t;
        cout << "Enter SSN:\n";
        cin >> ssn_t;
        v_patient.ssn = ssn_t;

        if (ssn_t == "") {
            cout << "Invalid SSN given\n";
        }
        else {
            patientQueue[index].patientQueue.push_back(v_patient);
            //patientQueue.at(index).push_back(Patient(first_t, last_t, ssn_t, status_t));
        }
    }

}
void Patient::AddCriticalPatient(string clinic) {
    int index;//index of clinic
    int indexCritical;//index of last critical status patient in queue
    if (clinic == "HC") {//HC == heart clinic
        index = 0;
    }
    else if (clinic == "PS") {//PS == plastic surgery
        index = 1;
    }
    else if (clinic == "PC") {//PC == lung clinic
        index = 2;
    }

    if (index < 0 || index > 2) {//invalid clinic index, not 0,1, or 2
        cout << "Invalid Clinic\n";
    }
    else if (patientQueue.size() == 10 && patientQueue.at(index).patientQueue.at(9).GetStatus() == "critical") {//patientQueue is full and all patients are critical
        cout << "Clinic is at capacity\n";
    }
    else {
        //input for first, last, ssn, and status
        string first_t, last_t, ssn_t, status_t;
        cout << "Enter Status:\n";
        cin >> status_t;
        cout << "Enter First Name:\n";
        cin >> first_t;
        cout << "Enter Last Name:\n";
        cin >> last_t;
        cout << "Enter SSN:\n";
        cin >> ssn_t;

        if (ssn_t == "") {//invalid ssn
            cout << "Invalid SSN given\n";
        }
        else {
            vector<Patient> patientQueue_t = {};
            bool flag = true;//set to false so for loop doesnt change indexCritical after initial critical status
            for (int i = 0; i < patientQueue.size(); i++) {//finds last occurence of status == critical
                if (patientQueue.at(index).patientQueue.at(i).GetStatus() != status_t && flag) {
                    indexCritical = i;
                    flag = false;
                    patientQueue.at(index).patientQueue.pop_back();
                    cout << "Non critical patient removed from end of queue\n";
                }
            }
            patientQueue.at(index).patientQueue.insert(patientQueue.at(index).patientQueue.begin() + indexCritical, Patient(first_t, last_t, ssn_t, status_t));
        }
    }

}
void Patient::RemoveForOperation(){}


//void Patient::CancelPatient(){}
//if SSN does not exist write error
//SSN exist - print patient info and status and remove from queue
void Patient::CancelPatient(string first_t, string last_t, string ssn_t, vector<Patient> patientQueue){
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




