//
// Created by dog on 20/02/24.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Para std::shuffle
#include <random>    // Para std::default_random_engine y std::random_device
#include "Deck.h"
#include "Card.h"
using namespace std;

string symbols[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
string suits[] = {"!!", "<3","<>","E3"};
char color1 = 'N', color2 = 'R';

Deck::Deck() {
    fillDeck();
}

void Deck::fillDeck() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if(i == 0 || i == 3) {
                this->cards.emplace_back(&symbols[j],&suits[i],color1,j+1);
            }
            else {
                this->cards.emplace_back(&symbols[j],&suits[i],color2,j+1);
            }
        }
    }
    mixDeck();
}

void Deck::mixDeck() {
    random_device rd;
    default_random_engine rng(rd());
    shuffle(cards.begin(), cards.end(), rng);
}

void Deck::print(){
    for (Card& card : cards) {
        cout << "Palo: " << *card.getSuit() << ", Valor: " << *card.getSymbol() <<
        ", Color: " << card.getColor() << endl;
    }
}

vector<Card>& Deck::getDeck() {return cards;}
