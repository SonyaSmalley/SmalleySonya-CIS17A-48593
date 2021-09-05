/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 4, 2021, 12:37 PM
 * Purpose: Predict the size of a population of organisms based on their
 *          starting numbers, average daily increase, and the number of days
 *          they will be left to multiply. Display the daily population size.
 */

//System Libraries
#include <iostream>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int size, numDays; //variables for population size and days to multiply
    float grwRate; //growth rate
    
    //Initialize Variables
    do
    {
        cout<<"Enter the starting population size: ";
        cin>>size;
    }
    while (size<2); //make sure that there are at least 2 individuals to start
    
    do
    {
        cout<<"Enter the average daily increase as a percentage: ";
        cin>>grwRate;
        grwRate/=100.0; //turn it into a decimal
    }
    while (grwRate<0); //make sure it's a growth rate - this is not death rate
    
    do
    {
    cout<<"Enter the number of days for population increase: ";
    cin>>numDays;
    cout<<"\nFollowing is the population size after each day has passed:\n";
    }
    while (numDays<0); //make sure that it's a realistic number of days
    
    //Display Outputs
    for (int i=0; i<numDays; i++)
    {
        size+=(size*grwRate);
        cout<<"Day "<<(i+1)<<": "<<size<<endl;
    }
    //Exit stage right!
    return 0;
}

