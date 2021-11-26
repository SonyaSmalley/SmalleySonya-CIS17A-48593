/* 
 * File:   Patient.cpp
 * Author: Sonya Smalley 
 * Created on October 29, 2021, 4:41 PM
 * Purpose: Implement a patient class
 */

#include "Patient.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//*********************************************************************
//Constructor accepts arguments for patient name, address, and phone  *
//number, as well as their emergency contact's name and phone number. *
//Initializes the member variables.                                   *
//*********************************************************************
Patient::Patient(string n,string a,char p[],string eN,char eP[]){
    //Initialize the variables
    setName(n);
    setAdrs(a);
    setPhn(p);
    setEmNm(eN);
    setEmPh(eP);
}

//*******************************************
//Set the value for member function phone.  *
//*******************************************
void Patient::setPhn(char p[]){
    strcpy(phone,p);
}

//*******************************************
//Set the value for member function emrgPhn. *
//*******************************************
void Patient::setEmPh(char eP[]){
    strcpy(emrgPhn,eP);
}

//*******************************************
//Display patient information.              *
//*******************************************
void Patient::dspPtnt() const{
    cout<<"Patient Information\n";
    cout<<"\tName: "<<name<<endl;
    cout<<"\tAddress: "<<adrs<<endl;
    cout<<"\tPhone Number: "<<phone<<endl;
    cout<<"\tEmergency Contact: "<<emrgNm<<endl;
    cout<<"\tEmergency Contact Phone: "<<emrgPhn<<endl;
}