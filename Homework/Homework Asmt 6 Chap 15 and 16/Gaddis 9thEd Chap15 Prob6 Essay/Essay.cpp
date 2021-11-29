/* 
 * File:   Essay.cpp
 * Author: Sonya Smalley
 * Created on November 26, 2021, 4:49 PM
 * Purpose: Create an Essay class
 */

#include "Essay.h"
#include "GradedActivity.h"

void Essay::setScores(short g,short s,short l,short c){
    grammar=g;
    spell=s;
    length=l;
    content=c;
    
    float score; //to hold the numeric score
    
    //Calculate the score
    score=grammar+spell+length+content;
    
    //set the numeric score
    setScore(score);
}