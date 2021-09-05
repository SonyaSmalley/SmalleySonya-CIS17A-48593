/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 4, 2021, 2:59 PM
 * Purpose: Use binary search to search an array of strings
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void selSort(string array[],short size); //sort the string array
void swap(string &a, string &b); //swap two strings
short binSrch(string array[],short size,string find); //search an array for a string
void print(const string array[],int size); //print a string array

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    const short NUMNAME=20;
    string names[NUMNAME]={"Collins, Bill", "Smith, Bart", "Allen, Jim",
                            "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                            "Taylor, Terri", "Johnson, Jill",
                            "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                            "James, Jean", "Weaver, Jim", "Pore, Bob",
                            "Rutherford, Greg", "Javens, Renee",
                            "Harrison, Rose", "Setzer, Cathy",
                            "Pike, Gordon", "Holland, Beth"};
    short locale; //the position of the name in the array
    string search;

    //Initialize Variables
    //sort the array of names
    selSort(names,NUMNAME);
    //show the list of names
    print(names,NUMNAME);
    
    //ask for a name to look for
    cout<<"Search for a name. Enter last name, first name: ";
    getline(cin,search);

    //Display Outputs 
    //search for the requested name in the array of names
    locale=binSrch(names,NUMNAME,search);
    
    //let them know if it was found
    if (locale<0)
        cout<<"That name is not in the array\n";
    else
        cout<<"That name was found in element "<<locale<<" in the array\n";

    //Exit stage right!
    return 0;
}

//Sort an array of strings in ascending order, include the size
void selSort(string array[],short size)
{
    short minIndex; //lowest index point
    string minName; //smallest name
    
    for (unsigned short start=0;start<(size-1);start++)
    {
        minIndex=start;
        minName=array[start];
        for (unsigned short index=start+1;index<size;index++)
        {
            if (array[index]<minName)
            {
                minName=array[index];
                minIndex=index;
            }
        }
        swap(array[minIndex],array[start]);
    }
}

//Swap two string values
void swap(string &a, string &b)
{
    string temp=a;
    a=b;
    b=temp;
}

//Enter a string array, the size of the array (short) and the thing to be found
//Returns the location of the element where it was found or -1 if it was not
short binSrch(string array[],short size,string find)
{
    short first=0, //first array element
          last=size-1, //last array element
          middle; //middle of the search
    
    //search the array
    do
    {
        middle=(first+last)/2; //find the midlle of the array
        if (array[middle]==find) //if it's found in the middle
            return middle;
        else if (array[middle]>find) //if it's in the lower half
            last=middle-1;
        else //if it's in the upper half
            first=middle+1;
    }
    while (first<=last);
          
    return -1;
}
//Function to print a string array
void print(const string array[],int size)
{
    cout<<"List of Available Names:\n\n";
    for (short i=0;i<size;i++)
        cout<<array[i]<<endl;
    cout<<endl;
}