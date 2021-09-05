/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 4, 2021, 11:43 AM
 * Purpose: Convert US dollars to Japanese yen and to euros.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    const float YENPERD=109.71f, EURPERD=0.84f;
    float dollyen, dolleur;

    //Initialize Variables and Display Outputs
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout<<"Enter the amount of dollars you wish to convert to yen: ";
    cin>>dollyen;   
    cout<<"That will get you "<<dollyen*YENPERD<<" yen.\n";
    
    cout<<"Enter the amount of dollars you wish to convert to euros: ";
    cin>>dolleur;
    cout<<"That will get you "<<dolleur*EURPERD<<" euros.\n";

    //Exit stage right!
    return 0;
}

