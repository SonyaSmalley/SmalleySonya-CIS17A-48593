/* 
 * File:   NumDays.h
 * Author: Sonya Smalley 
 * Created on November 11, 2021, 2:20 PM
 * Purpose: Create a NumDays class
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {
private:
    short hours;
    float days;
public:
    //Constructor
    NumDays(short h=0){
        setHrs(h);
        setDays();
    }
    //Mutators
    void setHrs(short h){
        hours=h;
        setDays();
    }
    void setDays(){
        days=hours/8.0;
    }
    //Accessors
    short getHrs() const{
        return hours;
    }
    float getDays() const{
        return days;
    }
    //Overloaded operators
    NumDays operator - (const NumDays &);
    NumDays operator + (const NumDays &);
    NumDays operator ++ ();
    NumDays operator ++ (int);
    NumDays operator -- ();
    NumDays operator -- (int);
};

#endif /* NUMDAYS_H */

