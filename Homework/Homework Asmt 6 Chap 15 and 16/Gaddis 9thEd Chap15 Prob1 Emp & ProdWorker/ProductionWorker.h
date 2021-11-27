/* 
 * File:   ProductionWorker.h
 * Author: Sonya Smalley 
 * Created on November 23, 2021, 10:18 PM
 * Purpose: Create a ProductionWorker class
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include "Employee.h"

class ProductionWorker : public Employee {
private:
    short shift; //day (1) or night (2) shift
    float payRate; //hourly pay rate
public:
    //Default constructor
    ProductionWorker(){
        shift=1;
        payRate=0.0f;
    }
    //Constructor
    ProductionWorker(string n,short e,string h,short s,float p):Employee(n,e,h){
        shift=s;
        payRate=p;
    }
    //Accessor functions
    short getShft() const{
        return shift;
    }
    float getPyRt() const{
        return payRate;
    }
};

#endif /* PRODUCTIONWORKER_H */

