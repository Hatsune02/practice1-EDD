//
// Created by dog on 20/02/24.
//
#include  <iostream>
#include "Card.h"
#include <string>
using namespace std;

Card::Card() {}
Card::Card(string* symbol, string* suit, char color, int value) {
    this->symbol = symbol;
    this->suit = suit;
    this->color = color;
    this->value = value;
    this->hidden = true;
}

void Card::print() {
    if(hidden) cout << "██ ";
    else cout << *symbol << *suit /*<< color*/ << " ";
}

string* Card::getSymbol() {return symbol;}
string* Card::getSuit() {return suit;}
char Card::getColor() {return color;}
int Card::getValue() {return value;}
bool Card::getHidden() {return hidden;}

void Card::setHidden(bool state) {this->hidden = state;}