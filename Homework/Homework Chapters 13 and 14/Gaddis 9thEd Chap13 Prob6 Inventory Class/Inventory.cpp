/* 
 * File:   Inventory.cpp
 * Author: Sonya Smalley 
 * Created on November 5, 2021, 11:48 AM
 * Purpose: Create an Inventory class
 */

#include "Inventory.h"

Inventory::Inventory() {
    itemNum=0;
    quanty=0;
    cost=0.0f;
    setTot();
}

Inventory::Inventory(int n,int q,float c){ //constructor accepts item's num, quantity, and cost
    itemNum=n;
    quanty=q;
    cost=c;
    setTot();
}