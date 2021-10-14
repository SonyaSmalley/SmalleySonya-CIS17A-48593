/* 
 * File: main
 * Author: Sonya Smalley
 * Created on September 29, 2021, 6:39 PM
 * Purpose: Weather program: User enters weather data for a year. Calculates
            average temp, average mothly rainfall, total rainfall, highest and
            lowest temps, and the average of all monthly average temperatures.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries
struct Weather //Weather data
{
    string month; //month
    int rain, //Total rainfall in inches
        hiTemp, //High Temperature - Degrees Fahrenheit
        lowTemp, //Low Temperature -Degrees Fahrenheit
        avgTemp; //Average Temperature - Degrees Fahrenheit
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int MONTHS=12; //12 months in a year
    Weather weather[MONTHS]; //Weather array (monthly)
    float avgRain=0.0; //Average of the monthly average rain
    int minTemp, maxTemp; //Min and max temperatures for the year
    float avgTemp=0.0; //Average of the monthly average temperature
    string minMnth, maxMnth; //The months with the lowest and highest temperatures, respectively
    
    //Get the monthly weather data
    for (int i=0;i<MONTHS;i++)
    {
        //Get the month name
        cin>>weather[i].month;
        //Get the total rainfall in inches, and highest temp, lowest temp, and average temp in Fahrenheit
        cin>>weather[i].rain>>weather[i].lowTemp>>weather[i].hiTemp;
    }
    
    //Calculate average temps and rainfall as well as high and low temps
    minTemp=weather[0].lowTemp; //initialize minTemp to the lowTemp of the first element in the weather array
    maxTemp=weather[0].hiTemp; //initialize maxTemp to the hiTemp of the first element in the weather array
    for (int i=0;i<MONTHS;i++)
    {
        //Calculate the average temperature for the month
        weather[i].avgTemp=(weather[i].hiTemp+weather[i].lowTemp)/2;
        //Sum the rainfall and temperature from each month to get the totals for the year
        avgRain+=weather[i].rain; //Sum the rain
        avgTemp+=weather[i].avgTemp;
        //Track the highest temperature for the year and what month it was in
        if (weather[i].hiTemp>=maxTemp)
        {
            maxTemp=weather[i].hiTemp;
            maxMnth=weather[i].month;
        }
        //Track the lowest temperature for the year and what month it was i
        if (weather[i].lowTemp<=minTemp)
        {
            minTemp=weather[i].lowTemp;
            minMnth=weather[i].month;
        }
    }
    
    //Display Outputs
    cout<<fixed<<showpoint<<setprecision(1);
    cout<<"Average Rainfall "<<(avgRain/MONTHS)<<" inches/month\n";
    cout<<"Lowest  Temperature "<<minMnth<<"  "<<minTemp<<" Degrees Fahrenheit\n";
    cout<<"Highest Temperature "<<maxMnth<<"  "<<maxTemp<<" Degrees Fahrenheit\n";
    cout<<"Average Temperature for the year "<<static_cast<int>(round(avgTemp/MONTHS))<<" Degrees Fahrenheit\n";

    //Exit stage right!
    return 0;
}