/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on October 13, 2021, 11:55 AM
 * Purpose: Use a structure to store data on a company division. Data includes
 *          the division name, the sales quarter, and quarterly sales. Data to
 *          be input from a binary file. The data for each quarter for each division
 *          should be written into the structure. Output for each division the
 *          following: quarterly sales, yearly sales, average quarterly sales.
 *          For the entire corporation, output yearly sales and the highest and
 *          lowest quarters for the corporation.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries
#include "DivSales.h"   

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    const short NUMDIVS=4; //Number of divisions 
    DivSales divsn[NUMDIVS]; //Division sales data
    fstream binFile;
    
    //Initialize Variables
    //Open a file to write data to
    binFile.open("div_sales.bin",ios::in|ios::binary);
    
    //Process or map Inputs to Outputs
    for (short i=0;i<NUMDIVS;i++)
    {
        //Read in the data from the file
        binFile.read(reinterpret_cast<char *>(&divsn),sizeof(divsn)); //the book says this will work!!!!!
        
        //Process each divisions quarterly sales data
        cout<<"Division "<<divsn[i].name<<endl;
        //Q1
        cout<<"First-quarter sales: "<<divsn[i].salesQ1<<endl;
        //Q2
        cout<<"First-quarter sales: "<<divsn[i].salesQ2<<endl;
        //Q3
        cout<<"First-quarter sales: "<<divsn[i].salesQ3<<endl;
        //Q4
        cout<<"First-quarter sales: "<<divsn[i].salesQ4<<endl;
    }
    //Close the file
    binFile.close();
    
    //Display Outputs
    
    
    //Exit stage right!
    return 0;
}

