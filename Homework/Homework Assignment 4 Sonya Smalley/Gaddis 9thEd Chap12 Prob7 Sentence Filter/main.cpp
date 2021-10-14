/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on October 13, 2021, 9:25 AM
 * Purpose: Read in a text file that contains sentences that end with a period.
 *          The program will change all the letters to lowercase except the
 *          first letter of each sentence, which will be made uppercase. The
 *          revised contents will be stored in a second file.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    string file; //To hold the file names
    char ch; //To hold a character
    ifstream inFile; //Input file
    ofstream outFile; //Output file

    //Initialize Variables
    //Get the input file name and open it
    cout<<"Enter the name of a file to read in: ";
    cin>>file;
    inFile.open(file);
    
    //Get the output file name and open it
    cout<<"Enter the name of a file to output to: ";
    cin>>file;
    outFile.open(file);
    
    //Get the first letter of the first sentence and capitalize it (because this should be a file of sentences)
    if (inFile){
        inFile.get(ch);
        outFile.put(toupper(ch));
        inFile.get(ch);

        //Display Outputs
        while (inFile){
            if (ch=='.'){
                outFile.put(ch);
                inFile.get(ch);
                while (ch==' '&&inFile){
                    outFile.put(ch);
                    inFile.get(ch);
                }
                if (ch!='.')
                    outFile.put(toupper(ch));
            }
            else{
                outFile.put(tolower(ch));
            }
            inFile.get(ch);
        }

        //Close the files
        inFile.close();
        outFile.close();
        cout<<"File conversion done.\n";
    }
    else
        cout<<"The input file could not be found.\n";
    
    //Exit stage right!
    return 0;
}

