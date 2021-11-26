/* 
 * File:   Player.h
 * Author: Sonya Smalley
 * Created on November 8, 2021, 5:27 PM
 * Purpose: Create a Player class
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <string>
using namespace std;

struct Player{
    string name; //player name
    Card *hand; //hand of cards
    Card trick; //card played in current round
    short points; //points earned
};

#endif /* PLAYER_H */