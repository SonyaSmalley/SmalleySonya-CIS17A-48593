/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 24, 2021, 4:15 PM
 * Purpose: Total the elements in a 2d array
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int **array=nullptr; //2d integer array
    int rows, //number of rows in the 2d array
        cols, //number of columns in the 2d array
        total; //sum of the values in the 2d array
    
    //Initialize Variables
    array=getData(rows,cols);
    
    //Display array
    prntDat(array,rows,cols);
    
    //Sum the array and display the Sum
    total=sum(array,rows,cols);
    cout<<total;
       
    //Deallocate memory
    destroy(array,rows,cols);
    
    //Exit stage right!
    return 0;
}

//Get user input for number of rows and columns and fill 2d array with user input
int **getData(int &row,int &col)        //Return the 2-D array and its size.
{
    //Get row and col size from the user
    cin>>row>>col;
    
    //Allocate memory to the row pointers
    int **a=new int*[row];
    
    //Allocate memory to the column width for each row
    for (int r=0;r<row;r++)
        a[r]=new int[col];
    
    //Fill the array with user input
    for (int r=0;r<row;r++)
    {
        for (int c=0;c<col;c++)
        {
            cin>>a[r][c];
        }
    }
    
    //Exit function
    return a;
}

//Print a 2d dynamic array
void prntDat(const int* const *a,int row,int col)//Print the 2-D Array
{
    for (int r=0;r<row;r++)
    {
        for (int c=0;c<col;c++)
        {
            cout<<a[r][c];
            if (c!=col-1)
                cout<<" ";
        }
        cout<<endl;
    }
}

//Deallocate the memory in a 2d dynamic array one row at a time
//I don't know why columns are in here
void destroy(int **a,int row,int col)       //Deallocate memory
{
    //Delete allocated memory one row at a time
    for (int i=0;i<row;i++)
    {
        delete []a[i];
        a[i]=nullptr;
    }
    
    //Delete the row pointers
    delete []a;
    a=nullptr;
}

//Sum the values in a 2d dynamic array
int sum(const int * const *a, int row,int col)    //Return the Sum
{
    int total=0; //sum of values in the integer array
    
    //Sum the values of the array
    for (int r=0;r<row;r++)
    {
        for (int c=0;c<col;c++)
            total+=a[r][c];
    }
    
    //Exit function
    return total;
}