/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 5, 2021, 12:54 PM
 * Purpose: Create a circle class
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Circle.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    float radius;

    //Initialize Variables
    cout<<"Enter the radius of a circle: ";
    cin>>radius;
    //Create a circle object
    Circle circle(radius);
    
    //Display Outputs
    cout<<"\nYour Circle\n";
    cout<<"Area: "<<circle.getArea()<<endl;
    cout<<"Diameter: "<<circle.getDi()<<endl;
    cout<<"Circumference: "<<circle.getCmfnc()<<endl;

    //Exit stage right!
    return 0;
}

