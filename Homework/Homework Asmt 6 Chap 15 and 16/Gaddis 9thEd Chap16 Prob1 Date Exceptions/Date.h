/* 
 * File:   Date.h
 * Author: Sonya Smalley *
 * Created on October 29, 2021, 3:28 PM
 * Purpose: Implement a date class
 */

#ifndef DATE_H
#define DATE_H

class Date {
private:
    unsigned short month; //month
    unsigned short day; //day
    unsigned short year; //year
public:
    //Exception class for an invalid month
    class InvalidMonth{
    private:
        short val; //invalid value entered by the user
    public:
        InvalidMonth(short v){ //constructor
            val=v;
        }
        short getVal() const{ //accessor
            return val;
        }
    };
    //Exception class for an invalid day
    class InvalidDay{
    private:
        short val; //invalid value entered by the user
    public:
        InvalidDay(short v){ //constructor
            val=v;
        }
        short getVal() const{ //accessor
            return val;
        }
    };
    Date ();//Default constructor
    void setMnth(unsigned short); //Set the month
    void setDay(unsigned short); //Set the day
    void setYear(unsigned short); //Set the year
    void mdySlsh() const; //Format date 12/25/2018
    void mdyWrd() const; //Format date December 25,2018
    void dmyWrd() const; //Format date 25 December 2018
};

#endif /* DATE_H */

