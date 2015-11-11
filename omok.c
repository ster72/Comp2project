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
	int i, j, x, y, z=0;
	int pop_size = 1;
	int bit_count = 2;
	int data_count = 2;
	population *pop = create_population(pop_size, bit_count, data_count);
	individual *ivd1, *ivd2;
	int param[2];
	
	while(z < 255)
	{
		printf("x : ");
		scanf("%d", &x);
		printf("y : ");
		scanf("%d", &y);
		
		rand_population(pop);//랜덤수 추출 
	
		evaluate(pop,fitness_func);

		for(i = 0; i < pop->pop_size; i++){
		 for(j = 0; j < bit_count; j++){
			 if(j==8)
			 printf(" ");
			printf("%d ", pop->ivd[i].crms[j]);//랜덤한 좌표출력 
			}
		printf("\n");
		}	
		z++;
	}	
	free_population(pop);
	printf("아무키나 누르십시오...");getchar();
	return 0; 
}


