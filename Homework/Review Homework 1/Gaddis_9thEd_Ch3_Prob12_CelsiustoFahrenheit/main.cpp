/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 4, 2021, 11:29 AM
 * Purpose: Convert Celsius temperature to Fahrenheit temperature.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions


//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    float cTemp, fTemp;

    //Initialize Variables
    cout<<"Enter a temperature in degrees Celsius: ";
    cin>>cTemp;
    fTemp=cTemp*(9.0/5)+32.0;
    
    //Display Outputs
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout<<"The temperature in degrees Fahrenheit is "<<fTemp<<" degrees.\n";
    
    //Exit stage right!
    return 0;
}

