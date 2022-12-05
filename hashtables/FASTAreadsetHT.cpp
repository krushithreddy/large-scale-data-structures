#include "FASTAreadsetHT.h"

// Hashtable constructor, hash table size is passed as argument.
FASTAreadset_HT::FASTAreadset_HT(int ht_size) {
	h = new node*[ht_size];
	for (int i = 0; i < ht_size; ++i) {
		*(h + i) = NULL;
	}

	this->ht_size = ht_size;
	this->collision = 0;
}

// Destructor of the hashtable deleting hashtable data.
FASTAreadset_HT::~FASTAreadset_HT() {
	for (unsigned int i = 0; i < ht_size; ++i) {
		node *curr = *(h + i);
		while (curr != NULL) {
			node *next = curr->next;
			delete curr;
			curr = next;
		}
	}
}

// convert a 16 mer data to an unsigned int. Each character A C G T is converted to 2 bits, thus 16 characters use
// 32 bits of an unsigned int
unsigned int FASTAreadset_HT::Str16ToInt(char *str) {

	unsigned int ret = 0;
	for (int i = 0; i < 16; i++) {
		unsigned int val = 0;
		if (str[i] == 'A')
			val = 0;
		else if (str[i] == 'C')
			val = 1;
		else if (str[i] == 'G')
			val = 2;
		else if (str[i] == 'T')
			val = 3;
		ret = (ret * 4) + val;
	}

	return ret;
}

// use division method/radix to get index of a value in hash table.
unsigned int FASTAreadset_HT::getHashTableIndex(unsigned int strValue,
		int hashtableSize) {
	return strValue % hashtableSize;
}

// search for string sequence in the Hashtable.
bool FASTAreadset_HT::searchValueInHT(char *sequence) {
	unsigned int val = this->Str16ToInt(sequence);

	unsigned int ind = getHashTableIndex(val, ht_size);

	node *prev = *(h + ind);
	if (prev == NULL)
		return -1;
	if (prev != NULL && prev->value == val)
		return true;
	//int cnt = 0;
	//node *nx = prev->next;
	while (prev->next != NULL) {
		prev = prev->next;
		if (prev != NULL && prev->value == val)
			return true;
	}
	return false;
}

// insert a 16 mer value to hash table.
void FASTAreadset_HT::insertIntoHash(char *sequence) {
	unsigned int val = Str16ToInt(sequence);
	unsigned int ind = getHashTableIndex(val, ht_size);

	node *n = new node;
	n->value = val;
	n->next = NULL;

	if (*(h + ind) == NULL) {
		*(h + ind) = n;
	} else {
		// commented code which inserts value at end of the chain as inserting at head.
		// this code will be useful if we want to ignore duplicate values.
		//node *prev = *(h + ind);
		//while (prev->next != NULL)
		//	prev = prev->next;
		//prev->next = n;

		n->next = *(h + ind);
		*(h + ind) = n;

		collision++;

	}

}

