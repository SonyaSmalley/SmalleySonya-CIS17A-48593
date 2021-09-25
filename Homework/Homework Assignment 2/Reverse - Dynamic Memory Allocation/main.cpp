/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 24, 2021, 3:08 PM
 * Purpose: Sort and reverse a dynamic array
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &);            //Fill the array
int *sort(const int *,int);     //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int);  //Print the array

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int size,  //The size of an array
        *array=nullptr, //Dynamic array
        *aryCopy=nullptr, //Copy of the array - copy is to be sorted
        *revCopy=nullptr; //Copy of the copy array - to be reversed
    
    //Fill an integer array
    array=getData(size);
    
    //Fill an index array and sort the data lowest to highest
    aryCopy=sort(array,size);
    
    //Display copy array
    prntDat(aryCopy,size);
    
    //Reverse copy array
    revCopy=reverse(aryCopy,size);
    
    //Display reversed copy array
    cout<<endl;
    prntDat(revCopy,size);
    
    //Delete allocated memory
    delete []array;
    array=nullptr;
    delete []aryCopy;
    aryCopy=nullptr;
    delete []revCopy;
    revCopy=nullptr;
    
    //Exit stage right!
    return 0;
}


int *getData(int &n)             //Fill the array
{
    //Get user input on the size of the array
    cin>>n;
    
    //Allocate memory to a dynamic array
    int *a=new int[n];
    
    //Fill the array with user input
    for (int i=0;i<n;i++)
        cin>>*(a+i);
    
    //Exit function
    return a;
}

//Copy an array and sort the copy
int *sort(const int *a,int n)      //Sort smallest to largest
{
    //Copy the array
    int *aCopy=new int[n];
    for (int i=0;i<n;i++)
        *(aCopy+i)=*(a+i);
    
    //Sort the array
    for (int last=n-1;last>0;last--)
    {
        for (int i=0;i<last;i++) //Go through the array...
        {
            if (*(aCopy+i)>*(aCopy+i+1)) //and if the lower position is greater..
            {
                int temp=*(aCopy+i); //swap the values in the two elements
                *(aCopy+i)=*(aCopy+i+1);
                *(aCopy+i+1)=temp;
            }
        }
    }
    
    //Exit function
    return aCopy;
}


int *reverse(const int *a,int n)   //Sort in reverse order
{
    //Copy the array
    int *aCopy=new int[n];
    for (int i=0;i<n;i++)
        *(aCopy+i)=*(a+i);
    
    //Sort the array
    for (int last=n-1;last>0;last--)
    {
        for (int i=0;i<last;i++) //Go through the array...
        {
            if (*(aCopy+i)<*(aCopy+i+1))//and if the lower position is smaller...
            {
                int temp=*(aCopy+i);//swap the values in the two elements
                *(aCopy+i)=*(aCopy+i+1);
                *(aCopy+i+1)=temp;
            }
        }
    }
    
    //Exit function
    return aCopy;
}


void prntDat(const int *a,int n)   //Print the array
{
    //Print the array
    for (int i=0;i<n;i++)
    {
        cout<<a[i];
        if (i!=n-1)
            cout<<" ";
    }
}