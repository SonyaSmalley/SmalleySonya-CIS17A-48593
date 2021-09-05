/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 4, 2021, 12:00 PM
 * Purpose: Determine how many days are in a given month for any given year.
 */

//System Libraries
#include <iostream>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    unsigned short days, month, year;
    char choice;
    
    //Initialize Variables
    cout<<"This program will tell you how many days are in a month in any "
            "given year.\n";
    
    //Loop to request the month and day and then display number of days
    do
    {
        cout<<"Please enter the number of the month: ";
        cin>>month;
        cout<<"Enter the year: ";
        cin>>year;

        //Determine how many days are in the month
        switch (month)
        {
            case 2: if (year%400==0)
                    {
                        days=29;
                    }
                    else
                        days=28;
                    break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:days=31;
                    break;
            default: days=30;
        }
    
        //Display Outputs
        cout<<"There are "<<days<<" days in "<<month<<"/"<<year<<endl;
        cout<<"Do you want to try another month and year? y/n? ";
        cin>>choice;
    }
    while (choice=='Y'||choice=='y');

    //Exit stage right!
    return 0;
}

