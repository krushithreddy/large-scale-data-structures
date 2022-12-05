#include <iostream>
#include "Chain.h"
using namespace std;

Chain::Chain(){

    head = NULL;
    tail = NULL;

}

void Chain::insert(char* d, int l){

    node* temp = new node;
    temp->l = l;

    for(int i = 0; i < 11; i++){

        temp->array[i] = d[i];

    }

    if(head == NULL){

        head = temp;
        tail = head;
        return;

    }

    tail->next = temp;
    tail = tail->next;

}

Chain::~Chain(){

    node* current = head;
    node* next = NULL;

    while (current != NULL) {
        
        next = current->next;
        delete current;
        current = next;
    
    }

}