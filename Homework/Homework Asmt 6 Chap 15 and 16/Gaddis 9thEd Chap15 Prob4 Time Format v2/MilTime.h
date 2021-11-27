/* 
 * File:   MilTime.h
 * Author: Sonya Smalley 
 * Created on November 23, 2021, 10:56 PM
 * Purpose: Create a MilTime class
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

const short DIGITS=5; //number of digits required for military format + \0

class MilTime : public Time {
private:
    char milHrs[DIGITS]; //the time in military format
    int secs; //the seconds
public:
    //Default Constructor
    MilTime():Time(){
        for (short i=0;i<DIGITS;i++)
            milHrs[i]=0;
        secs=0;
    }
    //Constructor
    MilTime(char mH[],int s);
    //Mutator Function
    void setTime(char mH[],int s);
    //Accessor Functions
    int getHour() {
        int h=(10*(milHrs[0]-48))+(milHrs[1]-48);
        return h;
    }
    int getStandHr() const{
        return hour;
    }
};

#endif /* MILTIME_H */

