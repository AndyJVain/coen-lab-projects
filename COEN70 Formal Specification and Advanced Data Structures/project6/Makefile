CC	= g++

all:		sequence node

sequence:	sequence.h node.h sequence_test.cpp sequence.cpp node.cpp
		$(CC) -o sequence sequence_test.cpp sequence.cpp node.cpp

node:		node_test.cpp node.cpp node.h
		$(CC) -o node node_test.cpp node.cpp

clean:;		rm -f sequence