/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 23, 2021, 7:14 PM
 * Purpose: Demonstrate a base Employee class and its derived ProductionWorker class.
 */

//System Libraries
#include <iostream>
#include <string>
#include "Employee.h"
#include "ProductionWorker.h"
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    ProductionWorker person1("Apple Tini",1234,"2/24/2004",1,43.21);
    ProductionWorker person2("Rising Sun",2468,"3/6/2009",2,86.42);

    //Initialize Variables
    cout<<"Shift Leads:\n\n";
    cout<<"Name: "<<person1.getName()<<"\nEmployee ID: "<<person1.getEmpN()
        <<"\nHire Date: "<<person1.getHrDt()<<"\nShift: "
        <<(person1.getShft()==1?"Day":"Night")<<"\nHourly Pay: "
        <<person1.getPyRt()<<endl<<endl;
    cout<<"Name: "<<person2.getName()<<"\nEmployee ID: "<<person2.getEmpN()
        <<"\nHire Date: "<<person2.getHrDt()<<"\nShift: "
        <<(person2.getShft()==1?"Day":"Night")<<"\nHourly Pay: "
        <<person2.getPyRt()<<endl;
    
    //Display Outputs


    //Exit stage right!
    return 0;
}

