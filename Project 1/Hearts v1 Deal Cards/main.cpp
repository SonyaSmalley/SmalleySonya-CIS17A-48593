/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 8, 2021, 3:58 PM
 * Purpose: Shuffle 52 cards and deal them all to 4 players (the number of cards
 *          and players will vary in later versions).
 *          Using Dr. Lehr's example from CIS-5 as my basis. I like shuffling rather than
 *          a zillion if statements after each card is randomly assigned to someone.
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

//User Libraries
#include "Player.h"

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void filDeck(string cards[],short nCrd); //Fill a deck of card with values and suits
void shuffle(string cards[],short nCrd,short nShuf); //Shuffle a deck of cards
void dspDeck(string cards[],short nCrd); //Display the deck of cards
short dlPlayr(Player plyr[],short nPlyr,string cards[],short nCrd); //Deal the players
void dspHand(Player plyr,short hndN); //Display a player's hand

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    short nCards=52; //One 52-card deck (will vary in later versions, so not a constant)
    short nShufl=7; //Optimal number of shuffles to mix the cards is 7
    short nPlayrs=4; //Four players for this game
    short hndSize; //The size of each player's hand (same for all)
    string deck[nCards]; //A full deck of 52 playing cards, Ace thru King
    Player players[nPlayrs]; //Four players
    
    //Initialize Variables
    filDeck(deck,nCards);
    
    //Show the Fresh Deck
    cout<<"Here's a fresh deck of cards:\n";
    dspDeck(deck,nCards);
    
    //Shuffle the Deck
    shuffle(deck,nCards,nShufl);
    
    //Show the Shuffled Deck
    cout<<"\nHere's a well-shuffled deck of cards:"<<endl;
    dspDeck(deck,nCards);
    
    //Get players and deal them cards
    hndSize=dlPlayr(players,nPlayrs,deck,nCards);
    
    //Display the hands
    cout<<"\nThe players' hands:\n";
    for (short i=0;i<nPlayrs;i++){
        dspHand(players[i],hndSize);
    }
    
    //Deallocate memory
    for (short i=0;i<nPlayrs;i++){
        delete []players[i].hand;
    }
    
    //Exit stage right!
    return 0;
}

//********************************************************
//Fill a deck of cards.                                  *
//Input a string array of cards and short size of deck.  *
//********************************************************
void filDeck(string cards[],short nCrd){
    //Create array for suits and array for faces
    char suit[]={'H','S','C','D'}; //H=hearts,S=spades,C=clubs,D=diamonds
    char face[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'}; //Ace,2,3,4,5,6,7,8,9,10,Jack,Queen,King
    //Fill the cards
    for (short i=0;i<nCrd;i++){
        cards[i]=face[i%13]; //Each suit has one of each card face
        cards[i]+=suit[i/13]; //Fill the suit
    }    
}

//***************************************************************
//Fill a deck of cards.                                         *
//Input a string array of cards, short size of deck, and short  *
//number of shuffles.                                           *
//***************************************************************
void shuffle(string cards[],short nCrd,short nShuf){
    //Shuffle cards by randomly swapping cards
    for (short shf=0;shf<nShuf;shf++){
        for (short crd=0;crd<nCrd;crd++){
            short indx=rand()%nCrd;
            string temp=cards[crd];
            cards[crd]=cards[indx];
            cards[indx]=temp;
        }
    }
}

//********************************************************
//Display a deck of cards.                               *
//Input a string array of cards and short size of deck.  *
//********************************************************
void dspDeck(string cards[],short nCrd){
    //Display the cards 1 line per suit
    for (short i=0;i<nCrd;i++){
        cout<<cards[i]<<" ";
        if (i%13 == 13-1)
            cout<<endl;
    }    
}

//*******************************************************************
//Assign players and deal them a hand of cards. Return hand size.   *
//Input a Player array of players, short number of players,         *
//string array of cards, and short size of deck.                    *
//*******************************************************************
short dlPlayr(Player plyr[],short nPlyr,string cards[],short nCrd){
    //Create the player names
    string names[]={"Hal","Haley","Juan","Juanita"};
    short sizeH=nCrd/nPlyr; //size of a player's hand
    
    //Fill the Player array with the players' names and display their names
    cout<<endl<<"The players: ";
    for (short i=0;i<nPlyr;i++){
        plyr[i].name=names[i];
        cout<<plyr[i].name<<" ";
    }
    cout<<endl;
    
    //Allocate memory for the players' hands & deal them all the cards
    //All players get the same number of cards per the rules - decks will be 
    //adjusted in later versions
    for (short i=0;i<nPlyr;i++){
        plyr[i].hand=new string[sizeH]; //Allocate memory to a hand
    }
    short crdCnt=0;
    for (short cnt=0;cnt<sizeH;cnt++){
        for (short p=0;p<nPlyr;p++){
            plyr[p].hand[cnt]=cards[crdCnt];
            crdCnt++;
        }
    }
    
    //Exit function
    return sizeH;
}

//********************************************************
//Display a hand of cards.                               *
//Input a Player array and short size of hand.           *
//********************************************************
void dspHand(Player plyr,short hndN){
    cout<<plyr.name<<": ";
    for (short i=0;i<hndN;i++){
        cout<<plyr.hand[i]<<" ";
    }
    cout<<endl;
}