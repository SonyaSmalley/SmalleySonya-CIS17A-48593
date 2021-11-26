/* 
 * File:   Inventory.cpp
 * Author: Sonya Smalley 
 * Created on November 5, 2021, 11:48 AM
 * Purpose: Create an Inventory class
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
private:
    int itemNum; //the item's item number
    int quanty; //the quantity of the item on hand
    float cost; //wholesale per-unit cost of the item
    float ttlCost; //total inventory cost of the item (quantity * cost)
public:
    Inventory(); //default constructor
    Inventory(int,int,float); //constructor accepts item's num, quantity, and cost
    void setItmN(int n){ //set item number
        itemNum=n;
    }
    void setQuan(int q){ //set quantity of item
        quanty=q;
    }
    void setCost(float c){ //set wholesale per-unit cost
        cost=c;
    }
    void setTot(){ //set the total inventory cost
        ttlCost=quanty*cost;
    }
    int getItmN() const{ //returns the value in itemNum
        return itemNum;
    }
    int getQuan() const{ //returns the value in quanty
        return quanty;
    }
    float getCost() const{ //returns the value in cost
        return cost;
    }
    float getTot() const{ //returns the value in ttlCost
        return ttlCost;
    }
};

#endif /* INVENTORY_H */

