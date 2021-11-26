/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on October 29, 2021, 4:36 PM
 * Purpose: Create an instance for a patient class. Create 3 instances for a
 *          procedure class.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "Patient.h"
#include "Procedure.h"

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    //Initialize patient
    string name="Priscilla Hutchins", //Patient's name
           address="11 High Way, Roadtown, CA 92333", //Patient's address
           cntcNm="Elizabeth Moon"; //Patient's emergency contact's name
    char phone[]="9091112222", //Patient's phone number
         cntcPhn[]="9092223333"; //Patient's emergency contact's phone number
    Patient ptnt(name,address,phone,cntcNm,cntcPhn); //A patient
    
    //Initialize Procedures 1, 2, and 3
    string name1="Physical Exam", name2="X-ray", name3="Blood test", //procedure names
            date="10/30/2021", //date the procedures were performed
            doc1="Dr. Irvine", doc2="Dr. Jamison", doc3="Dr. Smith"; //practitioners
    float cost1=250.0f, cost2=500.0f, cost3=200.0f;
    Procedure first(name1,date,doc1,cost1), //first procedure
            second(name2,date,doc2,cost2), //second procedure
            third(name3,date,doc3,cost3); //third procedure

    //Display Outputs
    //Display Patient info
    ptnt.dspPtnt();
    
    //Display info on the procedures performed today
    cout<<"\nProcedure Information\n";
    cout<<"Procedure #1:\n";
    first.dspPrcd();
    cout<<"\nProcedure #2\n";
    second.dspPrcd();
    cout<<"\nProcedure #3\n";
    third.dspPrcd();
    
    //Exit stage right!
    return 0;
}
