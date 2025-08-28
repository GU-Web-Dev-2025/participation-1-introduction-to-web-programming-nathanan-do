all:
	g++ -Wall --std=c++11 main.cpp LinkedList.cpp -o LinkedListProgram
	./LinkedListProgram

test:
	g++ -Wall --std=c++11 maintest.cpp LinkedList.cpp -o LinkedListProgram
	./LinkedListProgram

memoryCheck:
	g++ -Wall --std=c++11 maintest.cpp LinkedList.cpp -o LinkedListProgram
	valgrind --leak-check=full ./LinkedListProgram