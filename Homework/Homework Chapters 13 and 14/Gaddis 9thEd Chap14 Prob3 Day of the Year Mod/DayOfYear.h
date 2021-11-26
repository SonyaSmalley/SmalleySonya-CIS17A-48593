/* 
 * File:   DayOfYear.h
 * Author: Sonya Smalley 
 * Created on November 11, 2021, 11:38 AM
 * Purpose: Create a DayOfYear class (not for leap years)
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <string>
using namespace std;

class DayOfYear {
private:
    unsigned short day; //day of the year
    static string month[12];
public:
    DayOfYear(int d){ //constructor sets the day
        day=d;
    }
    void print(); //print the day of the year in English
};

#endif /* DAYOFYEAR_H */

