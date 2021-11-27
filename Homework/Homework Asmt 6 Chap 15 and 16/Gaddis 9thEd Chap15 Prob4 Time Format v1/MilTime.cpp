/* 
 * File:   MilTime.h
 * Author: Sonya Smalley 
 * Created on November 23, 2021, 10:56 PM
 * Purpose: Create a MilTime class
 */

#include "MilTime.h"
#include "Time.h"
#include <iostream>
using namespace std;

//Constructor
MilTime::MilTime(int mH,int s):Time(){
    while (mH>2359 || mH<0){
        cout<<"Militarty time is between 0000 and 2359. Enter a valid time: ";
        cin>>mH;
    }
    while (s>59 || s<0){
        cout<<"Seconds can be between 0 and 59. Enter a valid number of seconds: ";
        cin>>s;
    }
    setTime(mH,s);
}

void MilTime::setTime(int mH,int s){
        milHrs=mH;
        secs=s;
        int h,m; //temporarily hold hours and minutes
        h=mH/100;
        m=mH%100;
        if (h>12)
            h-=12;
        hour=h;
        min=m;
        sec=s;
    }