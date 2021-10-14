/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on October 13, 2021, 10:56 AM
 * Purpose: Write the contents of an integer array into a file. Then read the
 *          contents of the file into another array.
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void aToFile(fstream &file,int *a,int n); //Write an array into a binary file
void fileToA(fstream &file,int *a,int n); //Read a binary file into an array

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    const int SIZE=5; //size of an array of integers
    int nums1[SIZE],nums2[SIZE]; //arrays of random integers
    fstream file; //file to hold data from an array
    
    //Initialize Variables
    //Assign random numbers to the first array
    for (int i=0;i<SIZE;i++){
        nums1[i]=10+rand()%91; //assign random numbers between 10 and 100
    }
        
    //Display Outputs
    //Display the contents of the original array
    cout<<"Here is the original array: ";
    for (int i=0;i<SIZE;i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    
    //Write the array contents into a file
    aToFile(file,nums1,SIZE);
    
    //Read in the file contents into a new array
    fileToA(file,nums2,SIZE);
    
    //Show the contents of the second array
    cout<<"Here is the second array: ";
    for (int i=0;i<SIZE;i++){
        cout<<nums2[i]<<" ";
    }
    cout<<endl;
    
    //Exit stage right!
    return 0;
}

//Write the contents of an integer array into a binary file
//Input the file, a pointer to the array, and the size of the array
void aToFile(fstream &file,int *a,int n){
    //Open the file for output
    file.open("data.bin",ios::out|ios::binary);
    
    //Test for an error opening the file
    if (!file){
        cout<<"Error opening file\n";
    }
    else{
        //Write the contents of the integer array into the file
        file.write(reinterpret_cast<char *>(a),sizeof(int)*n);
    }
        file.close();
}

//Input the contents of a binary file into an integer array
//Input the file, a pointer to the array, and the size of the array
void fileToA(fstream &file,int *a,int n){
    //Open the file for input
    file.open("data.bin",ios::in|ios::binary);
    
    //Test for an error opening the file
    if (!file){
        cout<<"Error opening file\n";
    }
    else{
        //Read the contents of the file into an integer array
        file.read(reinterpret_cast<char *>(a),sizeof(int)*n);
    }
    file.close();
}