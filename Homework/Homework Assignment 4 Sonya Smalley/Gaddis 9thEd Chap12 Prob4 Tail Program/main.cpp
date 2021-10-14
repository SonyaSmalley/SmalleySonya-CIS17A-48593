/* 
 * File: main.cpp
 * Author: Sonya
 * Created on October 13, 2021, 2:43 PM
 * Purpose: Read and display the last 11 characters of a word file.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    string file; //To hold the file name
    char ch; //To hold a character
    ifstream inFile; //Input file

    //Initialize Variables
    //Get the input file name and open it
    cout<<"Enter the name of a file to read in: ";
    cin>>file;
    inFile.open(file);
    
    //Get the last 11 characters of the file and output them
    cout<<"Here are the last 11 characters of the file:\n";
    if (inFile){
        inFile.seekg(-11L,ios::end);
        inFile.get(ch);
        //Display Outputs
        while (inFile){
            cout<<ch;
            inFile.get(ch);
        }
        cout<<endl;
        //Close the file
        inFile.close();
    }
    else
        cout<<"The input file could not be found.\n";
    
    //Exit stage right!
    return 0;
}

