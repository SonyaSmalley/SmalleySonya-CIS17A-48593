/* 
 * File:   RetailItem.h
 * Author: Sonya Smalley
 * Created on November 5, 2021, 10:52 AM
 * Purpose: Create a RetailItem class
 */

#include "RetailItem.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

RetailItem::RetailItem(string d,int u, float p) {
    setDesc(d); //set the value of description
    setUnit(u); //set the value of units
    setPrc(p); //set the value of price
}

void RetailItem::getItem() const{
    cout<<left<<setw(10)<<dscrptn<<"\t     "<<units<<"\t\t"<<price<<endl;
}