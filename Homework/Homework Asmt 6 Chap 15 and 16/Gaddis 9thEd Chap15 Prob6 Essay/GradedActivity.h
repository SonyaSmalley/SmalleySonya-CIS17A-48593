/* 
 * File:   GradedActivity.h
 * Author: Gaddis
 * Created on November 26, 2021, 4:39 PM
 * Purpose: Replicate the GradedActivity class from Chapter 15
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity {
private:
    float score; //To hold the numeric score
public:
    //Default constructor
    GradedActivity(){
        score=0.0f;
    }
    //Constructor
    GradedActivity(float s){
        score=s;
    }
    //Mutator Function
    void setScore(float s){
        score=s;
    }
    float getScore() const{
        return score;
    }
    char getLetterGrade() const;
};

#endif /* GRADEDACTIVITY_H */