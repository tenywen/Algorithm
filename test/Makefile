CC = gcc

all: test_InsertSort test_MergeSort

.PHONY: all clean

test_InsertSort :  test_InsertSort.c
	$(CC) test_InsertSort.c -L/home/tenywen/my_work/Algorithm/lib -lInsertSort -o test_InsertSort

test_MergeSort :  test_MergeSort.c
	$(CC) test_MergeSort.c -L/home/tenywen/my_work/Algorithm/lib -lMergeSort -lInsertSort -o test_MergeSort

clean : 
	rm test_InsertSort test_MergeSort
