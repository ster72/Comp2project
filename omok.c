#include "common.h"

population* create_population(int pop_size, int bit_count, int data_count);
void free_population(population *pop);

main()
{
	int pop_size = 100;
	int bit_size = 2;
	int data_count = 2;
	population *pop = create_population(pop_size, bit_count, data_count);

	for(i=0;i<pop_size;i++){
		printf("%d %p", i, &pop_ivd[i]);
		printf("%p\n", pop->ivd[i].crms);
		}

		free_population(pop);
		printf("아무키나 누르시오");getchar();
		return 0;
}

population* create_population(int pop_size, int bit_count, int data_count){
	int i;
	//1. 개체군 또는 집단을 위한 메모리 생성
	population *pop = (population*)malloc(sizeof(population));
	//2. 개체수만큼 개체를 생성
	individual *ivd = (individual*)malloc(sizeof(individual)*pop_size);
	//3. 모든 개체 내의 염색체 메모리 생성
	for(i=0;i<pop_size;i++){
	ivd[i].crms = (int*)malloc(sizeof(chromosome)*bit_count);
	ivd[i].fitness = 0.0;
	}

void free_population(population *pop){
	int i;
	for(i=0; i<pop_size;i++){
		free(pop->ivd[i].crms); //chromosome의 메모리 제거
		}
		free(pop->ivd); //individual의 메모리 제거
		free(pop); //population의 메모리 제거
}
