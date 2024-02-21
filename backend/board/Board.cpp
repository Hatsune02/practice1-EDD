//
// Created by dog on 20/02/24.
//
#include <iostream>
#include "Board.h"
#include <stack>
#include "../cards/Deck.h"
using namespace std;

Board::Board() {
    this->queue1 = new Queue();
    this->queue2 = new Queue();
    this->col1 = new LinkedList();
    this->col2 = new LinkedList();
    this->col3 = new LinkedList();
    this->col4 = new LinkedList();
    this->col5 = new LinkedList();
    this->col6 = new LinkedList();
    this->col7 = new LinkedList();
}

void Board::fillBoard() {
    Deck *deck = new Deck();

    for (int i = 0; i < 52; ++i) {
        if(i<24) queue1->getInto(deck->getDeck()[i]);
        else if(i==24) col1->addToFront(deck->getDeck()[i]);
        else if(i<27) col2->addToFront(deck->getDeck()[i]);
        else if(i<30) col3->addToFront(deck->getDeck()[i]);
        else if(i<34) col4->addToFront(deck->getDeck()[i]);
        else if(i<39) col5->addToFront(deck->getDeck()[i]);
        else if(i<45) col6->addToFront(deck->getDeck()[i]);
        else col7->addToFront(deck->getDeck()[i]);
    }
    queue1->print();
    cout<<endl;
    cout<<endl;
    col1->print();
    cout<<endl;
    col2->print();
    cout<<endl;
    col3->print();
    cout<<endl;
    col4->print();
    cout<<endl;
    col5->print();
    cout<<endl;
    col6->print();
    cout<<endl;
    col7->print();
    cout<<endl;
}