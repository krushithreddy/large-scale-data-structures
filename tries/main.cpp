#include <iostream>
#include "prefix_trie.h"
#include <fstream>
#include <cstdlib>

using namespace std;

char* ReadFile(string name)		// read data from file
{
	fstream input;
	char* data;
	int dataSize = 0, c=0;
	string readLine;

	input.open(name, ios::in);

	if(!input.is_open())
	{
        cout  << name << " file path is invalid." << endl;
        exit(-1);
    }

	while (getline(input, readLine))
	{
		if (c > 0)
			dataSize += readLine.length();

		c++;		
	}

	cout << "Dataset size is " << dataSize << endl;

	data = new char[dataSize];
	dataSize = 0;
	c = 0;

    input.clear();
    input.seekg(0, ios::beg);

	while (getline(input, readLine))
	{
		if (c > 0)
		{
			for (int i = 0; readLine[i]!='\0'; i++)
			{
				data[dataSize] = readLine[i];
				dataSize++;
			}
		}

		c++;		
	}

	input.close();

	return data;
}

int main(int count, char** arguments)
{
	srand(time(0));

	if (count < 4)			// error check for less number of arguments passed
	{
		cout << "Argument error" << endl;
		return -1;
	}

	if (arguments[2][0] == 'a')			// execution of part a
	{
		cout << "....running part A" << endl;

		char* gene = ReadFile(arguments[1]);

		int i=0, srch = 0;
		char find[36] = {' '};

		while (gene[i] != '\0')
		{
			i++;
		}cout << endl;

		prefix_trie objct(gene, atoi(arguments[3]), 0);

		cout << "Number of Nodes created in trie are " << objct.getTrieSize() << endl;

		for (int j = 0; j < i; j++)
		{
			for (int a = 0; a < 36; a++)
				find[a] = ' ';

			for (int a = 0; a < 36; a++)
				find[a] = gene[j + a];

			Node* rt = objct.getBase();	

			if (objct.search(find, rt, 0))
				srch++;
		}
		
		cout << "Total searches found -> " << srch << endl;
	}
	else if (arguments[2][0] == 'b')			// execution of part a
	{
		cout << "....running part B" << endl;

		char* gene = ReadFile(arguments[1]);

		int i=0, srch = 0;
		char find[36] = {' '};

		while (gene[i] != '\0')
		{
			i++;
		}cout << endl;

		prefix_trie objct(gene, atoi(arguments[3]), 1);

		cout << "Number of Nodes created in trie are " << objct.getTrieSize() << endl;

		for (int j = 0; j < i; j++)
		{
			for (int a = 0; a < 36; a++)
				find[a] = ' ';

			for (int a = 0; a < 36; a++)
				find[a] = gene[j + a];

			Node* rt = objct.getBase();	

			if (objct.search(find, rt, 0))
				srch++;
		}
		
		cout << "Total searches found -> " << srch << endl;
	}
	else			// execution error for wrong part entered
		cout << "execution error" << endl;

	return 0;
}

// ./exe file part query
// SARS_COV2.fasta