/* 
 * File:   DayOfYear.cpp
 * Author: Sonya Smalley 
 * Created on November 11, 2021, 11:38 AM
 * Purpose: Create a DayOfYear class (not for leap years)
 */

#include "DayOfYear.h"
#include <iostream>
#include <string>
using namespace std;

//Definition of static member variables
string DayOfYear::month[12]={"January","February","March","April","May","June",
                "July","August","September","October","November","December"};

void DayOfYear::print(){
    if (day<=31){ //January
        cout<<month[0]<<" "<<day<<endl;
    }
    else if (day<=59){ //February
        day-=31;
        cout<<month[1]<<" "<<day<<endl;
    }
    else if (day<=90){ //March
        day-=59;
        cout<<month[2]<<" "<<day<<endl;
    }
    else if (day<=120){ //April
        day-=90;
        cout<<month[3]<<" "<<day<<endl;
    }
    else if (day<=151){ //May
        day-=120;
        cout<<month[4]<<" "<<day<<endl;
    }
    else if (day<=181){ //June
        day-=151;
        cout<<month[5]<<" "<<day<<endl;
    }
    else if (day<=212){ //July
        day-=181;
        cout<<month[6]<<" "<<day<<endl;
    }
    else if (day<=243){ //August
        day-=212;
        cout<<month[7]<<" "<<day<<endl;
    }
    else if (day<=273){ //September
        day-=243;
        cout<<month[8]<<" "<<day<<endl;
    }
    else if (day<=304){ //October
        day-=273;
        cout<<month[9]<<" "<<day<<endl;
    }
    else if (day<=334){ //November
        day-=304;
        cout<<month[10]<<" "<<day<<endl;
    }
    else if (day<=365){ //December
        day-=334;
        cout<<month[11]<<" "<<day<<endl;
    }
}