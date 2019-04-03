// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 8
#include "Hand.h"
#include <fstream>
#include <iostream>
using namespace std;

Hand::Hand(){
    //ctor
}
//ctor
Hand::Hand(string nFilename){
    filename = nFilename;
    clearHand();
}

Hand::~Hand(){
    //dtor
}
//prints every card in the hand
void Hand::printHand(){
    for(int i=0; i<5; i++){
        handArr[i].printCard();
    }
}

//sets all cards in hand to 0,0
void Hand::clearHand(){
    Card tempCard(0,0);
    for(int i=0; i<5; i++){
        handArr[i] = tempCard;
    }
}
//sorting hand (by order in which they come inside a sorted deck, HEARTS, SPADES, DIAMONDS, CLUBS)
void Hand::sortHand(){
    for(int i=0; i<52; i++){
        for(int j=0; j<4; j++){
            if(handArr[j].getRank() > handArr[j+1].getRank()){
                Card temp1 = handArr[j];
                Card temp2 = handArr[j+1];
                handArr[j] = temp2;
                handArr[j+1] = temp1;
            }
            if(handArr[j].getSuit() > handArr[j+1].getSuit()){
                Card temp1 = handArr[j];
                Card temp2 = handArr[j+1];
                handArr[j] = temp2;
                handArr[j+1] = temp1;
            }
        }
    }
    cout << "Hand sorted!" << endl;
}
//splits strings based off a char
int Hand::split(string str, char s, string words[]){
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
//reads hand in from a given file, puts it into handArr
void Hand::readHand(){
    ifstream fr;
    fr.open(filename.c_str());
    string line;
    int i = 0;

    if(fr.is_open()){
        while(!fr.eof()){
            if(i < 5){
                string tempArr[2];
                getline(fr, line);
                split(line, ',', tempArr);
                Card tempCard(stoi(tempArr[0]), stoi(tempArr[1]));
                handArr[i] = tempCard;
                i++;
            }
        }
        cout << "Read Hand from " << filename << "!" << endl;
        fr.close();
    }
    else{
        cout << "Unable to read Hand file!" << endl;
    }
}
//writes hand into a given file (same format as reading)
void Hand::writeHand(string filewrite){
    ofstream fw;
    fw.open(filewrite.c_str());
    string line;
    if(fw.is_open()){
            for(int i=0; i<5; i++){
                fw << handArr[i].getRank();
                fw << "," << handArr[i].getSuit();
                if(i<4){
                    fw << "\r\n";
                }
            }
        }
    else{
        cout << "Unable to write to Hand file!" << endl;
    }
    cout << "Wrote Hand to " << filewrite << "!" << endl;
    fw.close();
}
//sets a public variable to the highest card (based on my ranking system) from the hand
void Hand::highCard(){
    Card tempCard = handArr[0];

    for(int i=0; i<5; i++){
        if(handArr[i].getRank() >= tempCard.getRank()){
            tempCard = handArr[i];
        }
    }
    highHRCard = tempCard;
}
//checks for a pair within the hand
bool Hand::pair(){
    for(int i=0; i<5; i++){
        int temp = 0;
        for(int j=0; j<5; j++){
            if(handArr[i].getRank() == handArr[j].getRank()){
                temp++;
                if(temp == 2){
                    highHRCard = handArr[i];
                    return true;
                }
            }
        }
    }
    return false;
}
//checks for a two pair within the hand
/*bool Hand::twoPair(){
    int temp2 = 0;
    Card tempCard(0,0);
    for(int i=0; i<5; i++){
        int temp = 0;
        for(int j=0; j<5; j++){
            if(handArr[i].getRank() == handArr[j].getRank()){
                temp++;
                if(temp == 2){
                    temp2++;
                    highHRCard = handArr[i];
                    if(temp2 == 2){
                            if(handArr[i].getRank() > highHRCard.getRank()){
                                highHRCard = handArr[i];
                                twoPairVal = handArr[i].getRank();
                            }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}*/
//checks for a threeofakind within the hand
bool Hand::threeOfAKind(){
    for(int i=0; i<5; i++){
        int temp = 0;
        for(int j=0; j<5; j++){
            if(handArr[i].getRank() == handArr[j].getRank()){
                temp++;
                if(temp == 3){
                    highHRCard = handArr[i];
                    threeOfAKindVal = handArr[i].getRank();
                    return true;
                }
            }
        }
    }
    return false;
}
//checks for a straight within the hand
bool Hand::straight(){

}
//checks for a flush within the hand
bool Hand::flush(){
    for(int i=0; i<5; i++){
        if(handArr[i].getSuit() != handArr[0].getSuit()){
            return false;
        }
    }
    return true;
}
//checks for a fullhouse within the hand
/*bool Hand::fullHouse(){
    if(pair()==true && threeOfAKind()==true && fourOfAKind()==false){
        if(twoPair()==false && twoPairVal!=threeOfAKindVal){
            return true;
        }
    }
    return false;
}*/
//checks for a fourofakind within the hand
bool Hand::fourOfAKind(){
    for(int i=0; i<5; i++){
        int temp = 0;
        for(int j=0; j<5; j++){
            if(handArr[i].getRank() == handArr[j].getRank()){
                temp++;
                if(temp == 4){
                    highHRCard = handArr[i];
                    return true;
                }
            }
        }
    }
    return false;
}
//checks for a straightflush within the hand
bool Hand::straightFlush(){

}
//checks for a royalflush within the hand
bool Hand::royalFlush(){

}
