#ifndef FASTAREADSET_H // include guard
#define FASTAREADSET_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h> 
#include <stdlib.h>
//#include <algorithm>


#define fragment_size 51 // repersents the fragment size


#define rid_size 42 // represents the length of the id


#define NoOfDataSets 14 // represents no of datasets

using namespace std;


class FASTAreadset{
	
	private:
		ifstream file;
		string filePath;
		
		
		int t_lines;//
		
		
		char** rid;// rid character pointer to pointer
		
			
		char** fragments; // fragment character pointer to pointer
		
		char** dataset1; // fragment character pointer to pointer in dataset 1
		char** dataset2; // fragment character pointer to pointer in dataset 2
		int flag;
		
	public:
		//Default Constructor
		FASTAreadset();
		
		//Custom constructor taking file path argument
		FASTAreadset(string filePath);
		
		
		void ReadFile(string& filePath, int lines){ // meathod to read the file
			t_lines = lines;
			if(file.is_open()){ // checks weather the file is open
				file.close();
			}
			file.open(filePath.c_str()); // opens the file
			string line;
			int count = 0;
			while(lines > 0){
				getline(file, line); // gets file with the line
				strcpy(rid[count], line.c_str());  
				
				getline(file, line);
				strcpy(fragments[count], line.c_str());
				
				count++;
				lines--;
				
			}
			file.close();
		}
		
		
		void ReadTwoFile(string& filePath, int lines){ // this method is for opening the file and storing the rid and fragnments also fragnments in dataset1 and dataset2
		    cout<<"file reading"<<"\n";
			t_lines = lines;
			if(file.is_open()){
				file.close();
			}
			file.open(filePath.c_str());
			string line;
			int count = 0;
			int i = 0;
			int k = 0;
			int p;
			//int k = 0;
			while(lines > 0){
				// read the string representing header data
				getline(file, line);
				strcpy(rid[count], line.c_str());
				
				getline(file, line);
				strcpy(fragments[count], line.c_str());
				
				 
				 char* str = rid[count];
			   //cout<<dataSet[k]<<"\n";
			   char* separator = "_";
				
			   char* word = strtok(str, separator);// strtok is used for spliting the string with seperator.

				
			
		       //char* word = strtok(dataSet[i], "_");
		       word = strtok(NULL, "_");
		       //int p = word-'0';
		       //cout<<p<<"\n";
		       for(int j =1; j<=2;j++){
		          p = atoi(word); // converts character to integer
		          //cout<<"j:"<<j<<"\n";
		          //cout<<"p:"<<p<<"\n";
		          //cout<<"count:"<<count1<<"\n";
		           if(j==1 && p>=1){
		               strcpy(dataset1[i], fragments[count] ); // storing fragnment in dataset1
		               i=i+1;
					   //cout<<word;
		               word = strtok(NULL, "_");// incrementing the character after the seperator
		           }
		           else if(j==2 && p>=1){
		               //cout<<dataSet[count]<<"\n";
		                strcpy(dataset2[k], fragments[count] ); // storing fragnment in dataset2
		                k = k+1;
		               //cout<<word;
					   //word = strtok(NULL, "_");
		           }
		           else{
		               word = strtok(NULL, "_");
		           }
		           //word = strtok(NULL, "_");
		       }
				count++;
				lines--;
				
			}
			file.close();
			//printDataSet1();
			//printDataSet2();
			
		}
		//This is an overload method that reads n number of lines from file at file path used when using custom constructor
		void ReadFile(int lines){
			ReadFile(filePath, lines);
		}
		
		void ReadTwoFile(int lines){
			ReadTwoFile(filePath, lines);
		}
		
		
		void Uniquefragments(){ // this method is for counting unique fragnment in datasets
			//cout<<"jgyu";
			int set=1;
		   int i = 1;
		   int count1 =0;
		   int count2 =0;
		   int count3 =0;
		   int count4 =0;
		   int count5 =0;
		   int count6 =0;
		   int count7 =0;
		   int count8 =0;
		   int count9 =0;
		   int count10 =0;
		   int count11 =0;
		   int count12 =0;
		   int count13 =0;
		   int count14 =0;
		   int p;
		   int k = 0;
		   
		   while(k<36000000){
			  // cout<<"jhvvyhj";
			   //cout<<dataSet[k]<<"\n";
			   char* str = rid[k];
			   //cout<<dataSet[k]<<"\n";
			   char* separator = "_";
				
			   char* word = strtok(str, separator);

				
			
		       //char* word = strtok(dataSet[i], "_");
		       word = strtok(NULL, "_");
		       //int p = word-'0';
		       //cout<<p<<"\n";
		       for(int j =1; j<=14;j++){
		          p = atoi(word);
		          //cout<<"j:"<<j<<"\n";
		          //cout<<"p:"<<p<<"\n";
		          //cout<<"count:"<<count1<<"\n";
		           if(j==1 && p>=1){
		               count1 = count1+1;
					   //cout<<word;
		               word = strtok(NULL, "_");
		           }
		           else if(j==2 && p>=1){
		               count2 = count2+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==3 && p>=1){
		               count3 = count3+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==4 && p>=1){
		               count4 = count4+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==5 && p>=1){
		               count5 = count5+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==6 && p>=1){
		               count6 = count6+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==7 && p>=1){
		               count7 = count7+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==8 && p>=1){
		               count8 = count8+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==9 && p>=1){
		               count9 = count9+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==10 && p>=1){
		               count10 = count10+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		            else if(j==11 && p>=1){
		               count11 = count11+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		            else if(j==12 && p>=1){
		               count12 = count12+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==13 && p>=1){
		               count13 = count13+1;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==14 && p>=1){
		               count14 = count14+1;
					   //cout<<word;
		               //word = strtok(NULL, "_")
		           }
		           else{
		               word = strtok(NULL, "_");
		           }
		       }
			   k=k+1;
		   }
		    cout<<"the total unique fragments in dataset1:"<<count1<<"\n"; 
		    cout<<"the total unique fragments in dataset2:"<<count2<<"\n"; 
		    cout<<"the total unique fragments in dataset3:"<<count3<<"\n"; 
		    cout<<"the total unique fragments in dataset4:"<<count4<<"\n"; 
		    cout<<"the total unique fragments in dataset5:"<<count5<<"\n"; 
		    cout<<"the total unique fragments in dataset6:"<<count6<<"\n"; 
		    cout<<"the total unique fragments in dataset7:"<<count7<<"\n"; 
		    cout<<"the total unique fragments in dataset8:"<<count8<<"\n"; 
		    cout<<"the total unique fragments in dataset9:"<<count9<<"\n"; 
		    cout<<"the total unique fragments in dataset10:"<<count10<<"\n"; 
		    cout<<"the total unique fragments in dataset11:"<<count11<<"\n"; 
		    cout<<"the total unique fragments in dataset12:"<<count12<<"\n"; 
		    cout<<"the total unique fragments in dataset13:"<<count13<<"\n"; 
		    cout<<"the total unique fragments in dataset14:"<<count14<<"\n"; 
		};
		
		void Totalfragnments(){ // this method is for counting total fragments in each datasets
		    
		    int set=1;
		   int i = 1;
		   int count1 =0;
		   int count2 =0;
		   int count3 =0;
		   int count4 =0;
		   int count5 =0;
		   int count6 =0;
		   int count7 =0;
		   int count8 =0;
		   int count9 =0;
		   int count10 =0;
		   int count11 =0;
		   int count12 =0;
		   int count13 =0;
		   int count14 =0;
		   int p;
		   int k = 0;
		   
		   while(k<36000000){
			  // cout<<"jhvvyhj";
			   //cout<<dataSet[k]<<"\n";
			   char* str = rid[k];
			   //cout<<dataSet[k]<<"\n";
			   char* separator = "_";
				
			   char* word = strtok(str, separator);

				
			
		       //char* word = strtok(dataSet[i], "_");
		       word = strtok(NULL, "_");
		       //int p = word-'0';
		       //cout<<p<<"\n";
		       for(int j =1; j<=14;j++){
		          p = atoi(word);
		          //cout<<"j:"<<j<<"\n";
		          //cout<<"p:"<<p<<"\n";
		          //cout<<"count:"<<count1<<"\n";
		           if(j==1 && p>=1){
		               count1 = count1+p;
					   //cout<<word;
		               word = strtok(NULL, "_");
		           }
		           else if(j==2 && p>=1){
		               count2 = count2+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==3 && p>=1){
		               count3 = count3+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==4 && p>=1){
		               count4 = count4+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==5 && p>=1){
		               count5 = count5+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==6 && p>=1){
		               count6 = count6+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==7 && p>=1){
		               count7 = count7+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==8 && p>=1){
		               count8 = count8+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==9 && p>=1){
		               count9 = count9+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==10 && p>=1){
		               count10 = count10+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		            else if(j==11 && p>=1){
		               count11 = count11+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		            else if(j==12 && p>=1){
		               count12 = count12+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==13 && p>=1){
		               count13 = count13+p;
		               //cout<<word;
					   word = strtok(NULL, "_");
		           }
		           else if(j==14 && p>=1){
		               count14 = count14+p;
					   //cout<<word;
		               //word = strtok(NULL, "_")
		           }
		           else{
		               word = strtok(NULL, "_");
		           }
		       }
			   k=k+1;
		   }
		    cout<<"the total fragments in dataset1:"<<count1<<"\n"; 
		    cout<<"the total fragments in dataset2:"<<count2<<"\n"; 
		    cout<<"the total fragments in dataset3:"<<count3<<"\n"; 
		    cout<<"the total fragments in dataset4:"<<count4<<"\n"; 
		    cout<<"the total fragments in dataset5:"<<count5<<"\n"; 
		    cout<<"the total fragments in dataset6:"<<count6<<"\n"; 
		    cout<<"the total fragments in dataset7:"<<count7<<"\n"; 
		    cout<<"the total fragments in dataset8:"<<count8<<"\n"; 
		    cout<<"the total fragments in dataset9:"<<count9<<"\n"; 
		    cout<<"the total fragments in dataset10:"<<count10<<"\n"; 
		    cout<<"the total fragments in dataset11:"<<count11<<"\n"; 
		    cout<<"the total fragments in dataset12:"<<count12<<"\n"; 
		    cout<<"the total fragments in dataset13:"<<count13<<"\n"; 
		    cout<<"the total fragments in dataset14:"<<count14<<"\n"; 
		};
		
		
		void DeleteAllocation(){ // de alocating the array for problemA
			cout << "De-allocation started"<<"\n";
			//PrintCurrentTime();
			
			
			delete[] rid;
			delete[] fragments;
		
			
			cout << "Cleared memory"<<"\n";	
			//PrintCurrentTime();		
		}
		
		void DeleteAllocation2(){ // de-allocation method for problem B and C
			cout << "De-allocation started: "<<"\n";
	
			delete[] fragments;
			delete[] rid;
			delete[] dataset1;
			delete[] dataset2;
			
			cout << "memory cleared"<<"\n";	
		}
		
		void problem2thousand(){//method for checking 1000 lines
		    cout<<"thousand files"<<"\n";
		    int count=0;
		    for(int i=0; i<1000; i++){
		        //int k =0;
	
		        for(int j=0; j<1000; j++){
		            //cout<<"djnfijchn"<<"\n";
		            //int res;
		            
		            //res = strcmp(dataset1[i],dataset2[j]);
		            if(dataset1[i]==dataset2[j]){
		                count=count+1;
		            }
		        }
		    }
		    cout<<"number of fragments dataset1 in dataset2 is: "<<count<<"\n";
		}
		
		void problem2tenthousand(){ //method for checking 10000 lines
		    cout<<"ten thousand files"<<"\n";
		    int count=0;
		    for(int i=0; i<10000; i++){
		        //int k =0;
	
		        for(int j=0; j<10000; j++){
		            //int res=0;
		            
		            //res = strcmp(dataset1[i],dataset2[j]);
		            if(dataset1[i]==dataset2[j]){
		                count=count+1;
		            }
		        }
		    }
		    cout<<"number of fragments dataset1 in dataset2 is: "<<count<<"\n";
		}
		
		void problem2hunderedthousand(){ //method for checking 100000 lines
		    cout<<"hundered thousand files"<<"\n";
		    int count=0;
		    for(int i=0; i<100000; i++){
		        //int k =0;
	
		        for(int j=0; j<100000; j++){
		            //int res=0;
		            
		            //res = strcmp(dataset1[i],dataset2[j]);
		            if(dataset1[i]==dataset2[j]){
		                count=count+1;
		            }
		        }
		    }
		    cout<<"number of fragments dataset1 in dataset2 is: "<<count<<"\n";
		}
		
		void problem2onemillion(){ ////method for checking 1000000 lines
		    cout<<"one million files"<<"\n";
		    int count=0;
		    for(int i=0; i<1000000; i++){
		        //int k =0;
	
		        for(int j=0; j<1000000; j++){
		            //int res=0;
		            
		            //res = strcmp(dataset1[i],dataset2[j]);
		            if(dataset1[i]==dataset2[j]){
		                count=count+1;
		            }
		        }
		    }
		    cout<<"number of fragments dataset1 in dataset2 is: "<<count<<"\n";
		}
		
		
		void problem1A(){
		    flag=0;
		    cout << "Problem 1A has started: "<<"\n";
			clock_t start = clock();
			rid = new char*[36000000];
			fragments = new char*[36000000];		
			for(int i = 0; i < 36000000; i++){
				fragments[i] = new char[fragment_size];
				rid[i] = new char[rid_size];
			}
			ReadFile(36000000);
		    Uniquefragments();
		    
		    //Totalfragnments();
		    
		    DeleteAllocation();
			//cout << "Successfully initialized with first 10 million reads at: ";
			cout.precision(2);
			cout<<"time taken for problem1A is ";
            cout << fixed <<  float(clock() - start)/CLOCKS_PER_SEC <<" seconds" << endl;
		}
		
		void problem1B(){
		    flag=0;
		    cout << "Problem 1B has started: "<<"\n";
			clock_t start = clock();
			rid = new char*[36000000];
			fragments = new char*[36000000];		
			for(int i = 0; i < 36000000; i++){
				fragments[i] = new char[fragment_size];
				rid[i] = new char[rid_size];
			}
			ReadFile(36000000);
		    //Uniquefragments();
		    
		    Totalfragnments();
		    
		    DeleteAllocation();
			//cout << "Successfully initialized with first 10 million reads at: ";
			cout.precision(2);
			cout<<"time taken for problem1B is ";
            cout << fixed <<  float(clock() - start)/CLOCKS_PER_SEC <<" seconds" << endl;
		}
		
		void problemB(){
		    flag =1;
		    
		    cout <<"\n"<< "Problem B has started: "<<"\n";
		    cout << "comparing 1000 sequences"<<"\n";
		    
			clock_t start = clock();
			rid = new char*[1000];
			fragments = new char*[1000];	
			dataset1 = new char*[1000];
			dataset2 = new char*[1000];	
			for(int i = 0; i < 1000; i++){
				fragments[i] = new char[fragment_size];
				rid[i] = new char[rid_size];
				dataset1[i] = new char[fragment_size];
				dataset2[i] = new char[fragment_size];
				
			}
			ReadTwoFile(1000);
			//ReadFile(360000000);
			problem2thousand();
		    DeleteAllocation2();
			//cout << "Successfully initialized with first 10 million reads at: ";
			cout.precision(2);
			cout<<"time taken for problem B for thousand files is ";
            cout << fixed <<  float(clock() - start)/CLOCKS_PER_SEC <<" seconds" << endl;
            
            cout <<"\n"<< "Now comparing 10000 sequences"<<"\n";
		    
			clock_t start1 = clock();
			rid = new char*[10000];
			fragments = new char*[10000];	
			dataset1 = new char*[10000];
			dataset2 = new char*[10000];	
			for(int i = 0; i < 10000; i++){
				fragments[i] = new char[fragment_size];
				rid[i] = new char[rid_size];
				dataset1[i] = new char[fragment_size];
				dataset2[i] = new char[fragment_size];
				
			}
			ReadTwoFile(10000);
			
			problem2tenthousand();
		    DeleteAllocation2();
			
			cout<<"time taken for problem B for 10000 thousand files is ";
            cout << fixed <<  float(clock() - start1)/CLOCKS_PER_SEC <<" seconds" << endl;
            
            cout <<"\n"<< "Now comparing 100000 sequences"<<"\n";
            clock_t start2 = clock();
			rid = new char*[100000];
			fragments = new char*[100000];	
			dataset1 = new char*[100000];
			dataset2 = new char*[100000];	
			for(int i = 0; i < 100000; i++){
				fragments[i] = new char[fragment_size];
				rid[i] = new char[rid_size];
				dataset1[i] = new char[fragment_size];
				dataset2[i] = new char[fragment_size];
				
			}
			ReadTwoFile(100000);
			
			problem2hunderedthousand();
		    DeleteAllocation2();
			
			cout<<"time taken for problem B for 100000 thousand files is ";
            cout << fixed <<  float(clock() - start2)/CLOCKS_PER_SEC <<" seconds" << endl;
            
            cout <<"\n"<< "Now comparing 1000000 sequences"<<"\n";
            clock_t start6 = clock();
			rid = new char*[1000000];
			fragments = new char*[1000000];	
			dataset1 = new char*[1000000];
			dataset2 = new char*[1000000];	
			for(int i = 0; i < 1000000; i++){
			fragments[i] = new char[fragment_size];
				rid[i] = new char[rid_size];
				dataset1[i] = new char[fragment_size];
				dataset2[i] = new char[fragment_size];
				
			}
			ReadTwoFile(1000000);
			
			problem2onemillion();
		    DeleteAllocation2();
			
			cout<<"time taken for problem B for 1000000 thousand files is ";
            cout << fixed <<  float(clock() - start6)/CLOCKS_PER_SEC <<" seconds" << endl;
            
		    
		}
		
		
        
        int binarySearch(char** arr, char* str, int lowest, int highest) {
            int middle;
	// Repeat until the pointers lowest and highest meet each other
          while (lowest <= highest) {
            middle = lowest + (highest - lowest) / 2;
        
            if (arr[middle] == str)// checks weather middle value is search
              return 1;
        
            if (arr[middle] < str)// if middle value is less than the string
              lowest = middle + 1;
        
            else
              highest = middle - 1;
          }
        
          return -1;// returns -1 is it found nothing
        }
			
		void BubbleSort( char **arr, int n)
        {
        	    int result;    
        	
        		for ( int i = 0; i < n - 1 ; ++i ) // takes first array
        		{
        					
        			for ( int j = 0; j < n - 1 - i; ++j ) // takes second array
        			{		
        				             
        				result = strcmp (arr[j], arr[j+1]);	// runs camparision between first and second element
        			              
        				if (result > 0)		   
        					swap ( arr[j] , arr[j+1] );		// swap first and second element if the result is greated than 0
        			}		 	
        		}
        }
		void sorting_arr(){
		    
		    cout<<"sorting the array"<<"\n";
		    cout<<t_lines<<"\n";
		    
		    
		    BubbleSort(dataset2,t_lines);
		    
		    cout<<"sorting array is done"<<"\n";
		}
		
		void problemC(){
		    flag =1;
		    cout<<"problemC has started"<<"\n";
		    
            
            cout <<"\n"<< "Now comparing 1000 sequences"<<"\n";
            clock_t start3 = clock();
			rid = new char*[1000];
			fragments = new char*[1000];	
			dataset1 = new char*[1000];
			dataset2 = new char*[1000];	
			for(int i = 0; i < 1000; i++){
			    fragments[i] = new char[fragment_size];
				rid[i] = new char[rid_size];
				dataset1[i] = new char[fragment_size];
				dataset2[i] = new char[fragment_size];
				
			}
			ReadTwoFile(1000);
			
			
			cout<<"sorting dataset2"<<"\n";
			sorting_arr();
			//printDataSet1();
			//cout<<"dataset2"<<"\n";
			//printDataSet2();
			cout<<"now doing binary search"<<"\n";
			
			int count = 0;
			for(int i=0; i>t_lines;i++){
			    int result = binarySearch(dataset2, dataset1[i], 0, t_lines);
			    if (result>=0){
			    count= count+1;    
			    }
			}
			cout<<"number of sequences of dataset1 in dataset2 "<<count<<"\n";
			
			
			
		    //DeleteAllocation2();
			
			cout<<"time taken for problem C to run 1000 files is ";
            cout << fixed <<  float(clock() - start3)/CLOCKS_PER_SEC <<" seconds" << endl;
		
		
		    cout <<"\n"<< "Now comparing 10000 sequences"<<"\n";
            clock_t start4 = clock();
			rid = new char*[10000];
			fragments = new char*[10000];	
			dataset1 = new char*[10000];
			dataset2 = new char*[10000];	
			for(int i = 0; i < 10000; i++){
			fragments[i] = new char[fragment_size];
				rid[i] = new char[rid_size];
				dataset1[i] = new char[fragment_size];
				dataset2[i] = new char[fragment_size];
				
			}
			ReadTwoFile(10000);
			
			
			cout<<"sorting dataset2 array"<<"\n";
			sorting_arr();
			
			count = 0;
			for(int i=0; i>t_lines;i++){
			    int result = binarySearch(dataset2, dataset1[i], 0, t_lines);
			    if (result>=0){
			    count= count+1;    
			    }
			}
			cout<<"the total number of sequences of dataset1 in dataset2 "<<count<<"\n";
			
			
		    //DeleteAllocation2();
			
			cout<<"time taken for problem C to run 10 thousand files is ";
            cout << fixed <<  float(clock() - start4)/CLOCKS_PER_SEC <<" seconds" << endl;
		
		
		cout <<"\n"<< "Now comparing 100 thousand sequences"<<"\n";
            clock_t start5 = clock();
			rid = new char*[100000];
			fragments = new char*[100000];	
			dataset1 = new char*[100000];
			dataset2 = new char*[100000];	
			for(int i = 0; i < 100000; i++){
				fragments[i] = new char[fragment_size];
				rid[i] = new char[rid_size];
				dataset1[i] = new char[fragment_size];
				dataset2[i] = new char[fragment_size];
				
			}
			ReadTwoFile(100000);
			
		
			cout<<"sorting dataset2 array"<<"\n";
			sorting_arr();
			
			count = 0;
			for(int i=0; i>t_lines;i++){
			    int result = binarySearch(dataset2, dataset1[i], 0, t_lines);
			    if (result>=0){
			    count= count+1;    
			    }
			}
			cout<<"number of fragnments of dataset1 in dataset2 is: "<<count<<"\n";
			
			
		    //DeleteAllocation2();
			
			cout<<"time taken for problem C for 100 thousand files is ";
            cout << fixed <<  float(clock() - start5)/CLOCKS_PER_SEC <<" seconds" << endl;
            
		}
		
		//Destructor
		~FASTAreadset(){
		    if(flag==1){
		        DeleteAllocation2();
		    }
		    else{
		        DeleteAllocation();
		    }
		}
};

//Custom constructor implementation: setting private variable for file path
FASTAreadset::FASTAreadset(string path){
	filePath = path;
}

//Default constructor implementation: doing nothing
FASTAreadset::FASTAreadset(){
}

#endif