//
// Created by dog on 20/02/24.
//

#include "Queue.h"
#include "Node.h"
#include <iostream>

Queue::Queue() {
    this->front = nullptr;
    this->rear = nullptr;
}

void Queue::getInto(Card card) {
    Node *newNode = new Node();
    newNode->card = card;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

Card Queue::takeOut() {
    Card card = front->card;
    Node *aux = front;

    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
    }

    delete aux;
    return card;
}

bool Queue::isEmpty() const {
    return front == nullptr;
}

void Queue::print() {
    Node *current = front;
    while (current != nullptr) {
        //current->card.print();
        cout << *current->card.getSymbol() << *current->card.getSuit() << endl;
        current = current->next;
    }
    std::cout << std::endl;
}