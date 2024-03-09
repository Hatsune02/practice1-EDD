//
// Created by dog on 20/02/24.
//

#include "Queue.h"
#include <iostream>

Queue::Queue() {
    this->front = nullptr;
    this->rear = nullptr;
}

Queue::Queue(const Queue& other) {
    front = nullptr;
    rear = nullptr;

    Node* current = other.front;
    while (current != nullptr) {
        // Crear una nueva instancia de Node y Card para cada nodo en la cola
        Node* newNode = new Node();
        newNode->card = current->card;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        current = current->next;
    }
}

void Queue::getInto(Card card) {
    Node *newNode = new Node();
    newNode->card = card;
    newNode->next = nullptr;

    if (front == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

Card Queue::takeOut() {
    Card card = front->card;
    Node *aux = front;

    if (front == rear) front = rear = nullptr;
    else front = front->next;

    delete aux;
    return card;
}
Card Queue::takeOutRear() {
    if(rear){
        Card card = rear->card;

        if (rear == front) {
            delete rear;
            front = rear = nullptr;
        }
        else {
            Node *prev = front;
            while(prev->next != rear){
                prev = prev->next;
            }
            delete rear;
            rear = prev;
            rear->next = nullptr;
        }
        return card;
    }
    return {};

}

Card Queue::getCard() {
    return rear->card;
}

void Queue::moveCards(Queue *& queue) {
    if(front) queue->getInto(takeOut());
    else{
        front = queue->front;
        rear = queue->rear;
        queue->front = nullptr;
        queue->rear = nullptr;
    }
}

void Queue::print(bool hidden) {
    if(hidden) {
        if(rear) cout << "██  ";
        else cout << "░░  ";
    }
    else {
        if(rear) rear->card.print();
        else cout << "░░";
    }
/*    Node *current = front;
    cout << endl;
    while (current != nullptr) {
        cout << *current->card.getSymbol() << *current->card.getSuit() << " ";
        current = current->next;
    }
    cout << endl;*/
}