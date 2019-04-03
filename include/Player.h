// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 8
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Hand.h"
#include "Deck.h"
using namespace std;

class Player{
    public:
        //methods
        Player();
        Player(string);
        ~Player();

        int highCard(Card);
        bool twoPair();
        bool threeOfAKind();
        bool straight();
        bool flush();
        bool fullHouse();
        bool fourOfAKind();
        bool straightFlush();
        bool royalFlush();

        //variables

    private:
        //methods

        //variables
        string filename;
        Card plHand();
};

#endif // PLAYER_H
