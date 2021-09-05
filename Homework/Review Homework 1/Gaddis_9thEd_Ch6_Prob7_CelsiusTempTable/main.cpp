/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 4, 2021, 1:09 PM
 * Purpose: Use a function named Celsius to display temperature conversions
 *          for 0 to 20 degrees Fahrenheit.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
float celsius (int fahr); //converts Fahrenheit to Celsius

//Execution Begins Here
int main(int argc, char** argv) {


    //Display Outputs
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    
    //Display a table of Fahrenheit temperatures converted to Celsius (range 0 to 20)
    cout<<"Fahrenheit              Celsius\n";
    for (int fTemp=0; fTemp<=20; fTemp++) //fTemp is Fahrenheit temperature
        cout<<fTemp<<"\t\t"<<celsius(fTemp)<<endl;

    //Exit stage right!
    return 0;
}

//Input is temp in Fahrenheit
//Returns the temperature converted to Celsius
float celsius (int fahr)
{
    return (5/9.0)*(fahr-32.0);
}