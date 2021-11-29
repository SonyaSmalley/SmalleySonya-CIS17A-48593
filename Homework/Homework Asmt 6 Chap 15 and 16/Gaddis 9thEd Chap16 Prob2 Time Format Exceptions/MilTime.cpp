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
MilTime::MilTime(char mH[],int s):Time(){
    if (mH[0]>'2' || ((mH[0]=='2' && mH[1]>'3') || (mH[0]=='2' && mH[1]=='3' && mH[2]>'5'))
            || (mH[0]<0 || mH[1]<0 || mH[2]<0 || mH[3]<0)){
        throw BadHour(mH);
    }
    if (s>59 || s<0){
        throw BadSeconds(s);
    }
    setTime(mH,s);
}

void MilTime::setTime(char mH[],int s){
        for (short i=0;i<DIGITS;i++)
            milHrs[i]=mH[i];
        milHrs[DIGITS]='\0';
        secs=s;
        int h,m; //temporarily hold hours and minutes
        h=(10*(mH[0]-48))+(mH[1]-48);
        m=(10*(mH[2]-48))+(mH[3]-48);
        if (h>12)
            h-=12;
        hour=h;
        min=m;
        sec=s;
    }