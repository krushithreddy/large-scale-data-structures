#include <iostream>
#include <math.h>
#include "Hashtable.h"
using namespace std;

Hashtable::Hashtable(int size){

    table = new Chain[size];

}

void Hashtable::insert(char* d, int l){

    int index = hash(d);

    Chain* chain = &table[index];
    chain->insert(d, l);

}

node* Hashtable::search_head(char* d){

    int index = hash(d);

    Chain *chain = &table[index];

    return chain->head;

}
long Hashtable::hash(char* d){

    long sum = 0;

    for(int i = 0; i < 11; i++){
    
        sum = sum + ((unsigned int)(int(d[i]) * pow(5, i)) % 10000000);

    }

    return (sum % 10000000);

}

Hashtable::~Hashtable(){

    delete [] table;

}   
