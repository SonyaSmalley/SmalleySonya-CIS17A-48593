/* 
 * File:   NumDays.cpp
 * Author: Sonya Smalley 
 * Created on November 11, 2021, 4:42 PM
 * Purpose: Create a NumDays class
 */

#include "NumDays.h"

//Overload the + operator
NumDays NumDays::operator - (const NumDays &right){
    NumDays temp;
    
    //Set temporary NumDays object equal to the left and right NumDays
    temp.hours=hours-right.hours;
    temp.days=days-right.days;
    temp.setDays();
    return temp;
}

//Overload the - operator
NumDays NumDays::operator + (const NumDays &right){
    NumDays temp;
    
    //Set temporary NumDays object equal to the left and right NumDays
    temp.hours=hours+right.hours;
    temp.days=days+right.days;
    temp.setDays();
    return temp;
}

//Overload the prefix ++ operator
NumDays NumDays::operator ++ (){
    ++hours;
    setDays();
    return *this;
}

//Overload the postfix ++ operator
NumDays NumDays::operator ++ (int){
    hours++;
    setDays();
    return days;
}

//Overload the prefix -- operator
NumDays NumDays::operator -- (){
    --hours;
    setDays();
    return *this;
}

//OverlNumDays::oad the postfix -- operator
NumDays NumDays::operator -- (int){
    hours--;
    setDays();
    return days;
}
