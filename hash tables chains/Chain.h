#pragma once

struct node{

    node* next;
    char array[11];
    int l;

};

class Chain{

public:

    node* head;
    node* tail;

    Chain();
    void insert(char* d, int l);
    ~Chain();

};