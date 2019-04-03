// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 8

#include <iostream>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

int main()
{

    //CARD TESTING
    cout << "Card Class Tests:" << endl;
    Card testC(1, 2); //rank, suit  //creating new card
    testC.printCard(); //printing card

    testC.clearCard(); //clearing card
    testC.printCard(); //printing card
    cout << "---------------------------------------------" << endl;

    //DECK TESTING
    cout << "Deck Class Tests:" << endl;
    Deck testD("ReadDeck.txt"); //creating new deck
    testD.readDeck();//reading the deck from file

    testD.shuffleDeck(); //shuffling deck
    //.printDeck(); //printing deck
    //testD.sortDeck(); //sorting deck
    //testD.printDeck(); //printing deck
    testD.writeDeck("WriteDeck.txt"); //writing the deck to file
    testD.writeDeckToHand("ReadHand.txt"); //writing a hand from deck to file
    cout<<endl;
    testD.deckArr[0].printCard(); //printing the 1st card in the deck
    cout << "^First Card in Deck!^" << endl;
    cout << "---------------------------------------------" << endl;

    //HAND TESTING
    cout << "Hand Class Tests:" << endl;
    Hand testH("tester.txt"); //creating new hand ReadHand
    testH.readHand(); //reading hand from file
    testH.sortHand(); //sorting hand (by order in which they come inside a sorted deck, HEARTS, SPADES, DIAMONDS, CLUBS)
    testH.writeHand("WriteHand.txt"); //writing hand to file
    cout<<endl;

    testH.printHand(); //printing hand
    cout << "^Printed Hand^" << endl << endl;

    testH.highCard();//testing for pairs, 3ofkinds, flushes, etc.
    cout<<"pair=";
    if(testH.pair()==true){cout<<"true"<<endl;}else{cout<<"false"<<endl;}
    cout<<"threeOfAKind=";
    if(testH.threeOfAKind()==true){cout<<"true"<<endl;}else{cout<<"false"<<endl;}
    cout<<"flush=";
    if(testH.flush()==true){cout<<"true"<<endl;}else{cout<<"false"<<endl;}
    //cout<<"fullHouse="; //not working at the moment
    //if(testH.fullHouse()==true){cout<<"true"<<endl;}else{cout<<"false"<<endl;}
    cout<<"fourOfAKind=";
    if(testH.fourOfAKind()==true){cout<<"true"<<endl;}else{cout<<"false"<<endl;}

    cout << "HighHRCard is "; //IMPORTANT: high card is used for tie breaking the same Hands with the same HAND RANKS. It is NOT the highest ranked card in the hand UNLESS every Hand Rank is false.
    testH.highHRCard.printCard();

    //testH.highCard().printCard(); //prints the highest card in the hand
    cout << "---------------------------------------------" << endl;

    //PLAYER TESTING
    return 0;
}
