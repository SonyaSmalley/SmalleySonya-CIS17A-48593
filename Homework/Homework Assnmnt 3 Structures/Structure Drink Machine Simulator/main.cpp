/* 
 * File: main
 * Author: Sonya Smalley
 * Created on September 29, 2021, 9:06 PM
 * Purpose: Simulate a vending machine
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
struct Drinks //Drinks in the vending machine
{
  string name; //drink names
  short cost; //drink costs in cents
  short count; //number of drinks available
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    short FLAVORS=5; //Number of flavors available
    Drinks soda[FLAVORS]={{"Cola",75,20}, //Array of drinks used in the machine
                         {"Root Beer",75,20},
                         {"Lemon-Lime",75,20},
                         {"Grape Soda",80,20},
                         {"Cream Soda",80,20}};
    Drinks choice; //Customer drink choice or choice to quit, and payment
    short change=0, //Change owed to the customer
          sales=0; //Total sales for the drink machine
    
    //Run the drink machine
    do
    {
        //Display drink selection with prices and the number of each drink available
        for (int i=0;i<FLAVORS;i++)
            cout<<left<<setw(10)<<soda[i].name<<" "<<soda[i].cost<<"  "<<soda[i].count<<endl;
        
        //Get user input: either soda choice or quit
        getline(cin,choice.name);
        if (choice.name!="Quit")
        {
            for (int i=0;i<FLAVORS;i++)
            {
                if (choice.name==soda[i].name)
                {
                    cin>>choice.cost;
                    //Make sure the user put in a reasonable amount of money
                    if (choice.cost<soda[i].cost||choice.cost>100)
                        cout<<"Not enough change\n";
                    else if (choice.cost<0)
                        cout<<"What are you trying to pull here?\n";
                    //Check if there's any soda left to sell them
                    if (soda[i].count<1)
                        cout<<"Sold out\n";
                    //If there's soda left, remove it from inventory, calculate the change, and add this sale to the total sales
                    else
                    {
                        soda[i].count--;
                        change=choice.cost-soda[i].cost;
                        sales+=choice.cost-change;
                    }
                }
            }
        }
        cout<<"Quit\n"<<((choice.name=="Quit")?sales:change)<<endl;
        //cin.ignore();
    }
    while (choice.name!="Quit");
    
    //Exit stage right!
    return 0;
}