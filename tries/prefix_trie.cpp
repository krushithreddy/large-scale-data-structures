#include <iostream>
#include "prefix_trie.h"

using namespace std;


prefix_trie::prefix_trie()
{
	this->TrieBase = NULL;
	this->NodeInTrie = 0;
}
prefix_trie::prefix_trie(char* SarsCov2, int queries, int flag)
{
	this->TrieBase = NULL;
	this->NodeInTrie = 0;

	int SizeSars = 0;
	int start = -1;
	char _36mer[36] = {' '};
	char arr[4] = {'A', 'C', 'G', 'T'};			// array used to create genome

	while (SarsCov2[SizeSars] != '\0')		// calculating file size
		SizeSars++;

	// cout << "Size Sars: " << SizeSars << endl;

	if (this->TrieBase == NULL)			// create new node at root
	{
		this->TrieBase = new Node;
		this->TrieBase->height = 0;
		this->TrieBase->Value = '*';
	}

	Node* current = this->getBase();

	if (flag == 0)
	{
		for (int i = 0; i < queries; i++)
		{
			start = rand()%(SizeSars-35);

			int j=0;
			while (j<36)
			{
				_36mer[j] = SarsCov2[start + j];
				j++;
			}

			insert(_36mer, current, 0);
		}
	}
	else
	{
		for (int i = 0; i < queries; i++)
		{
			start = rand()%(SizeSars-35);

			int j=0;
			while (j<36)
			{
				_36mer[j] = SarsCov2[start + j];

				if ((rand()%100) < 5)
					_36mer[j] = arr[rand()%4];
				
				j++;
			}

			insert(_36mer, current, 0);
		}
	}
}
prefix_trie::prefix_trie(const prefix_trie& tr)
{}

void prefix_trie::insert(char* str, Node* rt, int i) // recursive insert
{
	if (i == 36)
		return;

	// cout << i << endl;
	
	if (*str == 'A')
	{
		if (rt->children[0] == NULL)
		{
			rt->children[0] = new Node;
			rt->children[0]->Value = 'A';
			rt->children[0]->height = i;
			this->NodeInTrie++;

			// cout << *str << " created A" << endl;
		}
		
		return insert(str+1, rt->children[0], i+1);
	}
	else if (*str == 'C')
	{
		if (rt->children[1] == NULL)
		{
			rt->children[1] = new Node;
			rt->children[1]->Value = 'C';
			rt->children[1]->height = i;
			this->NodeInTrie++;

			// cout << *str << " created C" << endl;
		}
		
		return insert(str+1, rt->children[1], i+1);
	}
	else if (*str == 'G')
	{
		if (rt->children[2] == NULL)
		{
			rt->children[2] = new Node;
			rt->children[2]->Value = 'G';
			rt->children[2]->height = i;
			this->NodeInTrie++;

			// cout << *str << " created G" << endl;
		}
		
		return insert(str+1, rt->children[2], i+1);
	}
	else if (*str == 'T')
	{
		if (rt->children[3] == NULL)
		{
			rt->children[3] = new Node;
			rt->children[3]->Value = 'T';
			rt->children[3]->height = i;
			this->NodeInTrie++;

			// cout << *str << " created T" << endl;
		}
		
		return insert(str+1, rt->children[3], i+1);
	}
	else
		return;
}
bool prefix_trie::search(char* str, Node* rt, int missCount) // recursive search
{
	if (rt->children[0]==NULL && rt->children[1]==NULL && rt->children[2]==NULL && rt->children[3]==NULL)
	{
		if (rt->height == 35)
			return true;
		else
			return false;
	}

	if (missCount == 2)
		return false;

	if (*str == 'A')
	{
		if (rt->children[0])
			return this->search(str+1, rt->children[0], missCount);
		
		if (rt->children[1])
			return this->search(str+1, rt->children[1], missCount+1);
		else if (rt->children[2])
			return this->search(str+1, rt->children[2], missCount+1);
		else if (rt->children[3])
			return this->search(str+1, rt->children[3], missCount+1);
		else 
			return false;
	}

	if (*str == 'C')
	{
		if (rt->children[1])
			return this->search(str+1, rt->children[1], missCount);
		
		if (rt->children[0])
			return this->search(str+1, rt->children[0], missCount+1);
		else if (rt->children[2])
			return this->search(str+1, rt->children[2], missCount+1);
		else if (rt->children[3])
			return this->search(str+1, rt->children[3], missCount+1);
		else 
			return false;
	}

	if (*str == 'G')
	{
		if (rt->children[2])
			return this->search(str+1, rt->children[2], missCount);

		if (rt->children[0])
			return this->search(str+1, rt->children[0], missCount+1);
		else if (rt->children[1])
			return this->search(str+1, rt->children[1], missCount+1);
		else if (rt->children[3])
			return this->search(str+1, rt->children[3], missCount+1);
		else 
			return false;
	}

	if (*str == 'T')
	{
		if (rt->children[3])
			return this->search(str+1, rt->children[3], missCount);
		
		if (rt->children[0])
			return this->search(str+1, rt->children[0], missCount+1);
		else if (rt->children[1])
			return this->search(str+1, rt->children[1], missCount+1);
		else if (rt->children[2])
			return this->search(str+1, rt->children[2], missCount+1);
		else 
			return false;
	}

	return false;
}

int prefix_trie::getTrieSize()
{
	return this->NodeInTrie;
}
Node* prefix_trie::getBase()
{
	return this->TrieBase;
}

void prefix_trie::DeleteTrie(Node* rt)
{
	if (rt->children[0]==NULL && rt->children[1]==NULL && rt->children[2]==NULL && rt->children[3]==NULL)
	{
		delete rt;

		return;
	}

	if (rt->children[0])
		return this->DeleteTrie(rt->children[0]);
	
	if (rt->children[1])
		return this->DeleteTrie(rt->children[1]);
	
	if (rt->children[2])
		return this->DeleteTrie(rt->children[2]);
	
	if (rt->children[3])
		return this->DeleteTrie(rt->children[3]);
}

prefix_trie::~prefix_trie()
{
	this->DeleteTrie(this->getBase());

	cout << "Trie destroyed" << endl;
}