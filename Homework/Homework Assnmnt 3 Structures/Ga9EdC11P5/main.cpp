/* 
 * File: main
 * Author: Sonya Smalley
 * Created on September 29, 2021, 7:47 PM
 * Purpose: Weather program: User enters weather data for a year. Calculates
            average temp, average mothly rainfall, total rainfall, highest and
            lowest temps, and the average of all monthly average temperatures.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct Weather //Weather data
{
    float rain; //Total rainfall in inches
    int hiTemp, //High Temperature - Degrees Fahrenheit
        lowTemp; //Low Temperature -Degrees Fahrenheit
    float avgTemp; //Average Temperature - Degrees Fahrenheit
};

enum Months
{
    JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE,
    JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Weather weather[DECEMBER]; //Weather array (monthly)
    float avgRain=0.0, avgTemp=0.0; //Average of the monthly average rain and temp
    int minTemp, maxTemp; //Min and max temperatures for the year
    
    //Get the monthly weather data
    for (Months month=JANUARY;month<=JUNE;month=static_cast<Months>(month+1))
    {
        //Get the total rainfall in inches, and highest temp and lowest temp in Fahrenheit
        cout<<"Enter the total rainfall for the month:\n";
        cin>>weather[month].rain;
        cout<<"Enter the high temp:\n";
        cin>>weather[month].hiTemp;
        cout<<"Enter the low temp:\n";
        cin>>weather[month].lowTemp;
    }
    
    //Calculate average temps and rainfall as well as high and low temps
    minTemp=weather[0].lowTemp; //initialize minTemp to the lowTemp of the first element in the weather array
    maxTemp=weather[0].hiTemp; //initialize maxTemp to the hiTemp of the first element in the weather array
    for (Months month=JANUARY;month<=JUNE;month=static_cast<Months>(month+1))
    {
        //Calculate the average temperature for the month
        weather[month].avgTemp=(weather[month].hiTemp+weather[month].lowTemp)/2.0;
        //Sum the rainfall and temperature from each month to get the totals for the year
        avgRain+=weather[month].rain; //Sum the rain
        avgTemp+=weather[month].avgTemp;
        //Track the highest temperature for the year and what month it was in
        if (weather[month].hiTemp>=maxTemp)
        {
            maxTemp=weather[month].hiTemp;
        }
        //Track the lowest temperature for the year and what month it was i
        if (weather[month].lowTemp<=minTemp)
        {
            minTemp=weather[month].lowTemp;
        }
    }
    
    //Display Outputs
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Average monthly rainfall:"<<(avgRain/6.0)<<endl;
    cout<<"High Temp:"<<maxTemp<<endl;
    cout<<"Low Temp:"<<minTemp<<endl;
    cout<<setprecision(1)<<"Average Temp:"<<(avgTemp/6.0);

    //Exit stage right!
    return 0;
}