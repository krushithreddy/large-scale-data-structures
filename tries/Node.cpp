#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{	
	this->height = 0;
	this->Value = '-';

	for (int i = 0; i < 4; i++)			// initializing children to NULL for newly created node
	{
		this->children[i] = NULL;
	}
}