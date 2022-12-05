#pragma once

class Node		// prefix_trie node
{
public:
	int height;		// height of node in prefix_trie
	char Value;		// value of node; can be either A, C, G, T
	
	Node* children[4];		// pointer to children of current node
							// each node has only 4 children; A, C, G and T
	Node();
};