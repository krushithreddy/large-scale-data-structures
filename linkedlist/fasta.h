#ifndef FASTAreadset_LL_H // include guard
#define FASTAreadset_LL_H

#include <iostream>
#include <fstream>
#include <time.h> 
#include <math.h>
#include <string.h>

using namespace std;

//structure for storing secuences
struct Node{
	char line[51];
	struct Node* next; // pointer to next node
};

class FASTAreadset_LL{
			
	public:
	
		ifstream file;
		
		char* filePath;
		
		//pointer to start node
		Node* head;
		
		//Default Constructor
		FASTAreadset_LL(){
			head = NULL;
			
		}
		
		//Custom constructor 
		FASTAreadset_LL(char* path){
			filePath = path;
			head = NULL;
			
		}
	
	    //Copy constructor
		FASTAreadset_LL(const FASTAreadset_LL &obj){
			head = NULL;
			if(file.is_open()){
				file.close();
			}
			
			file.open(filePath);
			
			string line;
			int count = 0;
			Node* curr_node = NULL; //keeping track of current node
			
			while(getline(file, line)){
				
				//read the string representing genomic sequence
				getline(file, line);
				
				Node* temp_node = new Node;
			    
			    for(int k = 0; k < 50; k++){
	    		 	(temp_node -> line)[k] = (line.c_str())[k];
				}
	    	    (temp_node -> line)[50] = '\0';

			    temp_node -> next = NULL;
				
				if(curr_node != NULL){
					curr_node -> next = temp_node;
				}
				
				curr_node = temp_node;
				
				//if it's the first node then pointing head to it
				if(count == 0){
					head = temp_node;
				}
				
				count++;
				//lines--;
				
			}
			cout<<'\n'<<"fragnments in linked list: "<<count<<'\n';
			file.close();
		}
		
		void ReadFile(char* filePath){
			
			if(file.is_open()){
				file.close();
			}
			
			file.open(filePath);
			
			string line;
			int count = 0;
			Node* curr_node = NULL; //keeping track of current node
			
			while(getline(file, line)){
				
				
				//read the string representing genomic sequence
				getline(file, line);
				
				Node* temp_node = new Node;
			    
			    for(int k = 0; k < 50; k++){
	    		 	(temp_node -> line)[k] = (line.c_str())[k];
				}
	    	    (temp_node -> line)[50] = '\0';

			    temp_node -> next = NULL;
				
				if(curr_node != NULL){
					curr_node -> next = temp_node;
				}
				
				curr_node = temp_node;
				
				//if it's the first node then pointing head to it
				if(count == 0){
					head = temp_node;
				}
				
				count++;
				//lines--;
				
			}
			cout<<'\n'<<"fragnments in linked list: "<<count<<'\n';
			file.close();
		}
		
	
		
		void problemA(){
			
			cout << "Reading 36 Million fragments"<<'\n';
			
			ReadFile(filePath);
			search();
		}
		
		
		
		
		
		int linearsearch(char seq[]){
		    int i;
			Node* current = head;
		    while((current->next)!=NULL){
		        
		        if(strcmp(seq,current->line)==0){//comparing 50mer and fragment from linked list
		            return i;
		        }
		        else{
		            current = current->next;
		            i++;
		        }
		    }
		    return -1;
		    
		}

		void search(){
			char seq1[] = "CTAGGTACATCCACACACAGCAGCGCATTATGTATTTATTGGATTTATTT";
			char seq2[] = "GCGCGATCAGCTTCGCGCGCACCGCGAGCGCCGATTGCACGAAATGGCGC";
			char seq3[] = "CGATGATCAGGGGCGTTGCGTAATAGAAACTGCGAAGCCGCTCTATCGCC";
			char seq4[] = "CGTTGGGAGTGCTTGGTTTAGCGCAAATGAGTTTTCGAGGCTATCAAAAA";
			char seq5[] = "ACTGTAGAAGAAAAAAGTGAGGCTGCTCTTTTACAAGAAAAAGTNNNNNN";
			int position;
			
			
			position = linearsearch(seq1);
			if(position > -1){
				cout <<"\n"<< seq1<<" Found at position " << position + 1 << " in fasta dataset" << "\n";
			    }
			else{
				cout <<"\n" <<seq1<< " Not found in fasta dataset" << "\n";
			}
			
			
			position = linearsearch(seq2);
			if(position > -1){
				cout <<"\n"<<seq2<< "Found at position " << position + 1 << " in fasta dataset" << "\n";
			    }
			else{
				cout <<"\n" << seq2<<" Not found in fasta dataset" << "\n";
				}
				
			position = linearsearch(seq3);
			if(position > -1){
				cout <<"\n"<<seq3<< "Found at position " << position + 1 << " in fasta dataset" << "\n";
			}
			else{
				cout <<"\n" <<seq3<<" Not found in fasta dataset" << "\n";
				}
			
			position = linearsearch(seq4);
			if(position > -1){
				cout <<"\n"<<seq4<< "Found at position " << position + 1 << " in fasta dataset" << "\n";
			}
			else{
				cout <<"\n" <<seq4<< " Not found in fasta dataset" << "\n";
			}
			
			position = linearsearch(seq5);
			if(position > -1){
				cout <<"\n"<<seq5<< "Found at position " << position + 1 << " in fasta dataset" << "\n";
			}
			else{
				cout <<"\n" <<seq5<< " Not found in fasta dataset" << "\n";
			}
		}
		
		
		
		void problem1B(char* filepath){
		    ReadGenomeData(filePath);
		}
		
		void ReadGenomeData(char* filePath){
			ifstream file;
			file.open(filePath);
			
			cout << "reading genome dataset"<<'\n';
			

			char c = '\0';
			int count = 0;
			int records = 0;
			Node* current;
			
			//skipping the first line
			while(c != '\n'){
				file.get(c);	
			}
			
  			while (file.get(c)){
  				if(c == 'A' || c == 'C' || c == 'G' || c == 'T' || c == 'N'){
  					count++;
  				}
  				if(count==50){
  				    records++;
  					count=49;
  				}
				
			}         
			file.close();
			
			cout << "Total " << records << " 50charcter sequences found at genome dataset"<<'\n';
		}
		
		void problemAA(){
			
			cout << "Reading 36 million fragments"<<'\n';
			ReadFile(filePath);
		}
		
		
		
		void problem2B(char* genome, int size){
		    problemAA();
		    clock_t start = clock();
		    genomeSearch(genome,size);
		    cout.precision(2);
			cout<<"time taken for problem2B with "<< size<<" 50mers is ";
            cout << fixed <<  float(clock() - start)/CLOCKS_PER_SEC <<" seconds" << endl;
		}
		
		void genomeSearch(char* genome, int size){
		    ifstream file;
			file.open(genome);
			
			cout << "Reading Genome data "<<'\n';
			
			
			char temp[50];
			char c = '\0';
			int count = 0;
		    int records = 0;
		    int found;
		    int m=0;

			
			while(c != '\n'){
				file.get(c);	
			}
			
  			while (file.get(c) && m<=size){
  			    	if(c == 'A' || c == 'C' || c == 'G' || c == 'T' || c == 'N'){
  					temp[count] = c;
  					count++;
  			    	if(count == 50){
  						count = 49;
  						m++;
						found = linearsearch(temp);
						for(int i = 1; i < 50; i++){
							temp[i - 1] = temp[i];
						}
  						if(found>0){
  						    records++;
  						}
  						
  			    	}
  			}
		}
		cout<<"The total "<<size<<" 50mers matched in 36 million is "<<records<<"\n"<<"\n";
	
		file.close();
		}
		
		
		//Destructor
		~FASTAreadset_LL(){
			DeleteAllocation();
		}
		
		//Method for deleting memory used by arrays
		void DeleteAllocation(){
			cout << " deallocation started "<<'\n';
			
			if(head != NULL){
				Delete(head);
			}
			
			cout << "Successfully de-allocated the memory used for storing linkedlist"<<'\n';	
		}


		void Delete(Node* curr_node){
			while(curr_node != NULL){
				delete[] curr_node;
				curr_node = curr_node -> next;
			}
		}
};



#endif

