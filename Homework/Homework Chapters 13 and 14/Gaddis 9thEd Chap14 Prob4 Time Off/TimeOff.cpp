/* 
 * File:   TimeOff.cpp
 * Author: Sonya Smalley
 * Created on November 11, 2021, 4:43 PM
 * Purpose: Create a TimeOff class
 */

#include "TimeOff.h"
#include "NumDays.h"

//Constructor initializes name, empNum, and the max days
TimeOff::TimeOff(string n,short e){ //constructor
        name=n;
        empNum=e;
        maxSick.setHrs(40); //5 days of sick time allowed
        maxVaca.setHrs(240); //30 days of vacation time accrual allowed
        maxUnpd.setHrs(3); //3 days of unpaid time allowed
    }
