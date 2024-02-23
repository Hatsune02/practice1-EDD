//
// Created by dog on 20/02/24.
//
#include <iostream>
#include <string>
#include <algorithm> // Para std::shuffle
#include <random>    // Para std::default_random_engine y std::random_device
#include "Deck.h"
#include "Card.h"
using namespace std;

string symbols[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
string suits[] = {"♠", "♥","♦","♣"};
char color1 = 'N', color2 = 'R';

Deck::Deck() {
    fillDeck();
}

void Deck::fillDeck() {
    int aux = 0;
    this->cards = new Card[52];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if(i == 0 || i == 3) {
                this->cards[aux] = *new Card(&symbols[j],&suits[i],color1,j+1);
            }
            else {
                this->cards[aux] = *new Card(&symbols[j],&suits[i],color2,j+1);
            }
            aux++;
        }
    }
    mixDeck();
}

void Deck::mixDeck() {
    random_device rd;
    default_random_engine rng(rd());
    shuffle(cards, cards+52, rng);
}

void Deck::print(){
    for (int i = 0; i < 52; ++i) {
        cout << "Palo: " << *cards[i].getSuit() << ", Valor: " << *cards[i].getSymbol() <<
             ", Color: " << cards[i].getColor() << endl;
    }
}

Card* Deck::getDeck() {return cards;}
