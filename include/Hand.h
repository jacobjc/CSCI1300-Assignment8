// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 8
#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Hand
{
    public:
        Hand();
        Hand(string); //automatically runs clearHand
        ~Hand();

        //methods
        void clearHand();  //clears the hand of cards
        void sortHand(); //sorts the hand based off rank/suit
        void rankHand(); //ranks the hand based off flushes, full houses, etc
        void printHand(); //prints the hand (or rather each card, in order the hand has them in)
        void readHand(); //reads a hand in from a specific file
        void writeHand(string); //write hand to a file
        int split(string, char, string[]); //splits strings based off a char


        void highCard(); //highest card in a deck
        bool pair(); //checks for a pair within the hand
        bool twoPair(); //checks for a twopair within the hand
        bool threeOfAKind(); //checks for a threeofakind within the hand
        bool straight(); //checks for a straight within the hand
        bool flush(); //checks for a flush within the hand
        bool fullHouse(); //checks for a fullHouse within the hand
        bool fourOfAKind(); //checks for a fourofakind within the hand
        bool straightFlush(); //checks for a straightflush within the hand
        bool royalFlush(); //checks for a royalflush within the hand
        //variables
        Card highHRCard; //the highest card based on Hand Rank, for determining ties


    private:

        //methods

        //variables
        int twoPairVal;
        int threeOfAKindVal;
        string filename;
        Card handArr[5]; //5 cards in a hand

};

#endif // HAND_H

