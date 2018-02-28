CC	= g++

all:		poly1 poly2 poly1_op poly2_op

poly1:		poly1_test.cpp poly1.cpp poly1.h
		$(CC) -o poly1 poly1_test.cpp poly1.cpp

poly1_op:	poly1_test_op.cpp poly1.cpp poly1.h
		$(CC) -o poly1_op poly1_test_op.cpp poly1.cpp

poly2:		poly2_test.cpp poly2.cpp poly2.h
		$(CC) -o poly2 poly2_test.cpp poly2.cpp

poly2_op:	poly2_test_op.cpp poly2.cpp poly2.h
		$(CC) -o poly2_op poly2_test_op.cpp poly2.cpp

clean:;		rm poly1 poly2 poly1_op poly2_op