

#ifndef FASTAREADSETHT_H_
#define FASTAREADSETHT_H_

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

// class representing a node in linked list which implements chaining.
struct node {
    unsigned int value;
    node* next;
};


// class representing a hash table.
class FASTAreadset_HT {

private:
	unsigned int Str16ToInt(char *str);
	unsigned int getHashTableIndex(unsigned int strValue, int hashtableSize);

public:


	unsigned int ht_size; // size of hash table
	int collision; // number of collision found while insert
	node ** h;   // actual hash table data. It is an array of linked list to implement chaining
	int sixteen = 16;

	FASTAreadset_HT(int len);
	virtual ~FASTAreadset_HT();
	void insertIntoHash(char* str);
	bool searchValueInHT(char * str);
};

#endif /* FASTAREADSETHT_H_ */
