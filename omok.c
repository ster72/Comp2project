#include "common.h"

population* create_population(int pop_size, int bit_count, int data_count);
void free_population(population *pop);
int rand_between(int a, int b);
void rand_population(population *pop);

int main(){
	int i, j;
	int pop_size = 100;
	int bit_count = 2;
	int data_count = 2;
	population *pop = create_population(pop_size, bit_count, data_count);

	rand_population(pop);

	for(i = 0; i < pop->pop_size; i++){
		for(j = 0; j < bit_count; j++){
			if(j==2)
			 printf(" ");
			printf("%d ", pop->ivd[i].crms[j]);
		}
		printf("\n");
	}

	free_population(pop);
	printf("아무키나 누르십시오...");getchar();
	return 0; 
}
