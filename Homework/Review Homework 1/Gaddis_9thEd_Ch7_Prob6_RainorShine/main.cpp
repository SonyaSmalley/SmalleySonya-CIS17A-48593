/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 4, 2021, 1:40 PM
 * Purpose: Track the weather for the first 30 days in June, July and August.
 *          Save the data to a file. Create a report that displays the total
 *          number of days that were rainy, cloudy, and sunny. It also reports
 *          which month had the largest number of rainy days.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variable Data Types and Constants
    ofstream outFile;
    ifstream inFile;
    const unsigned short DAYS=30,MONTHS=3; //months: 0=June 1=July 2=August
    char sunny[11]="SSSCSSCSRC"; //weather is sunny (S), cloudy (C), or rainy (R) (mostly sunny) - idea came from Dr. Lehr
    char weather[MONTHS][DAYS]; //array to read in the season's weather
    unsigned short rainy=0; //to hold the total number of rainy days for the season
    unsigned short sun, cloud, rain; //# of days in a month that were sunny, cloudy, or rainy

    //Initialize Variables
    //output to a file what the weather was for June, July and August
    outFile.open("RainOrShine.txt");
    for (unsigned short month=0; month<MONTHS; month++)
    {
        for (unsigned short day=0; day<DAYS; day++)
            outFile<<sunny[rand()%10]; //randomly assign sunny (S), cloudy (C), and rainy (R) days
        outFile<<endl;
    }
    outFile.close();
    
    //read in to the weather array what the recorded weather was for the season
    inFile.open("RainOrShine.txt");
    for (unsigned short month=0; month<MONTHS; month++)
    {
        for (unsigned short day=0; day<DAYS; day++)
            inFile>>weather[month][day];
    }
    inFile.close();
    
    //Display Outputs
    //report how many days each month were sunny, cloudy, and rainy
    for (unsigned short month=0; month<MONTHS; month++)
    {
        sun=cloud=rain=0; //set the accumulators to 0 for each month
        for (unsigned short day=0; day<DAYS; day++)
        {
            if (weather[month][day]=='R') //how many days were rainy?
            {
                rain+=1;
                rainy+=1;
            }
            else if (weather[month][day]=='C') //how many days were cloudy?
                cloud+=1;
            else //how many days were sunny
                sun+=1;
        }
            cout<<(month==0?"June":month==1?"July":"August")
                    <<"\n-----------------------------\n";
            cout<<"Sunny Days: "<<sun<<endl;
            cout<<"Cloudy Days: "<<cloud<<endl;
            cout<<"Rainy Days: "<<rain<<endl<<endl;
    }
    
    //report the total number of rainy days for the season
    cout<<"\n\nIn total there were "<<rainy<<" rainy days in the season."<<endl;
    
    //Exit stage right!
    return 0;
}

