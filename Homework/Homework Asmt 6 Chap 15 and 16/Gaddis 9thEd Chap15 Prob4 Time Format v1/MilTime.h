/* 
 * File:   MilTime.h
 * Author: Sonya Smalley 
 * Created on November 23, 2021, 10:56 PM
 * Purpose: Create a MilTime class
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

class MilTime : public Time {
private:
    int milHrs; //the time in military format
    int secs; //the seconds
public:
    //Default Constructor
    MilTime():Time(){
        milHrs=0;
        secs=0;
    }
    //Constructor
    MilTime(int mH,int s);
    //Mutator Function
    void setTime(int mH,int s);
    //Accessor Functions
    int getHour() const{
        return milHrs;
    }
    int getStandHr() const{
        return hour;
    }
};

#endif /* MILTIME_H */

