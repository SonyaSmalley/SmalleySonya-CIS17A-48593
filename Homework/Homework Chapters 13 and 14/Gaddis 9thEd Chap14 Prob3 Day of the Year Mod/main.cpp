/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 11, 2021, 11:37 AM
 * Purpose: Convert a day of the year written as a single integer into its
 *          month and day form
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "DayOfYear.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    unsigned short dayNum; //to hold the day

    //Initialize Variables
    cout<<"Enter a day of the year as a single integer: ";
    cin>>dayNum;
    DayOfYear day(dayNum);

    //Display Outputs
    day.print();
    
    //Exit stage right!
    return 0;
}

