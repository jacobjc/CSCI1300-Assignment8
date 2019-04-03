// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 8
#include "Deck.h"
#include <iostream>
#include <fstream>
using namespace std;

Deck::Deck(){
    //ctor
}
//ctor
Deck::Deck(string nFilename){
    filename = nFilename;
    clearDeck();
}

Deck::~Deck(){
    //dtor
}
//sets every card in the deck to 0,0
void Deck::clearDeck(){
    Card tempCard(0,0);
    for(int i=0; i<52; i++){
        deckArr[i] = tempCard;
    }
}
//splits strings based off a char
int Deck::split(string str, char s, string words[]){
    int arrSize = 0;
    string temp = "";
    int c=0;

        if(str.length() == 0){
        return 0;
    }

    for(int i=0; i<str.length(); i++){

        if(str[i]==s){
            words[c] = temp;
            arrSize++;
            temp = "";
            c++;
        }
        else{
            temp += str[i];
        }

    }
    words[c] = temp;
    arrSize++;
    return arrSize;
}
//reads the deck in from a given file, puts into deckArr
void Deck::readDeck(){
    ifstream fr;
    fr.open(filename.c_str());
    string line;
    int i = 0;

    if(fr.is_open()){
        while(!fr.eof()){
            if(i < 52){
                string tempArr[2];
                getline(fr, line);
                split(line, ',', tempArr);
                Card tempCard(stoi(tempArr[0]), stoi(tempArr[1]));
                deckArr[i] = tempCard;
                i++;
            }
        }
        cout << "Read Deck from " << filename << "!" << endl;
        fr.close();
    }
    else{
        cout << "Unable to read Deck file!" << endl;
    }
}
//prints the entire deck out to console
void Deck::printDeck(){
    for(int i=0; i<52; i++){
        deckArr[i].printCard();
    }
}
//shuffles the deck based on the given srand function and the time(NULL) seed. %52's the random number, giving a different sequence every time.
void Deck::shuffleDeck(){
    srand((int)time(0));
    for(int i=0; i<52; i++){
        int r = (rand() % 52);
        Card temp1 = deckArr[i];
        Card temp2 = deckArr[r];
        deckArr[i] = temp2;
        deckArr[r] = temp1;
    }
    cout << "Deck shuffled!" << endl;
}
//sorts function based of my ranking system, using bubble sort, with 2 for loops and an if
void Deck::sortDeck(){
    for(int i=0; i<52; i++){
        for(int j=0; j<51; j++){
            if(deckArr[j].getRank() > deckArr[j+1].getRank()){
                Card temp1 = deckArr[j];
                Card temp2 = deckArr[j+1];
                deckArr[j] = temp2;
                deckArr[j+1] = temp1;
            }
            if(deckArr[j].getSuit() > deckArr[j+1].getSuit()){
                Card temp1 = deckArr[j];
                Card temp2 = deckArr[j+1];
                deckArr[j] = temp2;
                deckArr[j+1] = temp1;
            }
        }
    }
    cout << "Deck sorted!" << endl;
}
//writes deck to a specified file, in the same format in which it was read in as
void Deck::writeDeck(string filewrite){
    ofstream fw;
    fw.open(filewrite.c_str());
    string line;
    if(fw.is_open()){
            for(int i=0; i<52; i++){
                fw << deckArr[i].getRank();
                fw << "," << deckArr[i].getSuit();
                if(i<51){
                    fw << "\r\n";
                }
            }
        }
    else{
        cout << "Unable to write to Deck file!" << endl;
    }
    cout << "Wrote Deck to " << filewrite << "!" << endl;
    fw.close();
}
//writes the first 5 cards to a file, which can be read in the hand function to create a shuffled hand (if the deck was shuffled)
void Deck::writeDeckToHand(string filehand){
    ofstream fw;
    fw.open(filehand.c_str());
    string line;
    if(fw.is_open()){
            for(int i=0; i<5; i++){
                fw << deckArr[i].getRank();
                fw << "," << deckArr[i].getSuit();
                if(i<4){
                    fw << "\r\n";
                }
            }
        }
    else{
        cout << "Unable to write to Hand file!" << endl;
    }
    cout << "Wrote the first Hand of Deck to " << filehand << "!" << endl;
    fw.close();
}
//returns a card from a specified location in the deck.
Card Deck::returnCard(int i){
    return deckArr[i];
}
