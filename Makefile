
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

3sum: 3sum.o
	$(CC) $(CFLAGS) -o 3sum 3sum.o

3sum.o: 3sum.cpp
	$(CC) $(CFLAGS) -c 3sum.cpp

clean:
	rm -rf 3sum 3sum.o
