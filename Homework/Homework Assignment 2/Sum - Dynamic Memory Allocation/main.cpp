/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 27, 2021, 3:35 PM
 * Purpose: Given an array, create a parallel array that represents the successive
 * sum of preceding members in the array.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &); //Return the array size and the array from the inputs
int *sumAry(const int *,int);//Return the array with successive sums
void prntAry(const int *,int);//Print the array

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int *array=nullptr, //integer array
        *sumsAry=nullptr; //parallel array that represents the successive sum of preceding members in the array
    int size; //size of the array (dynamic)
    
    //Fill an integer array
    array=getData(size);
    
    //Display original array
    prntAry(array,size);
    
    //Fill an array with the successive sums of the original array
    sumsAry=sumAry(array,size);
    
    //Display parallel array of successive sums
    cout<<endl;
    prntAry(sumsAry,size);
    
    //Delete allocated memory
    delete []array;
    array=nullptr;
    delete []sumsAry;
    sumsAry=nullptr;

    //Exit stage right!
    return 0;
}

//Get array size from the user and fill an array with user input
int *getData(int &size)  //Fill the array
{
    //Get user input on the size of the array
    cin>>size;
    
    //Allocate memory to the array
    int *arr=new int[size];
    
    //Fill the array with user input
    for (int i=0;i<size;i++)
        cin>>*(arr+i);
    
    //Exit function
    return arr;
}

//Sum the digits of an array one at a time and fill another array with each sum
//The values of the first elements should be the same
int *sumAry(const int *a,int n)  //Return the array with successive sums
{
    int *sums=new int[n]; //sums array will hold the succesive sums of the original array
    
    //Fill the sums array
    for (int i=0;i<n;i++)
    {
        if (i==0) //Element zero in the sums array is equal to the value in the original array element 0
            *(sums+i)=*(a+i);
        //To get the successive sums:
        //Sum the value of the current element in the original array with the previous element in the sums array
        else 
            *(sums+i)=*(a+i)+(*(sums+i-1));
    }
    
    //Exit function
    return sums;
}

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