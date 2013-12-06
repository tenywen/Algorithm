CC = gcc

.PHONY: clean

libInsertSort : InsertSort.o
	ar -r libInsertSort.a InsertSort.o
InsertSort.o : /home/tenywen/my_work/Algorithm/src/InsertSort.c 
	$(CC) -c /home/tenywen/my_work/Algorithm/src/InsertSort.c
clean :
	rm *.o 
