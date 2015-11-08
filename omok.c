#include "common.h"

population* create_population(int pop_size, int bit_count, int data_count);
void free_population(population *pop);
int rand_between(int a, int b);
void rand_population(population *pop);
void evalutate(population *pop, double (*function)(int[], int));
double fitness_func(int *param, int data_count);
void mutate(chromosome *crms, int bit_count);
individual* select_individual(population *pop);

int main(){
	int i, j;
	int pop_size = 100;
	int bit_count = 2;
	int data_count = 2;
	population *pop = create_population(pop_size, bit_count, data_count);
	individual *ivd1, *ivd2;
	int param[2];

	rand_population(pop);
	
	ivd1 = select_individual(pop);
	ivd2 = select_individual(pop);
	
	decode(ivd1->crms, param, bit_count, data_count);
	decode(ivd2->crms, param, bit_count, data_count);
	
	evaluate(pop,fitness_func);

	for(i = 0; i < pop->pop_size; i++){
		printf("%d번째 fitness : %f\n", i, pop->ivd[i].fitness);
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
