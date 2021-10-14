/* 
 * File: main
 * Author: Sonya Smalley
 * Created on 9/29/2021 @ 17:41
 * Purpose: Input quarterly sales for each regional division and output annual sales and average quarterly sales.
 */


//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
struct DivSales //Division Sales
{
    float salesQ1, //1st quarter sales
          salesQ2, //2nd quarter sales
          salesQ3, //3rd quarter sales
          salesQ4, //4th quarter sales
          salesAn, //Total annual sales
          salsAvQ; //Average quarterly sales
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    short numDivs=4; //Number of divisions 
    DivSales divsn[numDivs]; //Division sales data
    string divName[numDivs]={"North","West","East","South"}; //Division names
    
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    for (short i=0;i<4;i++)
    {   
        //Initialize annual sales to 0
        divsn[i].salesAn=0;
        
        //Process each divisions quarterly sales data
        cout<<divName[i]<<endl;
        //Q1
        cout<<"Enter first-quarter sales:\n";
        cin>>divsn[i].salesQ1;
        divsn[i].salesAn+=divsn[i].salesQ1; //add quarterly sales to annual sum
        //Q2
        cout<<"Enter second-quarter sales:\n";
        cin>>divsn[i].salesQ2;
        divsn[i].salesAn+=divsn[i].salesQ2; //add quarterly sales to annual sum
        //Q3
        cout<<"Enter third-quarter sales:\n";
        cin>>divsn[i].salesQ3;
        divsn[i].salesAn+=divsn[i].salesQ3; //add quarterly sales to annual sum
        //Q4
        cout<<"Enter fourth-quarter sales:\n";
        cin>>divsn[i].salesQ4;
        divsn[i].salesAn+=divsn[i].salesQ4; //add quarterly sales to annual sum
        //Calculate average quarterly sales
        divsn[i].salsAvQ=divsn[i].salesAn/4.0;
        
        //Output annual sales and average quarterly sales for each division
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout<<"Total Annual sales:$"<<divsn[i].salesAn<<endl;
        cout<<"Average Quarterly Sales:$"<<divsn[i].salsAvQ;
        if (i<3)
            cout<<endl;
    }
    
    //Display Outputs

    //Exit stage right!
    return 0;
}