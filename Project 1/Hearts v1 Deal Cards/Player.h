/* 
 * File:   Player.h
 * Author: Sonya Smalley
 * Created on November 8, 2021, 5:27 PM
 * Purpose: Create a Player class
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

struct Player{
    string name; //player name
    string *hand; //hand of cards
};

#endif /* PLAYER_H */