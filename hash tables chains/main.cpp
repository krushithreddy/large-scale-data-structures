#include <iostream>
#include <fstream>
#include "BLAST_DB.h"
using namespace std;

int size = 0;

char* load_genome(char* filename){

    ifstream file(filename);

    if(!file.is_open()){

        cout << "File error!" << endl;
        exit(0);

    }

    string read;
    int letters = 0;

    getline(file, read); //headerr

    while(getline(file, read)){

        for(int i = 0; read[i] != '\0'; i++){

            letters++;

        }

    }

    file.clear();
    file.seekg(0, ios::beg);

    int index = 0;
    size = letters;
    char *genome = new char[size];

    getline(file, read); //headerr

    while(getline(file, read)){

        for(int i = 0; read[i] != '\0'; i++){

            genome[index++] = read[i];

        }

    }

    return genome;

}

void mutate(char* q){

    for(int i = 0; i < 50; i++){

        if(rand() % 100 > 95){

            int r = rand() % 4;

            switch(r){

                case 0:
                    q[i] = 'A';
                    break;

                case 1:
                    q[i] = 'C';
                    break;

                case 2:
                    q[i] = 'C';
                    break;

                case 3:
                    q[i] = 'T';
                    break;
            
            }

        }

    }

}

void search_random_queries(char* genome, int num, BLAST_DB &db){

    int allowable = (size - 49);
    int perf = 0;
    
    for(int i = 0; i < num; i++){
    
       int random = rand() % allowable;
       char q[50];

       for(int j = 0; j < 50; j++)
            q[j] = genome[random + j];

        if(db.search_in_table(q) == 100)
            perf++;

    }

    cout << "Perfect hits: " << perf << endl;

}

void search_random_queries_error(char* genome, int num, BLAST_DB &db){

    int allowable = (size - 49);
    int perf = 0;
    
    for(int i = 0; i < num; i++){
    
       int random = rand() % allowable;
       char q[50];

       for(int j = 0; j < 50; j++)
            q[j] = genome[random + j];

        mutate(q);

        if(db.search_in_table(q) == 100)
            perf++;

    }

    cout << "Perfect hits: " << perf << endl;

}

void search_random_queries_with_extra_credit(char* genome, int num, BLAST_DB &db){

    int allowable = (size - 49);
    int perf = 0;
    
    for(int i = 0; i < num; i++){
    
       int random = rand() % allowable;
       char q[50];

       for(int j = 0; j < 50; j++)
            q[j] = genome[random + j];

        if(db.search_in_table(q) == 100)
            perf++;

        if(i < 10){

            string alignment = "";

            for(int j = 0; j < 50; j++){

                alignment += "|";

            }

            cout << q << endl << alignment << endl << q << endl << endl;
    
            if(i == 9)
                cout << "Alignment for first 10 queries ^ ^ ^" << endl;

        }


    }

    cout << "Perfect hits: " << perf << endl;



}
void search_hw_dataset(char* filename, int num, BLAST_DB &db){

    ifstream file(filename);
    int perf = 0;

    if(!file.is_open()){

        cout << "File error!" << endl;
        exit(0);

    }

    string read;
    char q[50];

    for(int i = 0; i < num && getline(file, read) && getline(file, read); i++){

        for(int j = 0; j < 50; j++)
            q[j] = read[j];

        if(db.search_in_table(q) == 100)
            perf++; 

    }

    cout << "Perfect hits: " << perf << endl;

}

int main(int arg_count, char** arg_values){

    if(arg_count < 4){

        cout << "Arguments insufficient\n";
        exit(0);

    }

    char* genome = load_genome(arg_values[1]);

    BLAST_DB db(genome);
    db.disassemble(genome, size);

    char part = arg_values[2][0];

    if(part == 'A')
        search_random_queries(genome, atoi(arg_values[3]), db);

    if(part == 'B')
        search_random_queries_error(genome, atoi(arg_values[3]), db);

    if(part == 'C')
        search_hw_dataset(arg_values[4], atoi(arg_values[3]), db);

    if(part == 'D')
        search_random_queries_with_extra_credit(genome, atoi(arg_values[3]), db);


    cout << "Returned 0\n";
    return 0;

}