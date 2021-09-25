/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 24, 2021, 4:53 PM
 * Purpose: Create a 2-D array 1 row and 1 column larger than the array to copy with 0's
 * in the 1st row and column but filled with the other rows and columns using the original array.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int **array=nullptr, //original integer array
        **augArr=nullptr; //augmented array is filled with a 0 in the first element, and the rest is a shifted copy of the original
    int rows,cols; //size of the rows and columns of the array (dynamic)
    
    //Fill an integer array
    array=getData(rows,cols);
    
    //Display original array
    printDat(array,rows,cols);
    
    //Fill the augmented array (first row and column with 0s and the rest is a copy of the original array)
    augArr=augment(array,rows,cols);
    
    //Display augmented array
    
    printDat(augArr,rows+1,cols+1);
    
    //Deallocate memory
    destroy(array,rows);
    destroy(augArr,rows);
    
    //Exit stage right!
    return 0;
}

//Get user input for number of rows and columns and fill 2d array with user input
int **getData(int &row,int &col)//Get the Matrix Data
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
void printDat(const int* const *a,int row,int col)//Print the 2-D Array
{
    for (int r=0;r<row;r++)
    {
        for (int c=0;c<col;c++)
        {
            cout<<a[r][c];
            if (c!=col-1)
                cout<<" ";
        }
        //I cannot use the "correct" code for the endl (code is commented out below)
        //The code below causes row to be decreased. If I try to correct for that, things just get weirder
        //if (r<(row-1))
            //cout<<endl;
        cout<<endl;
    }
}

//Make a 2d dynamic array that is one row and one column bigger than another array
//Put 0 into the first row and columnt ofthe augmented array, then fill the rest with the original array
int **augment(const int * const *a,int row,int col)//Augment the original array
{
    //Allocate memory to the augment array row pointers
    int **aug=new int*[row+1];
    
    //Allocate memory to the column width for each row
    for (int r=0;r<row+1;r++)
        aug[r]=new int[col+1];
    
    //Fill the first row of the augmented array with 0s
    for (int c=0;c<col+1;c++)
        aug[0][c]=0;
        
    //Fill the first column of the augmented array with 0s
    for (int r=0;r<row+1;r++)
        aug[r][0]=0;
    
    //Copy the original array into the augmented array
    for (int r=1;r<row+1;r++)
    {
        for (int c=1;c<col+1;c++)
        {
            aug[r][c]=a[r-1][c-1];
        }
    }
    
    //Exit function
    return aug;
}

//Function input is the array and rows.
//Function will deallocate the memory allocated to the array.
void destroy(int **a,int row)//Destroy the Matrix, i.e., reallocate memory
{
    //Delete allocated memory one row at a time
    for (int i=0;i<row;i++)
    {
        delete []a[row];
        a[row]=nullptr;
    }
    
    //Delete the row pointers
    delete []a;
    a=nullptr;
}