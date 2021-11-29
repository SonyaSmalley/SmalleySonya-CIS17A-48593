/* 
 * File:   Essay.h
 * Author: Sonya Smalley
 * Created on November 26, 2021, 4:49 PM
 * Purpose: Create an Essay class
 */

#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"

class Essay : public GradedActivity {
private:
    short grammar; //points for grammar (30 pts)
    short spell; //points for spelling (20 pts)
    short length; //points for meeting length requirement (20 pts)
    short content; //points for content (30 pts)
public:
    //Default constructor
    Essay(){
        grammar=spell=length=content=0;
    }
    //Constructor
    Essay(short g,short s,short l,short c){
        setScores(g,s,l,c);
    }
    //Mutator function
    void setScores(short g,short s,short l,short c);
    //Accessor functions
    short getGram() const{
        return grammar;
    }
    short getSpell() const{
        return spell;
    }
    short getLen() const{
        return length;
    }
    short getCntnt() const{
        return content;
    }
};

#endif /* ESSAY_H */