#include "BLAST_DB.h"
#define LEN 50
#include <iostream>
#include <queue>
using namespace std;

BLAST_DB::BLAST_DB(char* genome){

    table = new Hashtable(10000000);
    this->genome = genome;

}

void BLAST_DB::disassemble(char* genome, int genome_size){

    char insertion[11];
    int seedsize = 11;

    for(int i = 0; i < genome_size - 49; i++){

        for(int j = 0; j < seedsize; j++){

            insertion[j] = genome[i+j];

        }

        table->insert(insertion, i);

    }

}

int BLAST_DB::ndlmanwun(){

	int score = 0;

    for (int i=0;i<=50;i++){
	
		arrDistances[i][0] = -i;
        arrDistances[0][i] = -i;
    
	}

    int i = 1;
    int j = 1;

	while(i < LEN + 1)
    {

        j = 1;

        while(j < LEN + 1)
        {
        	
            if(arr1[i-1] == arr2[j-1])			
				score = 2;	
			else
				score = -1;
			
            arrDistances[i][j] = max(arrDistances[i-1][j-1] + score, max(arrDistances[i-1][j] + (-1), arrDistances[i][j-1] + (-1)));
        
            j++;
		}
        i++;
    }

    return arrDistances[LEN][LEN];

}

int BLAST_DB::search_in_table(char* query){

    for(int i = 0; i < 50; i++){

        arr1[i] = query[i];

    }

    int maxs = 0;

    char seed[11];
    node *nodes[40];

    for(int i = 0; i < 40; i++){

        for(int j = 0; j < 11; j++){

            seed[j] = query[i+j];

        }

        nodes[i] = table->search_head(seed);

    }

    queue<int> queue;

    for(int i = 0; i < 40; i++){

        node* temp = nodes[i];

        while(temp != NULL){

            queue.push(temp->l); //push location to the queue

            temp = temp->next;
        }

    }

    //empty the queue
    //expand

    while(!queue.empty()){

        int ind = queue.front();
        queue.pop();

        for(int i = 0; i < 50; i++){

            arr2[i] = genome[ind + i];

        }

        int score = ndlmanwun();

        if(score == 100)
            return 100;

        if(score > maxs)
            maxs = score;

    }

    return maxs;

}


BLAST_DB::~BLAST_DB(){

    if(!table)
        delete table;

}
