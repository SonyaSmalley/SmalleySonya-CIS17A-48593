/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 11, 2021, 2:19 PM
 * Purpose: Implement a NumDays class
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries
#include "NumDays.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    short hours=rand()%30+30;
    NumDays work1(hours),work2,work;
    work2.setHrs(rand()%30+1);
    
    //Do things with the work hours
    cout<<"Week 1: "<<work1.getHrs()<<" = "<<work1.getDays()<<" days"<<endl;
    cout<<"Week 2: "<<work2.getHrs()<<" = "<<work2.getDays()<<" days"<<endl;
    work=work1-work2;
    cout<<"You worked a difference of "<<work.getHrs()<<" hours between the weeks\n";
    work1++;
    ++work1;
    --work2;
    work2--;
    cout<<"Errors have been found in your reported hours. Here are the "
            "corrected hours:\n";
    cout<<"Week 1: "<<work1.getHrs()<<" = "<<work1.getDays()<<" days"<<endl;
    cout<<"Week 2: "<<work2.getHrs()<<" = "<<work2.getDays()<<" days"<<endl;
    work=work1+work2;
    cout<<"Your total for the pay period is "<<work.getHrs()<<" hours ("
            <<work.getDays()<<" days)\n";
    
    //Exit stage right!
    return 0;
}

