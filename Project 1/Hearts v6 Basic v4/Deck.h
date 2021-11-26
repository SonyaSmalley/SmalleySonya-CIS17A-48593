/* 
 * File:   Deck.h
 * Author: Sonya Smalley
 * Created on November 9, 2021, 4:23 PM
 * Purpose: Create a Deck structure
 */

#ifndef DECK_H
#define DECK_H
#include "Card.h"

struct Deck{
    short nCards; //number of cards in the deck
    Card *cards; //array of Cards
};

#endif /* DECK_H */

