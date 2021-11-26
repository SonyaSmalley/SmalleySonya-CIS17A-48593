/* 
 * File:   Date.cpp
 * Author: Sonya Smalley * 
 * Created on October 29, 2021, 3:28 PM
 * Purpose: Implement a date class
 */

#include <iostream>
#include "Date.h"
using namespace std;

//***********************************************
//Constructor sets a default date of 1/1/2020.  *
//***********************************************
Date::Date() {
    month=day=1; //January 1st,
    year=2020; //2020    
}

//***********************************************
//Sets the value for the member variable month  *
//***********************************************
void Date::setMnth(unsigned short m){
    //Validate the input for m (there are 12 months in a year)
    while (m<1 || m>12){
        cout<<"Invalid value for month. Please re-enter the month (1 -12): ";
        cin>>m;
    }
    
    month=m;
}

//***********************************************
//Sets the value for the member variable day    *
//***********************************************
void Date::setDay(unsigned short d){
    //Validate the input for d (there are no more than 31 days in a month)
    while (d<1 || d>31){
        cout<<"Invalid value for day. Please re-enter the day (1 - 31): ";
        cin>>d;
    }
    
    day=d;
}

//***********************************************
//Sets the value for the member variable year   *
//***********************************************
void Date::setYear(unsigned short y){
    year=y;
}

//***********************************************
//Output the date in format 12/25/2018          *
//***********************************************
void Date::mdySlsh() const{
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}

//***********************************************
//Output the date in format December 25,2018    *
//***********************************************
void Date::mdyWrd() const{
    //Display the name of the month
    switch (month){
        case 1: cout<<"January ";
        break;
        case 2: cout<<"February ";
        break;
        case 3: cout<<"March ";
        break;
        case 4: cout<<"April ";
        break;
        case 5: cout<<"May ";
        break;
        case 6: cout<<"June ";
        break;
        case 7: cout<<"July ";
        break;
        case 8: cout<<"August ";
        break;
        case 9: cout<<"September ";
        break;
        case 10: cout<<"October ";
        break;
        case 11: cout<<"November ";
        break;
        case 12: cout<<"December ";
        break;
    }
    //Display the day and year
    cout<<day<<", "<<year<<endl;
}

//***********************************************
//Output the date in format 25 December 2018    *
//***********************************************
void Date::dmyWrd() const{
    //Display the day
    cout<<day<<" ";
    
    //Display the name of the month
    switch (month){
        case 1: cout<<"January ";
        break;
        case 2: cout<<"February ";
        break;
        case 3: cout<<"March ";
        break;
        case 4: cout<<"April ";
        break;
        case 5: cout<<"May ";
        break;
        case 6: cout<<"June ";
        break;
        case 7: cout<<"July ";
        break;
        case 8: cout<<"August ";
        break;
        case 9: cout<<"September ";
        break;
        case 10: cout<<"October ";
        break;
        case 11: cout<<"November ";
        break;
        case 12: cout<<"December ";
        break;
    }
    //Display the year
    cout<<year<<endl;
}