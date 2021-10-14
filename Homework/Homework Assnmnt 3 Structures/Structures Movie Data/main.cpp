/* 
 * File: main
 * Author: Sonya Smalley
 * Created on September 29, 2021, 9:42 PM
 * Purpose: Store and display movie data
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
struct MoviDat
{
    string title, //Title
           dirctr; //Director
    int year, //Year released
        length; //Running time in minutes
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void prntDat(MoviDat); //print the movie data

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    int num; //number of movies
    MoviDat *movies=nullptr; //dynamic array of movie data
    
    //Initialize Variables
    cout<<"This program reviews structures\n";
    cout<<"Input how many movies, the Title of the Movie, Director, "
        <<"Year Released, and the Running Time in (minutes).\n";
    cin>>num;
    movies=new MoviDat [num];
    
    //Get the movie data
    for (int i=0;i<num;i++)
    {
        cin.ignore();
        getline(cin,movies[i].title);
        getline(cin,movies[i].dirctr);
        cin>>movies[i].year>>movies[i].length;
    }
    
    //Display the movie data
    for (int i=0;i<num;i++)
        prntDat(movies[i]);

    //Deallocate memory
    delete []movies;
    movies=nullptr;
    
    //Exit stage right!
    return 0;
}

void prntDat(MoviDat m) //print the movie data
{
    cout<<endl<<left<<setw(11)
        <<"Title:  "<<m.title<<endl;
    cout<<left<<setw(11)
        <<"Director:  "<<m.dirctr<<endl;
    cout<<left<<setw(11)
        <<"Year:  "<<m.year<<endl;
    cout<<left<<setw(11)
        <<"Length:  "<<m.length<<endl;
    
}