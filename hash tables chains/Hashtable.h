#pragma once
#include "Chain.h"

class Hashtable{

private:

    Chain* table;

public:

    Hashtable(int size);
    void insert(char* d, int l);;
    node* search_head(char* d);
    long hash(char* d);

    ~Hashtable();

};