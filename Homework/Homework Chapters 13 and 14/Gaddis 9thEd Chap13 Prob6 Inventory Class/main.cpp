/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 5, 2021, 11:46 AM
 * Purpose: Implement an Inventory class
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Inventory.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int itmNum, //item number
        qnty; //item quantity
    float cst; //item wholesale cost
    Inventory item1; //inventory item 1
    
    //Initialize Variables
    //Get the first item
    cout<<"Please provide the following information "
            "on the inventory on hand for an item:\n";
    //Get the item number from the user
    cout<<"Item Number: ";
    cin>>itmNum;
    while (itmNum<0){ //validate the user's entry (negative numbers not allowed)
        cout<<"Invalid entry. Please enter the item number: ";
        cin>>itmNum;
    }
    item1.setItmN(itmNum);
    //Get the item quantity from the user
    cout<<"Item Quantity: ";
    cin>>qnty;
    while (qnty<0){ //validate the user's entry (negative numbers not allowed)
        cout<<"Invalid entry. Please enter the item quantity: ";
        cin>>qnty;
    }
    item1.setQuan(qnty);
    //Get the item cost from the user
    cout<<"Item Cost: ";
    cin>>cst;
    while (cst<0){ //validate the user's entry (negative numbers not allowed)
        cout<<"Invalid entry. Please enter the item cost: ";
        cin>>cst;
    }
    item1.setCost(cst);
    item1.setTot();
    
    //Get the second item
    cout<<"Please provide the following information "
            "on the inventory on hand for a second item:\n";
    //Get the item number from the user
    cout<<"Item Number: ";
    cin>>itmNum;
    while (itmNum<0){ //validate the user's entry (negative numbers not allowed)
        cout<<"Invalid entry. Please enter the item number: ";
        cin>>itmNum;
    }
    //Get the item quantity from the user
    cout<<"Item Quantity: ";
    cin>>qnty;
    while (qnty<0){ //validate the user's entry (negative numbers not allowed)
        cout<<"Invalid entry. Please enter the item quantity: ";
        cin>>qnty;
    }
    //Get the item cost from the user
    cout<<"Item Cost: ";
    cin>>cst;
    while (cst<0){ //validate the user's entry (negative numbers not allowed)
        cout<<"Invalid entry. Please enter the item cost: ";
        cin>>cst;
    }
    //Initialize inventory item 2
    Inventory item2(itmNum,qnty,cst);
    
    //Display inventory information
    cout<<"\nCurrent Inventory\n";
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    //Display item 1
    cout<<"Item Number: "<<item1.getItmN()<<endl;
    cout<<"Item Quantity: "<<item1.getQuan()<<endl;
    cout<<"Item Cost: $"<<item1.getCost()<<endl;
    cout<<"Inventory Cost: $"<<item1.getTot()<<endl<<endl;
    cout.precision(2);
    //Display item 2
    cout<<"Item Number: "<<item2.getItmN()<<endl;
    cout<<"Item Quantity: "<<item2.getQuan()<<endl;
    cout<<"Item Cost: $"<<item2.getCost()<<endl;
    cout<<"Inventory Cost: $"<<item2.getTot()<<endl<<endl;
    
    //Exit stage right!
    return 0;
}

