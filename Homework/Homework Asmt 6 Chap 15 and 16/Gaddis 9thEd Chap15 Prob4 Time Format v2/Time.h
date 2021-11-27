/* 
 * File:   Time.cpp
 * Author: Gaddis
 * Created on November 23, 2021, 10:52 PM
 * Copied from Time.h on page 972
 */

#ifndef TIME_H
#define TIME_H

class Time {
protected:
    int hour;
    int min;
    int sec;
public:
    //Default constructor
    Time(){
        hour=0; min=0; sec=0;
    }
    //Constructor
    Time(int h,int m,int s){
        hour=h; min=m; sec=s;
    }
    //Accessor Functions
    int getHour() const{
        return hour;
    }
    int getMin() const{
        return min;
    }
    int getSec() const{
        return sec;
    }
};

#endif /* TIME_H */
