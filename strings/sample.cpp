#include "sample.h"

int main(int argc, char* argv[]){
	
	string file = argv[1];
	string problem = argv[2];
	
	FASTAreadset fr(file);
	
	if(problem == "1A"){
		fr.problem1A();	
	}
	else if(problem == "A"){
		fr.problemexampleA();
	}
	else if(problem == "1B"){
		fr.problem1B();
	}
	else if(problem == "B"){
		fr.problemB();
	}
	else if(problem == "C"){
		fr.problemC();
	}
	else{
		cout << "Invalid option" << "\n";
	}
	
	return 0;
}