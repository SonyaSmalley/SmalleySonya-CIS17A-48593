/* 
 * File:   TimeOff.h
 * Author: Sonya Smalley
 * Created on November 11, 2021, 4:43 PM
 * Purpose: Create a TimeOff class
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H
#include <iostream>
#include <string>
#include "NumDays.h"
using namespace std;

class TimeOff {
private:
    string name; //employee name
    short empNum; //employee number
    NumDays maxSick; //max sick days that may be taken
    NumDays sickUsd; //number of sick days actually taken
    NumDays maxVaca; //max vacation days that may be taken
    NumDays vacaUsd; //number of vacation days actually taken
    NumDays maxUnpd; //max unpaid days that may be taken
    NumDays unpdUsd; //number of unpaid days actually taken
public:
    TimeOff(string n,short e); //constructor
    void setSUsd(short h){
        sickUsd.setHrs(h);
    }
    void setVUsd(short h){
        while (h>240){
            cout<<"Invalid number of vacation hours. Cannot exceed 240 hours.\n";
            cout<<"Enter the number of vacation hours: ";
            cin>>h;
        }
        vacaUsd.setHrs(h);
    }
    void setUUsd(short h){
        unpdUsd.setHrs(h);
    }
    string getName(){
        return name;
    }
    short getEmpn(){
        return empNum;
    }
    short getShrUsd(){
        sickUsd.getHrs();
    }
    short getVhrUsd(){
        vacaUsd.getHrs();
    }
    short getUhrUsd(){
        unpdUsd.getHrs();
    }
    float getSdyUsd(){
        sickUsd.getDays();
    }
    float getVdyUsd(){
        vacaUsd.getDays();
    }
    float getUdyUsd(){
        unpdUsd.getDays();
    }
};

#endif /* TIMEOFF_H */

