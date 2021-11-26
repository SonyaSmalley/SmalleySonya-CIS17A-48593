/* 
 * File:   Patient.h
 * Author: Sonya Smalley
 * Created on October 29, 2021, 4:41 PM
 * Purpose: Create a patient class
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;

class Patient {
private:
    string name; //patient name
    string adrs; //patient address
    char phone[11]; //patient phone number
    string emrgNm; //emergency contact name
    char emrgPhn[11]; //emergency contact phone number
public:
    Patient(string,string,char [],string,char []); //Constructor initializes patient member variables
    void setName(string n){ //set patient name
        name=n;
    }
    void setAdrs(string a){ //set patient address
        adrs=a;
    }
    void setPhn(char p[]); //set patient phone number
    void setEmNm(string eN){ //set emergency contact name
        emrgNm=eN;
    }
    void setEmPh(char eP[]); //set emergency contact phone number
    void dspPtnt() const; //display patient info
};

#endif /* PATIENT_H */

