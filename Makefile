CC = g++

all: libMergeSort libInsertSort 

.PHONY: all clean


libInsertSort : InsertSort.o
	ar -r libInsertSort.a InsertSort.o
InsertSort.o : /home/tenywen/my_work/Algorithm/src/InsertSort.c 
	$(CC) -c /home/tenywen/my_work/Algorithm/src/InsertSort.c 

libMergeSort : MergeSort.o
	ar -r libMergeSort.a MergeSort.o
MergeSort.o : /home/tenywen/my_work/Algorithm/src/MergeSort.c /home/tenywen/my_work/Algorithm/src/InsertSort.c 
	$(CC) -c /home/tenywen/my_work/Algorithm/src/MergeSort.c /home/tenywen/my_work/Algorithm/src/InsertSort.c 

libMergeSort : StackSort.o
	ar -r libStackSort.a StackSort.o
StackSort.o : /home/tenywen/my_work/Algorithm/src/StackSort.c /home/tenywen/my_work/Algorithm/src/StackSort.c 
	$(CC) -c /home/tenywen/my_work/Algorithm/src/StackSort.c /home/tenywen/my_work/Algorithm/src/StackSort.c 

clean :
	rm *.o 
