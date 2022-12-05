#pragma once
#include "Hashtable.h"

class BLAST_DB{

    Hashtable *table;
    char* genome;

public:
    char arr1[50];  
    char arr2[50];
    char arrDistances[55][55];

    BLAST_DB(char *genome);

    void disassemble(char* genome, int genome_size);
    int ndlmanwun();

    int search_in_table(char* query);

    ~BLAST_DB();

};