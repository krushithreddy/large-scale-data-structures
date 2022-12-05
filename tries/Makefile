output: Node.o prefix_trie.o main.o
	g++ -o run Node.o prefix_trie.o main.o

Node.o: Node.h Node.cpp
	g++ -c Node.cpp

prefix_trie.o: prefix_trie.cpp prefix_trie.h
	g++ -c prefix_trie.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm run Node.o prefix_trie.o main.o