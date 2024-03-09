//
// Created by dog on 20/02/24.
//

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}
LinkedList::LinkedList(const LinkedList& other) {
    head = nullptr;
    tail = nullptr;

    Node* current = other.head;
    while (current != nullptr) {
        // Crear una nueva instancia de Node y Card para cada nodo en la lista
        Node* newNode = new Node();
        newNode->card = current->card;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
        current = current->next;
    }
}
LinkedList::~LinkedList() {
    Node *current = head;
    while (current) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::addToFront(Card card) {
    Node *newNode = new Node();
    newNode->card = card;
    newNode->next = head;
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
}

Card LinkedList::removeFront() {
    Node *aux = head;
    Card card = head->card;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete aux;
    return card;
}

void LinkedList::moveCardsToStack(Stack *& stack) {
    if(stack->validatePush(head->card)){
        stack->push(removeFront());
    }
}

void LinkedList::moveCardFromDeck(Queue* &queue) {
    if(validateMoveFromQueue(queue->getCard())) {
        addToFront(queue->takeOutRear());
    }
}

void LinkedList::moveCards(const string& symbol, const string& suit, LinkedList* &list) {
    Node *current = head;
    Node *aux = nullptr;

    while (current) {
        if(*current->card.getSymbol() == symbol && *current->card.getSuit() == suit){
            aux = current;
            break;
        }
        current = current->next;
    }
    if(!aux){
        cout << "No existe esa carta en esta lista." << endl;
        return;
    }

    if(validateMove(aux, list)) moveNodes(aux, list);
}

bool LinkedList::validateMove(Node *& node, LinkedList *& list) {
    //Ve si el valor y color de la carta son correctos con la otra lista
    if(node->card.getValue() == (list->head->card.getValue()-1)
       && node->card.getColor() != list->head->card.getColor()){
        //Ve si el valor y color de la carta son correctos en su anterior
        if(node->prev){
            if(node->card.getValue() == (node->prev->card.getValue()+1)
               && node->card.getColor() != node->prev->card.getColor()){
                return true;
            }
        }
        else{
            return true;
        }
    }
    cout << "No se puede realizar este movimiento." << endl;
    return false;
}

bool LinkedList::validateMoveFromQueue(Card card) {
    if(card.getValue() == (head->card.getValue() - 1)
    && card.getColor() != (head->card.getColor())) return true;
    cout << "No se puede realizar este movimiento." <<endl;
    return false;
}

//guardar nodo y list1 y list2, si se retrocede entonces el metodo sera de la lista2(nodo, list1)
void LinkedList::moveNodes(Node* & node, LinkedList* &list) {
    Node *firstNode = head;
    if(node->next) node->next->prev = nullptr;
    else{
        head = nullptr;
        tail = nullptr;
    }
    head = node->next;
    node->next = list->head;
    if(list->head) list->head->prev = node;
    list->head = firstNode;
}

void LinkedList::print() {
    Node *current = tail;
    while (current) {
        if(current == head){
            current->card.setHidden(false);
        }
        current->card.print();
        current = current->prev;
    }
   cout << endl;
}

Card LinkedList::firstCard() {
    if(head) return head->card;
    return {};
}

Node *LinkedList::getTail() {
    return tail;
}

Node *LinkedList::getHead() {
    return head;
}

Node *LinkedList::getNodePosition(int pos) {
    if (pos < 0) {
        return nullptr;
    }
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        if (count == pos) {
            return current;
        }
        current = current->next;
        count++;
    }
    return nullptr;
}

bool LinkedList::showCard(int pos, int show) {
    Node* aux = getNodePosition(pos);
    if(aux){
        if(show == 1){ // +1 NEXT MOSTRAR
            if(aux->next) aux->next->card.setHidden(false);
            else {
                cout << "No tiene siguiente\n"<<endl;
                return false;
            }
        }
        else if(show == 2){ // +2 PREV MOSTRAR
            if(aux->prev) aux->prev->card.setHidden(false);
            else {
                cout << "No tiene anterior\n"<<endl;
                return false;
            }
        }
        else if(show == -1){ // -1 NEXT OCULTAR
            if(aux->next) aux->next->card.setHidden(true);
            else {
                cout << "No tiene siguiente\n"<<endl;
                return false;
            }
        }
        else if(show == -2){ // -2 PREV OCULTAR
            if(aux->prev) aux->prev->card.setHidden(true);
            else {
                cout << "No tiene anterior\n"<<endl;
                return false;
            }
        }
        return true;
    }
    else cout << "No existe esa carta\n" << endl;
    return false;
}


