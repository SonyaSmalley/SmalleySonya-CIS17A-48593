/* 
 * File:   MilTime.h
 * Author: Sonya Smalley 
 * Created on November 23, 2021, 10:56 PM
 * Modified on November 27, 2021, 4:28 PM
 * Purpose: Create a MilTime class
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"
#include <iostream>
using namespace std;

const short DIGITS=5; //number of digits required for military format + \0

class MilTime : public Time {
private:
    char milHrs[DIGITS]; //the time in military format
    int secs; //the seconds
public:
    class BadHour{
    private:
        char val[DIGITS]; //to hold user value
    public:
        //Constructor
        BadHour(char v[]){
            for (short i=0;i<DIGITS;i++)
                val[i]=v[i];
        }
        //Accessor
        void getVal() const{
            for (short i=0;i<DIGITS;i++)
                cout<<val[i];
        }
    };
    class BadSeconds{
    private:
        int val; //to hold user value
    public:
        //Constructor
        BadSeconds(int v){
            val=v;
        }
        //Accessor
        int getVal() const{
            return val;
        }
    };
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

