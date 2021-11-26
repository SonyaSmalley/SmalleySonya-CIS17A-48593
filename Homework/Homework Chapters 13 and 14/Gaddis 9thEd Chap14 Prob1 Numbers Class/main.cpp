/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 9, 2021, 6:38 PM
 * Purpose: Implement a Numbers class, which prints the English version of
 *          an integer.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Numbers.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int n;

    //Initialize Variables
    cout<<"Enter a four digit positive integer: \n";
    cin>>n;
    
    //Create a numbers object
    Numbers num(n);
    
    //Display Outputs
    cout<<"Here is the English equivalent of your number: \n";
    num.print();    
    
    //Exit stage right!
    return 0;
}

