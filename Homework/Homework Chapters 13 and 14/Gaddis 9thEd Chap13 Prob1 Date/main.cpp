/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on October 29, 2021, 2:56 PM
 * Purpose: Implement a class to format a date
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
    
    //Initialize Variables
    //Get the month
    cout<<"Program will display a date in 3 different formats\n"
            "Enter the month (1 - 12): ";
    cin>>num;
    usrDate.setMnth(num);
    
    //Get the day
    cout<<"Enter the month (1 - 31): ";
    cin>>num;
    usrDate.setDay(num);
    
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

