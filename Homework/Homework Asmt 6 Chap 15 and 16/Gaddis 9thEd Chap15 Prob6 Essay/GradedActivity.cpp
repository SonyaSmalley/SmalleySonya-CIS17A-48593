/* 
 * File:   GradedActivity.cpp
 * Author: Gaddis
 * Created on November 26, 2021, 4:39 PM
 * Purpose: Replicate the GradedActivity class from Chapter 15
 */

#include "GradedActivity.h"

//Member function getLetterGrade
char GradedActivity::getLetterGrade() const{
    char letterGrade; //To hold the letter grade
    
    if (score>89)
        letterGrade='A';
    else if (score>79)
        letterGrade='B';
    else if (score>69)
        letterGrade='C';
    else if (score>59)
        letterGrade='D';
    else
        letterGrade='F';
    
    return letterGrade;
}