// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 8
#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

class Card
{
    public:
        Card();
        Card(int, int);
        ~Card();

        //methods
        void setSuit(int); //getters and setters
        void setRank(int);
        int getSuit();
        int getRank();
        void setCard(int, int);

        void clearCard(); //clears suit and rank of card
        void printCard(); //prints card to console
        //variables



    private:

        //methods


        //variables
        int suit;//hearts are 1, spades are 2, diamonds are 3, clubs 4
        int rank;//aces are 1, kings are 13

};

#endif // CARD_H
