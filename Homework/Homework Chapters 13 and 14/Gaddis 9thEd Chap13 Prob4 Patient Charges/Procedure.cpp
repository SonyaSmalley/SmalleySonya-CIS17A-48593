/* 
 * File:   Procedure.cpp
 * Author: Sonya Smalley
 * Created on October 30, 2021, 2:24 PM
 * Purpose: Implement a procedure class
 */

#include "Procedure.h"
#include <iostream>
#include <string>
#include <ios>
using namespace std;

//********************************************************************
//Constructor accepts arguments for procedure's name, date, doctor,  *
//and cost.                                                          *
//Initializes the member variables.                                  *
//********************************************************************
Procedure::Procedure(string n,string d,string doc,float c){
    //Initialize the variables
    setName(n);
    setDate(d);
    setDoc(doc);
    setCost(c);
}

//*******************************************
//Display procedure information.            *
//*******************************************
void Procedure::dspPrcd() const{
    cout<<"\tProcedure Name: "<<name<<endl;
    cout<<"\tDate: "<<date<<endl;
    cout<<"\tPractitioner: "<<doctor<<endl;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"\tCharge: "<<cost<<endl;
}
