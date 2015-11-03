#include <stdio.h>


typedef int bit;

/*염색체*/ 
typedef bit chromosome;

/*개체*/
typedef struct{
	chromosome *crms;
	double fitness;
} individual;

/*개체군*/
typedef struct{
	individual *ivd;
	int pop_size;
	int bit_count;
	int data_count;	
} population; 

