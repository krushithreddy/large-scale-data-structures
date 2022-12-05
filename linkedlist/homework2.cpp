#include "fasta.h"

int main(int argc, char* argv[]){
    char* file = argv[1];
	char* genFile = argv[3];
	string problem = argv[2];
	int size = atoi(argv[4]);
	cout<<size<<'\n';
	FASTAreadset_LL fr(file);
	
	if (problem[0] == 'A'){
	    fr.problemA();
	}
	if (problem == "1B"){
	    fr.problem1B(file);
	};
	if (problem == "2B"){
	    fr.problem2B(genFile,size);
	};
}