hepsi: compile link run

compile:
	g++ -c -I ./include/ ./src/FileManager.cpp -o ./lib/FileManager.o
	g++ -c -I ./include/ ./src/StringManager.cpp -o ./lib/StringManager.o
	g++ -c -I ./include/ ./src/StackNode.cpp -o ./lib/StackNode.o
	g++ -c -I ./include/ ./src/Stack.cpp -o ./lib/Stack.o
	g++ -c -I ./include/ ./src/AvlNode.cpp -o ./lib/AvlNode.o
	g++ -c -I ./include/ ./src/Avl.cpp -o ./lib/Avl.o
	g++ -c -I ./include/ ./src/ListNode.cpp -o ./lib/ListNode.o
	g++ -c -I ./include/ ./src/LinkedList.cpp -o ./lib/LinkedList.o
	g++ -c -I ./include/ ./src/main.cpp -o ./lib/main.o
	g++ -c -I ./include/ ./src/LinkedList.cpp -o ./lib/LinkedList.o
link:
	g++ ./lib/FileManager.o ./lib/StringManager.o ./lib/StackNode.o ./lib/Stack.o ./lib/AvlNode.o ./lib/Avl.o ./lib/ListNode.o ./lib/LinkedList.o ./lib/main.o -o ./bin/Program
run:
	./bin/Program