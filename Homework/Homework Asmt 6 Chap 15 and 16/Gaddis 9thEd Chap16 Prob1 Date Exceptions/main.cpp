/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 27, 2021, 3:54 PM
 * Purpose: Demonstrate exception classes for Date
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Date.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    unsigned short num; //variable to temporarily hold values
    Date usrDate; //To hold the date
    bool again=true; //Flag to reread input
    
    //Initialize Variables
    //Get the month
    cout<<"Program will display a date in 3 different formats\n"
            "Enter the month (1 - 12): ";
    cin>>num;
    while (again){
        try{
            usrDate.setMnth(num);
            again=false;
        }
        catch (Date::InvalidMonth m){
            cout<<"Error: "<<m.getVal()<<" is an invalid value for the month.\n";
            cout<<"Please re-enter the month (1 -12): ";
            cin>>num;
        }
    }
    
    //Get the day
    cout<<"Enter the day (1 - 31): ";
    cin>>num;
    again=true;
    while (again){
        try{
            usrDate.setDay(num);
            again=false;
        }
        catch (Date::InvalidDay d){
            cout<<"Error: "<<d.getVal()<<" is an invalid value for the day.\n";
            cout<<"Please re-enter the day (1 -31): ";
            cin>>num;
        }
    }
    
    //Get the month
    cout<<"Enter the year (yyyy): ";
    cin>>num;
    usrDate.setYear(num);
    
    //Display Outputs
    cout<<"\nYour date in 3 different formats:\n";
    usrDate.mdySlsh();
    usrDate.mdyWrd();
    usrDate.dmyWrd();

    //Exit stage right!
    return 0;
}

