DBG=-g
OPTS=$(DBG) -Wall -ansi -pedantic -std=c++17

CC=g++ -c $(OPTS)
LN=g++

OBJS=SplayNode.o SplayTree.o main.o

splay: $(OBJS)
	$(LN) -o splay $(OBJS)

SplayNode.o: SplayNode.cpp SplayNode.hpp
	$(CC) SplayNode.cpp

SplayTree.o: SplayTree.cpp SplayTree.hpp SplayNode.hpp
	$(CC) SplayTree.cpp

main.o: main.cpp SplayTree.hpp SplayNode.hpp
	$(CC) main.cpp

clean:
	/bin/rm -f $(OBJS) splay *~
