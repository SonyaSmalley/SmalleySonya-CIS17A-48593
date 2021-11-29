/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 27, 2021, 4:27 PM
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
    char milTime[DIGITS];
    int sec;
    bool again=true; //Flag to reread input
    
    //Initialize Variables
    cout<<"Enter a time in military format: ";
    cin>>milTime;
    
    cout<<"Enter the seconds: ";
    cin>>sec;
    
    while(again){
        try{
            MilTime mTime(milTime,sec);
            
            //Display Outputs
            cout<<"\nThe time you entered in military format and standard format:\n";
            cout<<mTime.getHour()<<":"<<mTime.getMin()<<":"
                    <<(mTime.getSec()<10?"0":"")<<mTime.getSec()<<endl;
            cout<<mTime.getStandHr()<<":"<<mTime.getMin()<<":"<<mTime.getSec()<<endl;
            
            again=false;
        }
        catch(MilTime::BadHour){
            cout<<"Error: Military time is between 0000 and 2359."
                  "\nEnter a valid time: ";
            cin>>milTime;
        }
        catch(MilTime::BadSeconds){
            cout<<"Error: Seconds can be between 0 and 59."
                  "\nEnter a valid number of seconds: ";
            cin>>sec;
        }
    }
        
    //Exit stage right!
    return 0;
}

