#ifndef _COMMON_H_
#define _COMMON_H_
#include <stdbool.h>
#define MAX(a,b) ((a > b) ? a : b) 
#define iFLOOR(a) (int(a))

//float有效位为6-7，double有效位为16
#define iCEIL(a) (( float(a) - int(a) > 0.0) ? int(a + 1) : int(a)) 
#define SWAP(a,b) do\
					{\
						a = a^b;\
						b = a^b;\
						a = a^b;\
					}while(0)
#endif
