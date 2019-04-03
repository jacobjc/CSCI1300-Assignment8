// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 8
#include "Card.h"
#include <iostream>
using namespace std;

//ctor
Card::Card(){
    suit = 0;
    rank = 0;
}
//ctor
Card::Card(int sRank, int sSuit){
    rank = sRank;
    suit = sSuit;
}

Card::~Card()
{
    //dtor
}
//sets rank
void Card::setRank(int sRank){
    rank = sRank;
}
//sets suit
void Card::setSuit(int sSuit){
    suit = sSuit;
}
//gets rank
int Card::getRank(){
    return rank;
}
//gets suit
int Card::getSuit(){
    return suit;
}
//sets card (both rank and suit)
void Card::setCard(int sRank, int sSuit){
    rank = sRank;
    suit = sSuit;
}
//sets card to 0,0
void Card::clearCard(){
    suit = 0;
    rank = 0;
}
//prints card in format: "6 of Spades" with Ace=1, Jack=11, Queen=12, King=13 and Hearts=1, Spades=2, Diamonds=3, Clubs=4
void Card::printCard(){
    if(rank == 1){
        cout << "Ace";
    }
    else if(rank == 11){
        cout << "Jack";
    }
    else if(rank == 12){
        cout << "Queen";
    }
    else if(rank == 13){
        cout << "King";
    }
    else if(rank <= 0 || rank > 13){
        cout << "Erorr";
    }
    else{
        cout << rank;
    }

    cout << " of ";

    if(suit == 1){
        cout << "Hearts";
    }
    else if(suit == 2){
        cout << "Spades";
    }
    else if(suit == 3){
        cout << "Diamonds";
    }
    else if(suit == 4){
        cout << "Clubs";
    }
    else{
        cout << "Error";
    }

    cout << endl;
}
