/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 11, 2021, 4:42 PM
 * Purpose: Implement a NumDays class
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries
#include "NumDays.h"
#include "TimeOff.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    short hours=rand()%30+30;
    NumDays work1(hours),work2,work;
    work2.setHrs(rand()%30+1);
    TimeOff person("George Ramos",4422);
    
    
    //Do things with the work hours
    cout<<"Week 1: "<<work1.getHrs()<<" = "<<work1.getDays()<<" days"<<endl;
    cout<<"Week 2: "<<work2.getHrs()<<" = "<<work2.getDays()<<" days"<<endl;
    work=work1-work2;
    cout<<person.getName()<<" worked a difference of "<<work.getHrs()
            <<" hours between the weeks\n";
    work1++;
    ++work1;
    --work2;
    work2--;
    cout<<"Errors have been found in the reported hours. Here are the "
            "corrected hours:\n";
    cout<<"Week 1: "<<work1.getHrs()<<" = "<<work1.getDays()<<" days"<<endl;
    cout<<"Week 2: "<<work2.getHrs()<<" = "<<work2.getDays()<<" days"<<endl;
    work=work1+work2;
    cout<<"The total for the pay period is "<<work.getHrs()<<" hours ("
            <<work.getDays()<<" days)\n";
    
    //Do stuff with the sick, vacation, and paid hours
    person.setSUsd(24); //enter sick used
    person.setVUsd(80); //enter vacation used
    person.setUUsd(5); //enter unpaid used
    cout<<"As of last pay period, "<<person.getName()<<" had used "<<person.getSdyUsd()
            <<" sick days, "<<person.getVdyUsd()<<" vacation days, and "
            <<person.getUhrUsd()<<" unpaid hours.\n";
    
    //Exit stage right!
    return 0;
}

