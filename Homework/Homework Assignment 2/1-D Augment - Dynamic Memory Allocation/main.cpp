/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 24, 2021, 4:45 PM
 * Purpose: Augment a 1-D array by 1 Element, place 0 in the first element and copy the rest from the original shifted by 1 index
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int *array=nullptr, //original integer array
        *augArr=nullptr; //augmented array is filled with a 0 in the first element, and the rest is a shifted copy of the original
    int size; //size of the array (dynamic)

    //Fill an integer array
    array=getData(size);
    
    //Fill the augmented array
    augArr=augment(array,size);
    
    //Display origianl array
    prntAry(array,size);
    
    //Display augmented array
    cout<<endl;
    prntAry(augArr,size+1);
    
    //Delete allocated memory
    delete []array;
    array=nullptr;
    delete []augArr;
    augArr=nullptr;
    
    //Exit stage right!
    return 0;
}


//Get size from the user and fill an array with user input
int *getData(int &n)  //Fill the array
{
    //Get user input on the size of the array
    cin>>n;
    
    //Allocate memory to the array
    int *a=new int[n];
    
    //Fill the array with user input
    for (int i=0;i<n;i++)
        cin>>*(a+i);
    
    //Exit function
    return a;
}

//Make a 2d dynamic array that is one element bigger than another
//Put 0 into the augmented array then fill the rest with the original array
int *augment(const int *a,int n)//Augment and copy the original array
{
    //Allocate memory to the augment array
    int *aug=new int[n+1];
    
    //The first element of the augmented array holds 0
    *aug=0;
    
    //Copy the original array into the rest of the augmented array
    for (int i=0;i<n;i++)
        *(aug+i+1)=*(a+i);
    
    //Exit function
    return aug;
}

//Print a 2d array
void prntAry(const int *a,int n)   //Print the array
{
    //Print the array
    for (int i=0;i<n;i++)
    {
        cout<<a[i];
        if (i!=n-1)
            cout<<" ";
    }
}