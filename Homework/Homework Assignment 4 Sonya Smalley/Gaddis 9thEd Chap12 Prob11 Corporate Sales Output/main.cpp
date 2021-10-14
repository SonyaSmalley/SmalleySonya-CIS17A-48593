/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on October 13, 2021, 11:55 AM
 * Purpose: Use a structure to store data on a company division. Data includes
 *          the division name, the sales quarter, and quarterly sales. Data to
 *          be input by the user. The data for each quarter for each division
 *          should be written into a file.
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
void wrtText(fstream &file,DivSales div); //Writes data from a structure to a text file

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    const short NUMDIVS=4; //Number of divisions 
    DivSales divsn[NUMDIVS]; //Division sales data
    fstream binFile,txtFile;
    
    //Initialize Variables
    //Open files to write data to
    binFile.open("div_sales.bin",ios::out|ios::binary);
    txtFile.open("div_sales.txt",ios::out);
    
    //Process or map Inputs to Outputs
    for (short i=0;i<NUMDIVS;i++)
    {          
        //Process each divisions quarterly sales data
        cout<<"Enter the division's name: ";
        getline(cin,divsn[i].name);
        //Q1
        cout<<"Enter first-quarter sales: ";
        cin>>divsn[i].salesQ1;
        //Q2
        cout<<"Enter second-quarter sales: ";
        cin>>divsn[i].salesQ2;
        //Q3
        cout<<"Enter third-quarter sales: ";
        cin>>divsn[i].salesQ3;
        //Q4
        cout<<"Enter fourth-quarter sales: ";
        cin>>divsn[i].salesQ4;
        cout<<endl;
        
        //Write the contents of the structure to a binary file
        binFile.write(reinterpret_cast<char *>(&divsn),sizeof(divsn)); //the book says this works!!
        //Write the contents of the structure to a text file (to make sure this thing is mostly working)
        wrtText(txtFile,divsn[i]);
        cin.ignore();
    }
    
    //Close the files
    binFile.close();
    txtFile.close();
    
    //Display Outputs
    
    
    //Exit stage right!
    return 0;
}

//Writes data from a structure to a text file
void wrtText(fstream &file,DivSales div){
    file<<"Division "<<div.name<<endl;
    //Q1
    file<<"First-quarter sales: "<<div.salesQ1<<endl;
    //Q2
    file<<"First-quarter sales: "<<div.salesQ2<<endl;
    //Q3
    file<<"First-quarter sales: "<<div.salesQ3<<endl;
    //Q4
    file<<"First-quarter sales: "<<div.salesQ4<<endl;
    file<<endl;
} 