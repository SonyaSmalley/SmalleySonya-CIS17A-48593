/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on November 12, 2021, 4:00 PM
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
Player *getPlyr(short &nPlyr); //Create an array of Players
void shuffle(Deck cards,short nShuf); //Shuffle a deck of cards
short dlPlayr(Player plyr[],short nPlyr,Deck cards,short sizeH); //Deal the players
void srtHand(Player plyr,short sizeH); //Sort/Organize a player's hand by suit & face
void srtFace(Card hand[],short sizeH); //Sort/Organize a player's hand by face
void srtFcSt(Card hand[],short sizeH); //Sort a player's hand by face, then suit
void swapCrd(Card &a,Card &b); //Swap two cards
void dspDeck(const Deck cards); //Display the deck of cards
void dspHand(const Player plyr,short sizeH); //Display a player's hand
short rndPlay(Player plyr[],short nPlyr,short sizeH,short first,
        short rnd,bool &brkn); //Play 1st round - 2C first
short srchHnd(Card hand[],short sizeH,const Card lead,
        short rnd); //Search for a card in a hand
void dspCard(const Player plyr); //Display a card
void nullCrd(Card &card); //Set a card to be an unreal card
short pickCrd(Card hand[],short sizeH,bool brkn); //Pick which card to lead with

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    short nShufl=7; //Optimal number of shuffles to mix the cards is 7
    short nPlayrs; //Four players for this game
    short hndSize; //The size of each player's hand (same for all)
    short first; //Indicate which player goes first on next round
    short round=1, //Track which round it is
          maxRnd; //The number of rounds to play to deplete player hands
    Deck deck; //A deck of playing cards
    Player *players; //Array of players
    bool broken=false; //Has a heart or a QS been played/broken?
    
    //Initialize Variables
    deck=filDeck();
    players=getPlyr(nPlayrs);
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
    
    //Get players and deal them cards; Determine who has the 2C card
    first=dlPlayr(players,nPlayrs,deck,hndSize);
    
    //Sort the players' hands
    for (short i=0;i<nPlayrs;i++){
        srtHand(players[i],hndSize);
    }
    
    //Display the hands after sorting
    cout<<"\nThe players' hands after sorting:\n";
    for (short i=0;i<nPlayrs;i++){
        dspHand(players[i],hndSize);
    }
    
    //Play the game - player with 2C goes first in round 1
    cout<<"\nThe owner of the two of clubs is "
            <<players[first].name<<".\n";
    for (short r=1;r<=maxRnd;r++){
        cout<<"\nRound "<<r<<"! "<<players[first].name<<" leads the round:\n";
        first=rndPlay(players,nPlayrs,hndSize,first,round,broken);
        round++;

        //Display the hands after sorting
        cout<<"\nThe players' hands after Round "<<r<<":\n";
        for (short i=0;i<nPlayrs;i++){
            dspHand(players[i],hndSize);
        }
    }
    
    //Deallocate memory
    for (short i=0;i<nPlayrs;i++){
        delete []players[i].hand;
    }
    delete []players;
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
    char suit[]={'C','D','S','H'}; //H=hearts,S=spades,C=clubs,D=diamonds
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

//******************************************************
//Get and the number of players. Return Player array.  *
//Input short number of players.                       *
//******************************************************
Player *getPlyr(short &nPlyr){
    nPlyr=4;
    Player *plyr=new Player[nPlyr];
    
    return plyr;
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

//*******************************************************************
//Assign players and deal them a hand of cards. Return short value  *
//indicating who owns the 2C card.                                  *
//Input a Player array of players, short number of players,         *
//string array of cards, and short size of deck.                    *
//*******************************************************************
short dlPlayr(Player plyr[],short nPlyr,Deck cards,short sizeH){
    //Create the player names
    string names[]={"Haley","Juan","Phuong","Sakura","Hatem","Soraya",
                    "Sal","Kishor","Quinn","Rommel","Mandana"};
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

//*************************************************************
//Sort and organize a hand of cards first by face value, then *
//by suit.                                                    *
//Input a Player array and short size of hand.                *
//*************************************************************
void srtFcSt(Card hand[],short sizeH){
    //Sort by face value
    for (short pos=0;pos<sizeH-1;pos++){ //Look at the cards starting w/the 1st...
        for (short i=pos+1;i<sizeH;i++){ //compare to the next card
            if (hand[pos].value>hand[i].value){ //lowest values should be first
                swapCrd(hand[i],hand[pos]);
            }
        }
    }
    
    //Sort by suit: clubs & diamonds first, then spades, then hearts
    for (short pos=0;pos<sizeH-1;pos++){ //Look at the cards starting w/the 1st...
        for (short i=pos+1;i<sizeH;i++){ //compare to the next card
            if (hand[pos].value==hand[i].value){ //sort by the suit
                if (hand[pos].suit=='H') //hearts should be last if equal
                    swapCrd(hand[i],hand[pos]);
                else if (hand[pos].suit=='Q' && 
                        (hand[i].suit=='C' || hand[i].suit=='D'))
                    swapCrd(hand[i],hand[pos]);
            }
        }
    }
}

void swapCrd(Card &a,Card &b){
    Card temp=a;
    a=b;
    b=temp;
}

//********************************************************
//Display a deck of cards.                               *
//Input a string array of cards and short size of deck.  *
//********************************************************
void dspDeck(const Deck cards){
    //Display the cards 1 line per suit
    for (short i=0;i<cards.nCards;i++){
        cout<<cards.cards[i].face<<cards.cards[i].suit<<" ";
        if (i%13==13-1)
            cout<<endl;
    }    
}

//********************************************************
//Display a hand of cards.                               *
//Input a Player array and short size of hand.           *
//********************************************************
void dspHand(const Player plyr,short sizeH){
    cout<<plyr.name<<": ";
    for (short i=0;i<sizeH;i++){
        //if (plyr.hand[i].face!='Z')
            cout<<plyr.hand[i].face<<plyr.hand[i].suit<<" ";
    }
    cout<<endl;
}

//*********************************************************************
//Play a round of cards. Player with 2C goes first, or player who won *
//last trick goes first. Players take turns laying down a card.       *
//Hearts and QS can't be played on the first round unless. Two Clubs  *
//starts round 1. Highest in the suit of lead card takes the trick.   *
//Returns short value indicating winner of the trick.                 *
//Input a Player array of players, short number of players, short     *
//size of starting hand, short player to go first, short round, and.  *
//bool broken.                                                        *
//*********************************************************************
short rndPlay(Player plyr[],short nPlyr,short sizeH,short first,short rnd,
            bool &brkn){    
    short trn=first; //track whose turn it is to lay down a card in the round
    Card trck[nPlyr]; //track the card that leads the round & all other cards played
    short highCrd; //track which is the highest card in the lead card's suit
    
    //Each player plays one round, starting with the player with the 2C card
    for (short cnt=0;cnt<nPlyr;cnt++){
        short indx; //position of the card that the player will play for the trick
        //Play the 2C first
        if (trn==first && rnd==1){
            trck[cnt]=plyr[trn].hand[0]; //add the player's card to the trick pile
            trck[cnt].order=trn; //note who played the card in the order variable
            plyr[trn].trick=plyr[trn].hand[0]; //note which card the player played
            nullCrd(plyr[trn].hand[0]); //"remove" the played card from player's hand
            highCrd=trck[cnt].value; //the lead card starts as the highest card in the suit
        }
        //If it's not round 1, the player who leads the round chooses a card
        else if (trn==first && rnd>1){
            indx=pickCrd(plyr[trn].hand,sizeH,brkn); //choose a card to lead
            trck[cnt]=plyr[trn].hand[indx]; //add the player's card to the trick pile
            trck[cnt].order=trn; //note who played the card in the order variable
            plyr[trn].trick=plyr[trn].hand[indx]; //note which card the player played
            nullCrd(plyr[trn].hand[indx]); //"remove" the played card from player's hand
            highCrd=trck[cnt].value; //the lead card starts as the highest card in the suit
        }
        //Everyone else plays what they can
        else{
            indx=srchHnd(plyr[trn].hand,sizeH,trck[0],rnd); //choose a card to play
            trck[cnt]=plyr[trn].hand[indx]; //add the player's card to the trick pile
            trck[cnt].order=trn; //note who played the card in the order variable
            plyr[trn].trick=plyr[trn].hand[indx]; //note which card the player played
            nullCrd(plyr[trn].hand[indx]); //"remove" the played card from player's hand
            //If the card played is in the same suit as the lead card, see if
            //the card is of higher value than other's played in the suit
            if (trck[cnt].suit==trck[0].suit && trck[cnt].value>highCrd){
                highCrd=trck[cnt].value; //this card is now the highest in the suit
                first=trn; //the player with the highest card in the suit, leads next
            }
            //Note if hearts have been broken (if QS or an H has been played)
            if (!brkn){
                if (trck[cnt].suit=='H')
                    brkn=true;
                if (trck[cnt].face=='Q' &&trck[cnt].suit=='S')
                    brkn=true;
            }
        }
        dspCard(plyr[trn]);
        //Sort the player's hand
        srtHand(plyr[trn],sizeH);
        //Get ready for the next player's turn
        if (++trn>=nPlyr)
            trn=0;
    }
    //Return who goes first on the next round (whoever played the highest card
    //in the same suit as the lead card during this round)
    cout<<plyr[first].name<<" won the trick!\n";
    return first;
}

//***************************************************************
//Search  a hand of cards for the lowest card in the same suit  *
//as the card that lead the trick. If a card in that suit is    *
//not found, find Queen of spade or highest heart.              *
//Input a Player array, short size of hand, lead Card, and      *
//short round number.
//***************************************************************
short srchHnd(Card hand[],short sizeH,const Card lead,short rnd){
    short indx=0,pos; //position of the card that the player will play for the trick
    bool found=false; //indicate if a card in the suit has been found
    
    //Play the lowest valued card in the same suit
    while (indx<sizeH && !found){
        if (hand[indx].suit==lead.suit){ //if they have a card in the same suit
            found=true;
            pos=indx;
        }
        indx++;
    }
    
    //If the player doesn't have a card in the same suit as the lead card,
    //then search for the Queen of Spades (QS)
    if (!found && rnd>1){
        indx=0;
        while (indx<sizeH && !found){
            //Find QS
            if (hand[indx].face=='Q' && hand[indx].suit=='S'){
                found=true;
                pos=indx;
            }
            indx++;
        }
    }
    
    //If the player doesn't have a card in the same suit as the lead card,
    //and they don't have the Q of spades, then pull the A or K of spades
    if (!found){
        indx=sizeH-1;
        while (indx>=0 && !found){
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
    }
    
    //If the player doesn't have a card in the same suit as the lead card,
    //and they don't have the Q,K,or A of spades, then pull the highest
    //ranked heart first. If no hearts, pull the highest ranked non-point card.
    if (!found){
        //Sort by face value
        srtFace(hand,sizeH);
        indx=sizeH-1;
        while (indx>=0 && !found){
            if (hand[indx].suit!='Z'){
                found=true;
                pos=indx;
            }
            indx--;
        }
    }
    
    return pos;
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

//***************************************************************
//Pick a card from a hand of cards to lead the trick.           *
//Input a Player array and short size of hand.                  *
//***************************************************************
short pickCrd(Card hand[],short sizeH,bool brkn){
    short indx=0,pos; //position of the card that the player will play for the trick
    bool found=false; //indicate if a card in the suit has been found
    
    //Sort the player's hand by face value then suit
    srtFcSt(hand,sizeH);
    while (!found){
        if (brkn){
            found=true;
            pos=indx;
        }
        else if (!brkn && hand[indx].suit!='H'){
            found=true;
            pos=indx;
        }
        indx++;
    }
    
    return pos;
}