//
// Created by dog on 20/02/24.
//

#ifndef PRACTICE1_EDD_CARD_H
#define PRACTICE1_EDD_CARD_H
#include <string>
using namespace std;

class Card {
private:
    string *symbol;
    string *suit;
    char color;
    int value;
    bool hidden;
public:
    //CONSTRUCTOR
    Card();
    Card(string*, string*, char, int);
    //getters
    string* getSymbol();
    string* getSuit();
    char getColor();
    int getValue();
    bool getHidden();
    //setter
    void setHidden(bool);
};


#endif //PRACTICE1_EDD_CARD_H
