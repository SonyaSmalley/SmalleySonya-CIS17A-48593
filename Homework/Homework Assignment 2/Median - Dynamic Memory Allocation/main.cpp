/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 24, 2021, 11:39 PM
 * Purpose: Calculate the Median
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *,int);     //Print the median Array

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int size, *array=nullptr; //an integer array and its size
    float *medArry=nullptr; //a float array to hold the numbers in the integer array, its median and and its size (reverse order)
    
    //Fill an integer array
    array=getData(size);
    
    //Fill the median array with the float array size, median of the integer array, and the integer array data
    medArry=median(array,size);
    
    //Display Outputs
    //Print the integer array
    prntDat(array,size);
    //Print the median array
    prntMed(medArry,size);
    
    //Delete allocated memory
    delete []array;
    delete []medArry;
    
    //Exit stage right!
    return 0;
}

//Return the array size and the array
int *getData(int &n)
{
    //get the array size
    cin>>n;
    
    //create a dynamic array the size of n
    int *a=new int[n];
    
    //Fill the array with user input
    for (int i=0;i<n;i++)
    {
        cin>>*(a+i);
    }
    
    //Exit function
    return a;
}

//Print the integer array
void prntDat(int *a,int n){
    for (int i=0;i<n;i++)
    {
        cout<<*(a+i);
        if (i<n-1)
            cout<<" ";
    }
    cout<<endl;
}

//Fill the median Array with the Float array size, the median, and the integer array data
float *median(int *a,int n)
{   
    //Create a dynamic array the size of n +2
    float *med=new float[n+2];

    //Fill the first two elements of the array
    *med=n+2;//The median array is 2 elements larger than than the integer array
    *(med+1)=n/2.0+0.5; //The median position is in the center of a sorted array
    
    //Fill the rest of the median array with the integer array
    for (int i=2;i<n+2;i++)
        *(med+i)=*(a+(i-2));
    
    //Exit function
    return med;
}

//I could not figure out how to do this without having the size of the array
//I will try to ask about how to do this in class
void prntMed(float *med, int n)     //Print the median Array
{
    //Print the first element (the size) of the array
    cout<<*med;
    //Print the rest of the median array
    for (int i=1;i<n+2;i++)
    {
        cout<<setprecision(2)<<fixed<<showpoint;
        cout<<" "<<*(med+i);
    }
}