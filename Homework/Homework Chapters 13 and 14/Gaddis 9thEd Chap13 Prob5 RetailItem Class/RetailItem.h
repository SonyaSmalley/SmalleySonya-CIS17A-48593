/* 
 * File:   RetailItem.h
 * Author: Sonya Smalley
 * Created on November 5, 2021, 10:52 AM
 * Purpose: Create a RetailItem class
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H
#include <string>
using namespace std;

class RetailItem {
private:
    string dscrptn; //brief description of the item
    int units; //units currently in inventory
    float price; //item's retail price
public:
    RetailItem(string,int,float); //Constructor
    void setDesc(string d){ //Mutator to set description
        dscrptn=d;
    }
    void setUnit(int u){ //Mutator to set count of units
        units=u;
    }
    void setPrc(float p){ //Mutator to set price
        price=p;
    }
    void getItem() const; //Accessor to display description
};

#endif /* RETAILITEM_H */

