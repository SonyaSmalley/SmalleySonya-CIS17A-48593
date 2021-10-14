/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on October 3, 2021, 4:38 PM
 * Purpose: Store and display data on a speaker's bureau
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
struct Speaker //Data about a speaker (person)
{
    string name; //Speaker's name
    char phone[11]; //Telephone number - US phone numbers have 10 digits
    string topic; //Speaking topic
    float fee; //Fee charged by the speaker
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
//Fill an array of structures with data on speakers
Speaker *getData(short &n);

//Print out the data on the speakers
void prntDat(const Speaker *s,short n);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    

    //Declare Variable Data Types and Constants
    short nSpkr; //number of speakers in the bureau
    Speaker *speaker=nullptr; //data on the speakers in the bureau
    char choice; //yes or no for user choices
    char edit[10]; //allow the user to edit data
    short num; //number allocated to a speaker

    //Get speaker data
    speaker=getData(nSpkr);

    //Display Outputs
    prntDat(speaker,nSpkr);
    
    //Delete allocated memory
    delete []speaker;
    speaker=nullptr;

    //Exit stage right!
    return 0;
}

//Fill an array of structures with data on speakers
//Input number of speakers, return array of structures containing the data on the speakers
Speaker *getData(short &n)
{
    //Get the number of speakers whose data will be entered
    cout<<"How many speaker's are in the bureau? ";
    cin>>n;
    cout<<endl;
    
    //Allocate memory to a dynamic array of structures
    Speaker *s=new Speaker[n];
    
    //Get the data for each speaker
    for (short i=0;i<n;i++)
    {
        //Get speaker's name
        cout<<"Enter the Name for Speaker "<<i+1<<": ";
        cin.ignore();
        getline(cin,s[i].name);
        //Get speaker's phone number
        cout<<"Enter Their Phone Number: ";
        for (short j=0;j<11-1;j++)
        {
            cin>>s[i].phone[j];
        }
        s[i].phone[10]='\0';//append the phone number array with null zero
        //Get the speaker's speaking topic
        cout<<"Enter Their Speaking Topic: ";
        cin.ignore();
        getline(cin,s[i].topic);
        //Get the amount they charge for speaking
        cout<<"Enter Their Fee: ";
        cin>>s[i].fee;
        while (s[i].fee<0)
        {
            cout<<"The speaker cannot charge a negative fee. Please enter a valid fee: ";
            cin>>s[i].fee;
        };        
        cout<<endl;
    }
    
    //Exit function
    return s;
}

//Print out the data on the speakers
//Input is the dynamic array of structures holding the speaker data and the size of the array
void prntDat(const Speaker *s,short n)
{
    cout<<"\nPlease review the speaker data for errors.\n"<<endl;
    for (short i=0;i<n;i++)
    {
        cout<<"Speaker #"<<i+1<<": "<<s[i].name<<endl;
        cout<<"Phone Number: ";
        for (short j=0;j<11-1;j++)
        {
            if (j==3||j==6)
                cout<<"-";
            cout<<s[i].phone[j];
        }
        cout<<"\nSpeaking Topic: "<<s[i].topic<<endl;
        cout<<"Fee: $"<<s[i].fee<<endl<<endl;
    }
}