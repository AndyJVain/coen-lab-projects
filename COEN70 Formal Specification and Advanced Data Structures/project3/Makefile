CC	= g++

all:		seq seq_op s_seq

seq:		sequence_test.cpp sequence.cpp sequence.h
		$(CC) -o sequence sequence_test.cpp sequence.cpp

seq_op:		sequence_test_op.cpp sequence.cpp sequence.h
		$(CC) -o sequence_op sequence_test_op.cpp sequence.cpp

s_seq: 		s_sequence_test.cpp sorted_sequence.cpp sorted_sequence.h
		$(CC) -o sorted_sequence s_sequence_test.cpp sorted_sequence.cpp

clean:;		rm sequence sequence_op sorted_sequence
