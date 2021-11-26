/* 
 * File:   Procedure.h
 * Author: Sonya Smalley
 * Created on October 30, 2021, 2:24 PM
 * Purpose: Implement a procedure class
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H
#include <string>
using namespace std;

class Procedure {
private:
    string name; //name of a procedure
    string date; //date that the procedure was performed for a patient
    string doctor; //name of the practitioner who performed the procedure
    float cost; //charges for the procedure
public:
    Procedure(string,string,string,float); //Constructor initializes procedure member variables
    void setName(string n){ //set procedure name
        name=n;
    }
    void setDate(string d){ //set procedure date
        date=d;
    }
    void setDoc(string doc){ //set procedure doctor
        doctor=doc;
    }
    void setCost(float c){ //set emergency contact phone number
        cost=c;
    }
    void dspPrcd() const; //display patient info
};

#endif /* PROCEDURE_H */

