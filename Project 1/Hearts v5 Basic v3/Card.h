/* 
 * File:   Card.h
 * Author: Sonya Smalley
 * Created on November 9, 2021, 4:37 PM
 * Purpose: Create a Card structure
 */

#ifndef CARD_H
#define CARD_H

struct Card{
    char face; //a card's face
    char suit; //a card's suit
    short order; //a card's position in a deck or hand
    short value; //a card's face value
    short point; //a card's point value
};

#endif /* CARD_H */

