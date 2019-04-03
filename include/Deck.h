// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 8
#ifndef DECK_H
#define DECK_H
#include <iostream>
#include "Card.h"
using namespace std;

class Deck
{
    public:
        Deck();
        Deck(string); //automatically runs clearDeck
        ~Deck();

        //methods
        void readDeck(); //fills deck with cards listed in a file.
        void writeDeck(string); //writes the cards back into a specified file, in it's new order
        void shuffleDeck(); //shuffles deck
        void sortDeck(); //sorts the deck like it would be if you first opened a deck of cards
        void clearDeck(); //clears the deck of cards
        void printDeck(); //prints the deck (or rather each card, in order the deck has them in)
        void writeDeckToHand(string); //writes a hand (first 5 cards) to a specified file
        Card returnCard(int); //returns card from deckArr at given position
        //variables
        int split(string, char, string[]);//splits strings based off a char
        Card deckArr[52]; //52 cards in a deck


    private:
        //methods

        //variables
        string filename;

};

#endif // DECK_H

