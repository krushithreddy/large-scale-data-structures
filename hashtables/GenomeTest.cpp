#include <bits/types/clock_t.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>

#include "FASTAreadsetHT.h"

const int sixteen = 16;
const int tenK = 10000;
const int hundredK = 100000;
const int oneM = 1000000;
const int tenM = 10000000;


// Insert a 16-mer at location seq_start to hash table ht.
void add16MerToHash(char *genome_data, int seq_start, FASTAreadset_HT * ht) {
	char subseq[sixteen + 1];
	for (int j = 0; j < sixteen; j++)
		subseq[j] = genome_data[seq_start + j];
	subseq[sixteen] = '\0';
	ht->insertIntoHash(subseq);
}

// Creates a hashtable of size hashtable_size, and adds all 16-mers possible in genome_data to it.
FASTAreadset_HT addAll16MersToHashtable(char *genome_data, int data_size,
		int hashtable_size) {
	FASTAreadset_HT g(hashtable_size);
	for (int i = 0; i < data_size + 1 - sixteen; i++) {
		add16MerToHash(genome_data, i, &g);
	}
	return g;
}


// Generates a random 16-mer sequence consisting of A,C,G,T.
void generateRandom16Mer(char *ret) {
	for (int i = 0; i < sixteen; i++) {

		int index = rand() % 4;
		char ch = '?';
		if (index == 0)
			ch = 'A';
		else if (index == 1)
			ch = 'C';
		else if (index == 2)
			ch = 'G';
		else if (index == 3)
			ch = 'T';
		ret[i] = ch;
	}
	ret[sixteen] = '\0';

}


// Running test to access impact of hash table size.
void runSectionA(char *genome_data, int data_size) {
	printf("Running section A: Access the impact of hash table size.\n");
	clock_t t1, t2, t3, t4, t5;

	// insert values to hashtable of size 10,000.
	t1 = clock();
	FASTAreadset_HT g1 = addAll16MersToHashtable(genome_data, data_size, tenK);

	t2 = clock();
	printf(
			"For 10 thousand size hashtable: Number of collisions = %d, Time taken = %lu ms\n",
			g1.collision, (t2 - t1) / 1000);

	// insert values to hashtable of size 100,000.
	FASTAreadset_HT g2 = addAll16MersToHashtable(genome_data, data_size,
			hundredK);
	t3 = clock();
	printf(
			"For 100 thousand size hashtable: Number of collisions = %d, Time taken = %lu ms\n",
			g2.collision, (t3 - t2) / 1000);

	// insert values to hashtable of size 1,000,000.
	FASTAreadset_HT g3 = addAll16MersToHashtable(genome_data, data_size, oneM);
	t4 = clock();
	printf(
			"For 1 million size hashtable: Number of collisions = %d, Time taken = %lu ms\n",
			g3.collision, (t4 - t3) / 1000);

	// insert values to hashtable of size 10,000,000.
	FASTAreadset_HT g4 = addAll16MersToHashtable(genome_data, data_size, tenM);
	t5 = clock();
	printf(
			"For 10 million size hashtable: Number of collisions = %d, Time taken = %lu ms\n",
			g4.collision, (t5 - t4) / 1000);

	printf("Section A complete.\n\n");

}

// Running test to check searching speed both in case of random 16 mer in genome and completely random search.
void runSectionB(char *genome_data, int data_size) {
	printf(
			"Running section B: Searching speed, Running search in 10 million size hashtable.\n");
	FASTAreadset_HT g = addAll16MersToHashtable(genome_data, data_size, tenM);

	clock_t t1, t2, t3;

	t1 = clock();

	char subseq[sixteen + 1];
	int foundCount1 = 0;
	int foundCount2 = 0;
	int totalCount = oneM;
	for (int i = 0; i < totalCount; i++) {
		int start = (rand() % (data_size - sixteen));
		for (int j = 0; j < sixteen; j++)
			subseq[j] = genome_data[start + j];
		subseq[sixteen] = '\0';
		bool found = g.searchValueInHT(subseq);
		if (found == true)
			foundCount1++;
	}
	t2 = clock();
	printf(
			"Searched 1 million random 16-mers from genome data and found % d of total %d in %lu ms time.\n",
			foundCount1, totalCount, (t2 - t1) / 1000);

	srand(time(NULL));
	for (int i = 0; i < totalCount; i++) {
		generateRandom16Mer(subseq);
		bool found = g.searchValueInHT(subseq);
		if (found == true)
			foundCount2++;
	}
	t3 = clock();
	printf(
			"Searched 1 million completely random 16-mers and found % d of total %d in %lu ms time.\n",
			foundCount2, totalCount, (t3 - t2) / 1000);

	printf("Section B complete.\n\n");

}

// Searching and testing impact of 1% error in genomes.
void runSectionC(char *genome_data, int data_size) {
	printf("Running section C: Trouble with hash table.\n");

	printf("Searching for all the 16-mers in actual genome data.\n");
	FASTAreadset_HT g = addAll16MersToHashtable(genome_data, data_size, 10000000);
	char subseq[sixteen + 1];
	int foundCount1 = 0;
	for (int i = 0; i < data_size + 1 - sixteen; i++) {
		for (int j = 0; j < sixteen; j++)
			subseq[j] = genome_data[i + j];
		subseq[sixteen] = '\0';
		bool found = g.searchValueInHT(subseq);
		if (found == true)
			foundCount1++;
	}
	int totalCount = data_size + 1 - sixteen;
	printf("Searching for all possible 16-mers found % d of total %d\n", foundCount1, totalCount);

	const char *ACGT = "ACGT";
	srand(time(NULL));
	int foundCount2 = 0;
	for (int i = 0; i < data_size + 1 - sixteen; i++) {
		for (int j = 0; j < sixteen; j++) {
			char ch = genome_data[i + j];
			int randm = rand() % 1000000;
			if (randm < 10000) {
				int mv = 1 + (rand() % 3);
				for (int k = 0; k < 4; k++)
					if (ch == ACGT[k])
						ch = ACGT[(k + mv) % 4];
			}
			subseq[j] = ch;
		}
		subseq[sixteen] = '\0';
		bool found = g.searchValueInHT(subseq);
		if (found == true)
			foundCount2++;
	}
	printf("Searching with 1 percent error found %d of total %d\n", foundCount2, totalCount);
	printf("Section C complete.\n\n");
}


// Main function.
// Command to run: \"GenomeTest -f fileName  -s section\". Section can be one of A, B, C or all.
int main(int argc, char *argv[]) {
	const char *fileName = "";
	const char *section = "";
	for (int i = 1; i < argc - 1; i++) {
		if (strcmp(argv[i], "-f") == 0) {
			fileName = argv[i + 1];
		}
		if (strcmp(argv[i], "-s") == 0) {
			section = argv[i + 1];
		}
	}
	const char *usage =
			"Command to run: \"GenomeTest -f fileName  -s section\". Section can be one of A, B, C or all.\n";

	// read input file and populate genome_data and data_size values.
	std::ifstream file;

	std::ifstream f(fileName);
	std::string str;
	if (f) {
		std::ostringstream ss;
		ss << f.rdbuf();
		str = ss.str();
	} else {
		printf("File not found:%s\nUsage:\n%s\n", fileName, usage);
		return 0;
	}
	int index = 0;
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str.at(i) == '\n') {
			index = i;
			break;
		}
	}


	char genome_data[str.length()];
	int data_size = 0;
	for (unsigned int i = index + 1; i < str.length(); i++) {
		char chh = str.at(i);
		if (chh != '\n')
			genome_data[data_size++] = chh;
	}
	genome_data[data_size] = '\0';


	// run different experiments depending on section argument.
	printf("Completed reading genome data of length = %d\n", data_size);
	if (strcmp(section, "A") == 0) {
		runSectionA(genome_data, data_size);
	} else if (strcmp(section, "B") == 0) {
		runSectionB(genome_data, data_size);
	} else if (strcmp(section, "C") == 0) {
		runSectionC(genome_data, data_size);
	} else if (strcmp(section, "all") == 0) {
		runSectionA(genome_data, data_size);
		runSectionB(genome_data, data_size);
		runSectionC(genome_data, data_size);
	} else {
		printf("Incorrect section:%s\nUsage:\n%s\n", section, usage);
	}

	return 0;
}

