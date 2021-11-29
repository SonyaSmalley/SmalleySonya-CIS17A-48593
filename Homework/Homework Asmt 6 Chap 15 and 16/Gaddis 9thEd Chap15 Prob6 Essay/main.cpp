/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 26, 2021, 4:37 PM
 * Purpose: 
 */

//System Libraries
#include <iostream>
using namespace std;
#include "Essay.h"
#include "GradedActivity.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    Essay essay1(30,20,20,30),
            essay2(22,19,18,25);
    
    //Display Outputs
    cout<<"Here are the scores for two essays:\n";
    
    cout<<"\nEssay 1:"<<"\nGrammar: "<<essay1.getGram()
        <<"\nSpelling: "<<essay1.getSpell()
        <<"\nLength: "<<essay1.getLen()
        <<"\nContent: "<<essay1.getCntnt()
        <<"\nTotal: "<<essay1.getScore()<<" "<<essay1.getLetterGrade()<<endl;
    
    cout<<"Here are the scores for two essays:\n";
    cout<<"\nEssay 2:"<<"\nGrammar: "<<essay2.getGram()
        <<"\nSpelling: "<<essay2.getSpell()
        <<"\nLength: "<<essay2.getLen()
        <<"\nContent: "<<essay2.getCntnt()
        <<"\nTotal: "<<essay2.getScore()<<" "<<essay2.getLetterGrade()<<endl;
    
    //Exit stage right!
    return 0;
}