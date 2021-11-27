/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 23, 2021, 10:50 PM
 * Purpose: Demonstrate a MilTime class
 */

//System Libraries
#include <iostream>
#include "MilTime.h"
#include "Time.h"
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int milTime;
    int sec;
    
    //Initialize Variables
    cout<<"Enter a time in military format: ";
    cin>>milTime;
    
    cout<<"Enter the seconds: ";
    cin>>sec;
    
    MilTime mTime(milTime,sec);
    
    //Display Outputs
    cout<<"The time you entered in military format and standard format:\n";
    cout<<mTime.getHour()<<":"<<mTime.getSec()<<endl;
    cout<<mTime.getStandHr()<<":"<<mTime.getMin()<<":"<<mTime.getSec()<<endl;
    
    //Exit stage right!
    return 0;
}

