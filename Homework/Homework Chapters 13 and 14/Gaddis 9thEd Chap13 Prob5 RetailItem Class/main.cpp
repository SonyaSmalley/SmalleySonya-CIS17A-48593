/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 5, 2021, 10:48 AM
 * Purpose: Create 3 RetailItem objects.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "RetailItem.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    //Create 3 retail items
    RetailItem item1("Jacket",12,59.95),
               item2("Designer Jeans",40,34.95),
               item3("Shirt",20,24.95);
    
    //Display a table of the 3 items
    cout<<"\t\tDescription\tUnits On Hand\tPrice\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"Item #1\t\t";
    item1.getItem();
    cout<<"Item #2\t\t";
    item2.getItem();
    cout<<"Item #3\t\t";
    item3.getItem();
    
    //Exit stage right!
    return 0;
}

