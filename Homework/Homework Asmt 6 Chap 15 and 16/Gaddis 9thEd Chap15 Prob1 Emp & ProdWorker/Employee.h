/* 
 * File:   Employee.h
 * Author: Sonya Smalley 
 * Created on November 23, 2021, 7:15 PM
 * Purpose: Create an Employee class
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
private:
    string name; //employee name
    short empNum; //employee number
    string hireDt; //employee hire date
public:
    //Default constructor
    Employee(){
        name="";
        empNum=0;
        hireDt="1/1/2000";
    }
    Employee(string n,short e,string h){
        name=n;
        empNum=e;
        hireDt=h;
    }
    //Mutator functions
    void setName(string n){
        name=n;
    }
    void setEmpN(short e){
        empNum=e;
    }
    void setHrDt(string h){
        hireDt=h;
    }
    //Accessor functions
    string getName() const{
        return name;
    }
    short getEmpN() const{
        return empNum;
    }
    string getHrDt() const{
        return hireDt;
    }
};

#endif /* EMPLOYEE_H */

