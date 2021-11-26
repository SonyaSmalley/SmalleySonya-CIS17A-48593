/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 9, 2021, 4:25 PM
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
#include "Deck.h"
#include "Card.h"

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
Deck filDeck(); //Fill a deck of card with values and suits
void shuffle(Deck cards,short nShuf); //Shuffle a deck of cards
void dspDeck(Deck cards); //Display the deck of cards
short dlPlayr(Player plyr[],short nPlyr,Deck cards,short sizeH); //Deal the players
void srtHand(Player plyr,short sizeH); //Sort/Organize a player's hand
void dspHand(Player plyr,short sizeH); //Display a player's hand
short Round1(Player plyr[],short nPlyr,short sizeH,short turn); //Play 1st round - 2C first

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    short nShufl=7; //Optimal number of shuffles to mix the cards is 7
    short nPlayrs=4; //Four players for this game
    short hndSize; //The size of each player's hand (same for all)
    short twoClbs; //Indicate which player has the two of clubs
    short lead; //The winner of the last trick goes first (leads) on next round
    Deck deck; //A deck of playing cards
    Player players[nPlayrs]; //Four players
    
    //Initialize Variables
    deck=filDeck();
    hndSize=deck.nCards/nPlayrs;
    
    //Show the Fresh Deck
    cout<<"Here's a fresh deck of cards:\n";
    dspDeck(deck);
    
    //Shuffle the Deck
    shuffle(deck,nShufl);
    
    //Show the Shuffled Deck
    cout<<"\nHere's a well-shuffled deck of cards:"<<endl;
    dspDeck(deck);
    
    //Get players and deal them cards
    twoClbs=dlPlayr(players,nPlayrs,deck,hndSize);
    
    //Display the hands
    cout<<"\nThe players' hands:\n";
    for (short i=0;i<nPlayrs;i++){
        dspHand(players[i],hndSize);
    }
    
    //Play round 1 - player with 2C goes first
    lead=Round1(players,nPlayrs,hndSize,twoClbs);
    
    //Deallocate memory
    for (short i=0;i<nPlayrs;i++){
        delete []players[i].hand;
    }
    delete []deck.cards;
    
    //Exit stage right!
    return 0;
}

//***********************************************************
//Fill a deck of cards.                                     *
//Later versions will need input on the number of players.  *
//***********************************************************
Deck filDeck(){
    //Create a temporary deck of cards
    Deck tempDck;
    //Create array for suits and array for faces
    char suit[]={'H','S','C','D'}; //H=hearts,S=spades,C=clubs,D=diamonds
    char face[]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'}; //2,3,4,5,6,7,8,9,10,Jack,Queen,King,Ace
    //Fill the cards
    tempDck.nCards=52; //One 52-card deck (will vary in later versions)
    //Allocate memory to the deck of Cards and its index
    tempDck.cards=new Card[tempDck.nCards];
    for (short i=0;i<tempDck.nCards;i++){
        tempDck.cards[i].face=face[i%13]; //Each suit has one of each card face
        tempDck.cards[i].suit=suit[i/13]; //Fill the suit
        tempDck.cards[i].pos=i;
    }
    
    return tempDck;
}

//***************************************************************
//Fill a deck of cards.                                         *
//Input a string array of cards, short size of deck, and short  *
//number of shuffles.                                           *
//***************************************************************
void shuffle(Deck cards,short nShuf){
    //Shuffle cards by randomly swapping cards
    for (short shf=0;shf<nShuf;shf++){
        for (short crd=0;crd<cards.nCards;crd++){
            short indx=rand()%cards.nCards;
            Card temp=cards.cards[crd];
            cards.cards[crd]=cards.cards[indx];
            cards.cards[indx]=temp;
        }
    }
}

//********************************************************
//Display a deck of cards.                               *
//Input a string array of cards and short size of deck.  *
//********************************************************
void dspDeck(Deck cards){
    //Display the cards 1 line per suit
    for (short i=0;i<cards.nCards;i++){
        cout<<cards.cards[i].face<<cards.cards[i].suit<<" ";
        if (i%13 == 13-1)
            cout<<endl;
    }    
}

//*******************************************************************
//Assign players and deal them a hand of cards. Return short value  *
//indicating who owns the 2C card.                                  *
//Input a Player array of players, short number of players,         *
//string array of cards, and short size of deck.                    *
//*******************************************************************
short dlPlayr(Player plyr[],short nPlyr,Deck cards,short sizeH){
    //Create the player names
    string names[]={"Hal","Haley","Juan","Juanita"};
    short C2; //Who owns the 2 of Clubs card?
    
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
        plyr[i].hand=new Card[sizeH]; //Allocate memory to a hand
    }
    //Deal the cards
    short crdCnt=0; //Track the # of cards dealt
    for (short cnt=0;cnt<sizeH;cnt++){
        for (short p=0;p<nPlyr;p++){
            plyr[p].hand[cnt]=cards.cards[crdCnt];
            //if (plyr[p].hand[cnt]=="2C") //Note who owns the 2C card
                C2=1;
            crdCnt++;
        }
    }
    
    //Exit function
    return C2;
}

//********************************************************
//Sort and organize a hand of cards.                     *
//Input a Player array and short size of hand.           *
//********************************************************
void srtHand(Player plyr,short sizeH){
    for (short pos=0;pos<sizeH-1;pos++){ //Look at the cards starting w/the 1st...
        for (short i=pos+1;i<sizeH;i++){ //compare to the next card
            
        }
    }
    cout<<"srtHand TBD\n";
}

//********************************************************
//Display a hand of cards.                               *
//Input a Player array and short size of hand.           *
//********************************************************
void dspHand(Player plyr,short sizeH){
    cout<<plyr.name<<": ";
    for (short i=0;i<sizeH;i++){
        cout<<plyr.hand[i].face<<plyr.hand[i].suit<<" ";
    }
    cout<<endl;
}

//*********************************************************************
//Play first round of cards. Player with 2C goes first. Players take  *
//turns laying down a card. Hearts and QS can't be played unless      *
//player has nothing else. Must play Clubs first. Highest Club takes  *
//the trick. Returns short value indicating winner of the trick.      *
//Input a Player array of players, short number of players, short     *
//size of starting hand, and short indicating who owns 2C card.       *
//*********************************************************************
short Round1(Player plyr[],short nPlyr,short sizeH,short turn){    
    cout<<"\nRound 1 TBD\n";
    
    return turn;
}