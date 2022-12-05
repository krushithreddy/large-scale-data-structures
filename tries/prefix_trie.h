#pragma once

#include "Node.h"

class prefix_trie
{
private:
	Node* TrieBase;			// root
	int NodeInTrie;			// number of nodes in prefix_trie
	
public:
	prefix_trie();		// constructor
	prefix_trie(char*, int, int);		// custom constructor
	prefix_trie(const prefix_trie&);	// copy constructor

	void insert(char*, Node*, int); // recursive insert
	bool search(char*, Node*, int); // recursive search

	int getTrieSize();		// return total nodes in prefix_trie
	Node* getBase();		// returns root

	void DeleteTrie(Node*);			// deletes node in prefix_trie recursively

	~prefix_trie();		// destructor
};