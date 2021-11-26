/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 9, 2021, 6:15 PM
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
void dspDeck(const Deck cards); //Display the deck of cards
short dlPlayr(Player plyr[],short nPlyr,Deck cards,short sizeH); //Deal the players
void srtHand(Player plyr,short sizeH); //Sort/Organize a player's hand by suit & face
void dspHand(const Player plyr,short sizeH); //Display a player's hand
short Round1(Player plyr[],short nPlyr,short sizeH,short turn); //Play 1st round - 2C first
short srchHnd(Card hand[],short sizeH,const Card lead,
        short rnd); //Search for a card in a hand
void srtFace(Card hand[],short sizeH); //Sort/Organize a player's hand by face
void dspCard(const Player plyr); //Display a card
void nullCrd(Card &card); //Set a card to be an unreal card

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
    short round=0, //Track which round it is
          maxRnd; //The number of rounds to play to deplete player hands
    Deck deck; //A deck of playing cards
    Player players[nPlayrs]; //Four players
    
    //Initialize Variables
    deck=filDeck();
    hndSize=deck.nCards/nPlayrs;
    
    //Show the Fresh Deck
    cout<<"Here's a fresh deck of cards:\n";
    dspDeck(deck);
    maxRnd=deck.nCards/nPlayrs;
    
    //Shuffle the Deck
    shuffle(deck,nShufl);
    
    //Show the Shuffled Deck
    cout<<"\nHere's a well-shuffled deck of cards:"<<endl;
    dspDeck(deck);
    
    //Get players and deal them cards
    twoClbs=dlPlayr(players,nPlayrs,deck,hndSize);
    
    //Display the hands before sorting
    cout<<"\nThe players' hands before sorting:\n";
    for (short i=0;i<nPlayrs;i++){
        dspHand(players[i],hndSize);
    }
    
    //Sort the players' hands
    for (short i=0;i<nPlayrs;i++){
        srtHand(players[i],hndSize);
    }
    
    //Display the hands after sorting
    cout<<"\nThe players' hands after sorting:\n";
    for (short i=0;i<nPlayrs;i++){
        dspHand(players[i],hndSize);
    }
    
    //Play round 1 - player with 2C goes first
    cout<<"\nThe owner of the two of clubs is "
            <<players[twoClbs].name<<".\n";
    cout<<"\nRound 1! "<<players[twoClbs].name<<" leads the round:\n";
    lead=Round1(players,nPlayrs,hndSize,twoClbs);
    round++;
    
    //Display the hands after sorting
    cout<<"\nThe players' hands after Round 1:\n";
    for (short i=0;i<nPlayrs;i++){
        dspHand(players[i],hndSize);
    }
    
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
    char suit[]={'C','S','D','H'}; //H=hearts,S=spades,C=clubs,D=diamonds
    char face[]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'}; //2,3,4,5,6,7,8,9,10,Jack,Queen,King,Ace
    //Fill the cards
    tempDck.nCards=52; //One 52-card deck (will vary in later versions)
    //Allocate memory to the deck of Cards and its index
    tempDck.cards=new Card[tempDck.nCards];
    for (short i=0;i<tempDck.nCards;i++){
        tempDck.cards[i].face=face[i%13]; //Each suit has one of each card face
        tempDck.cards[i].suit=suit[i/13]; //Fill the suit
        tempDck.cards[i].order=i;
        tempDck.cards[i].value=i%13+2;
        if (suit[i/13]=='C' || suit[i/13]=='S' || suit[i/13]=='D'){
            tempDck.cards[i].point=0;
            if (suit[i/13]=='S' && face[i%13]=='Q')
                tempDck.cards[i].point=13;
        }
        else if (suit[i/13]=='H')
            tempDck.cards[i].point=1;
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
void dspDeck(const Deck cards){
    //Display the cards 1 line per suit
    for (short i=0;i<cards.nCards;i++){
        cout<<cards.cards[i].face<<cards.cards[i].suit<<"("
                <<cards.cards[i].order<<","<<cards.cards[i].value<<","
                <<cards.cards[i].point<<") ";
        if (i%13==13-1 || i%13==13-7)
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
    short c2; //Who owns the 2 of Clubs card?
    
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
            //Note who owns the 2C card
            if (plyr[p].hand[cnt].suit=='C' && plyr[p].hand[cnt].face=='2')
                c2=p;
            crdCnt++;
        }
    }
    
    //Exit function
    return c2;
}

//********************************************************
//Sort and organize a hand of cards first by suit, then  *
//by face.                                               *
//Input a Player array and short size of hand.           *
//********************************************************
void srtHand(Player plyr,short sizeH){
    for (short pos=0;pos<sizeH-1;pos++){ //Look at the cards starting w/the 1st...
        for (short i=pos+1;i<sizeH;i++){ //compare to the next card
            if (plyr.hand[pos].order>plyr.hand[i].order){
                Card temp=plyr.hand[i];
                plyr.hand[i]=plyr.hand[pos];
                plyr.hand[pos]=temp;
            }
        }
    }
}

//********************************************************
//Display a hand of cards.                               *
//Input a Player array and short size of hand.           *
//********************************************************
void dspHand(const Player plyr,short sizeH){
    cout<<plyr.name<<": ";
    for (short i=0;i<sizeH;i++){
        cout<<plyr.hand[i].face<<plyr.hand[i].suit<<"("
                <<plyr.hand[i].order<<","<<plyr.hand[i].value
                <<","<<plyr.hand[i].point<<") ";
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
short Round1(Player plyr[],short nPlyr,short sizeH,short first){    
    short trn=first; //track whose turn it is to lay down a card in the round
    Card trck[nPlyr]; //track the card that leads the round & all other cards played
    
    //Each player plays one round, starting with the player with the 2C card
    for (short cnt=0;cnt<nPlyr;cnt++){
        //Play the 2C first
        if (trn==first){
            trck[cnt]=plyr[trn].hand[0];
            trck[cnt].order=trn;
            plyr[trn].trick=plyr[trn].hand[0];
            nullCrd(plyr[trn].hand[0]);
        }
        //Everyone else plays what they can
        else{
            short indx; //position of the card that the player will play for the trick
            indx=srchHnd(plyr[trn].hand,sizeH,trck[0],1);
            trck[cnt]=plyr[trn].hand[indx];
            trck[cnt].order=trn;
            plyr[trn].trick=plyr[trn].hand[indx];
            nullCrd(plyr[trn].hand[indx]);
            }
        dspCard(plyr[trn]);
        //Sort the player's hand
        srtHand(plyr[trn],sizeH);
        //Get ready for the next player's turn
        if (++trn>=nPlyr)
            trn=0;
    }
    
    return first;
}

//***************************************************************
//Search  a hand of cards for the lowest card in the same suit  *
//as the card that lead the trick. If a card in that suit is    *
//not found, find Queen of spade or highest heart.              *
//Input a Player array, short size of hand, and lead card.      *
//***************************************************************
short srchHnd(Card hand[],short sizeH,const Card lead,short rnd){
    short indx=0,pos; //position of the card that the player will play for the trick
    bool found=false; //indicate if a card in the suit has been found
    bool notHrt=false; //assume they have only hearts, looking for cards that aren't
    
    //Play the lowest valued card in the same suit
    while (indx<sizeH && !found){
        if (hand[indx].suit==lead.suit){ //if they have a card in the same suit
            found=true;
            pos=indx;
        }
        //Note if they have any cards other than hearts
        if (hand[indx].suit!='H' && hand[indx].suit!='Z')
            notHrt=true;
        indx++;
    }
    
    //If the player doesn't have a card in the same suit as the lead card,
    //then search for the Queen of Spades (QS)
    if (!found && rnd>1){
        indx=0;
        while (indx<sizeH && !found){
            //Find QS
            if (hand[indx].suit=='S' && hand[indx].face=='Q'
                    && rnd!=1){ //QS can't be played on the first round
                found=true;
                pos=indx;
            }
        }
    }
    
    //If the player doesn't have a card in the same suit as the lead card,
    //and they don't have the Q of spades, then pull the A or K of spades
    if (!found){
        indx=sizeH-1;
        //If AS
        if (hand[indx].suit=='S' && hand[indx].face=='A'){
            found=true;
            pos=indx;
        }
        //If no AS, find KS
        else if (hand[indx].suit=='S' && hand[indx].face=='K'){
            found=true;
            pos=indx;
        }
        indx--;
    }
    
    //If the player doesn't have a card in the same suit as the lead card,
    //and they don't have the Q,K,or A of spades, then pull the highest
    //ranked heart.
    if (!found){
        if (rnd>1 || !notHrt){
            indx=sizeH-1;
            while (indx>0 && !found){
                if (hand[indx].suit=='H'){
                    found=true;
                    pos=indx;
                }
                indx--;
            }
        }
    }
    
    //If the player doesn't have a Heart, then pull the highest non-point card
    if (!found){
        //Sort by face value
        srtFace(hand,sizeH);
        indx=sizeH;
        while (indx>0 && !found){
            if (hand[indx].suit!='Z' && hand[indx].face=='Z'){
                found=true;
                pos=indx;
            }
            indx--;
        }
    }
    
    return pos;
}

//********************************************************
//Sort and organize a hand of cards first by face value. *
//Input a Player array and short size of hand.           *
//********************************************************
void srtFace(Card hand[],short sizeH){
    for (short pos=0;pos<sizeH-1;pos++){ //Look at the cards starting w/the 1st...
        for (short i=pos+1;i<sizeH;i++){ //compare to the next card
            if (hand[pos].value>=hand[i].value){
                Card temp=hand[i];
                hand[i]=hand[pos];
                hand[pos]=temp;
            }
        }
    }
}

//***************************************************
//Display a card. Input a Card.                     *
//***************************************************
void dspCard(const Player plyr){
    cout<<plyr.name<<" played "<<plyr.trick.face<<plyr.trick.suit<<endl;
}

//***************************************************
//Set a card to something unreal. Input a Card.     *
//***************************************************
void nullCrd(Card &card){
    card.face='Z';
    card.suit='Z';
    card.point=0;
    card.order=card.value=1000;
}