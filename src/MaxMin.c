/*
*
*       @max min for int
*       @O(n)
*       @
*       @
*       @
*/

#include <stdarg.h>
#include <stdio.h>
int Max(int n, ...) {
    // n为参数个数
    int argc = n;
    int argv = 0;
    int max = 0; 
    va_list arg_ptr;
    va_start(arg_ptr,n);
    do {
        argv = va_arg(arg_ptr,int);
        if (argc == n) {
            max = argv;
        } else {
            if(max < argv) {
                max = argv; 
            } 
        }
        argc --;
    }while(argc != 0);
    va_end(arg_ptr);
    return max;
}

int Min(int n, ...) {
    // n为参数个数
    int argc = n;
    int argv = 0;
    int min = 0; 
    va_list arg_ptr;
    va_start(arg_ptr,n);
    do {
        argv = va_arg(arg_ptr,int);
        if (argc == n) {
            min = argv;
        } else {
            if(min > argv) {
                min = argv; 
            } 
        }
        argc --;
    }while(argc != 0);
    va_end(arg_ptr);
    return min;
}
