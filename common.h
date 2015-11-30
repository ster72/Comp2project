#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <string.h>

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

population* create_population(int pop_size, int bit_count, int data_count);
void free_population(population *pop);
int rand_between(int a, int b);
void rand_population(population *pop);
void evalutate(population *pop, double (*function)(int[], int));
double fitness_func(int *param, int data_count);
void mutate(chromosome *crms, int bit_count);
individual* select_individual(population *pop);
int board[15][15];
void crossover(chromosome *old_c1, chromosome *old_c2, chromosome *new_c1, chromosome *new_c2);
void breed(individual *old_v1, individual *old_v2, individual *new_v1, individual *new_v2, int bit_count);
void new_generate(population *old_pop, population *new_pop);



int min(int a,int b);
/*개체군 생성*/ 
population* create_population(int pop_size, int bit_count, int data_count){
	int i;
	
	population *pop = (population*)malloc(sizeof(population));
	individual *ivd = (individual*)malloc(sizeof(individual)*pop_size);
	
	for(i = 0; i < pop_size; i++){
		ivd[i].crms = (int*)malloc(sizeof(chromosome)*bit_count);
		ivd[i].fitness = 0.0;
	}
	
	pop->ivd = ivd;
	pop->pop_size = pop_size;
	pop->bit_count = bit_count;
	pop->data_count = data_count;
	
	return pop;
	
}
/*제거 함수*/
void free_population(population *pop){
	int i;
	
	for(i = 0; i < pop->pop_size; i++){
		free(pop->ivd[i].crms);
	}
	free(pop -> ivd);
	
	free(pop);
	
}

int rand_between(int a, int b){
	int delta, randnum;
	delta = abs(a-b) + 1;
	randnum = rand()%delta;
	return (min(a,b) + randnum);
}
/*랜덤 추출*/
void rand_population(population *pop){
	int i;
	int pos;
	
	srand(time(NULL));
	
	for(i = 0; i < pop->pop_size; i++){
		for(pos = 0; pos < pop->bit_count; pos++){
			pop->ivd[i].crms[pos] = rand_between(0, 14);
		}
	}
}

int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}

void decode(chromosome *crms, int *param, int bit_count, int data_count){
	int pos;
	int n;
	int i;
	
	int data_bit_count = bit_count/data_count;
	pos = 0;
	
	for(n = 0; n < data_count; n++){
		param[n] = 0;
		for(i = 0; i < data_bit_count; i++){
			param[n] = param[n] + pow(2.0,(double)i) * crms[pos++];
		}
	}
}

void display_population(population *pop){
	int n;
	int i;
	
	int *param = (int*)malloc(sizeof(int)*pop->data_count);
	for(i = 0; i < pop->pop_size; i++){
		decode(pop->ivd[i].crms, param, pop->bit_count, pop->data_count);		
		for(n = 0; n < pop->data_count; n++){
			printf("%d\t", param[n]);
		}
		printf("\n");
	}
	free(param);
}
/*적응도값 계산*/
void evaluate(population *pop, double(*function)(int[],int)){
	int index;
	int *param = (int*)malloc(sizeof(int)*pop->data_count);//염색체 데이터 추출후 저장항 메모리 생성 
	
	for(index = 0; index <pop->pop_size; index++){//개체수만큼 개체의 염색체 데이터 추출 
		decode(pop->ivd[index].crms, param, pop->bit_count, pop->data_count);//데이터 해석후 param에 저장 
		pop->ivd[index].fitness = (*function)(param, pop->data_count);//적응도값 계산 
	}
	free(param);
}

double fitness_func(int *param, int data_count){
	int i;
	double fitness = 0;
	double sum = 0;
	for(i = 0; i < data_count; i++)
	    sum += param[i];
	
	fitness = sum;
	return fitness;
}

void mutate(chromosome *crms, int bit_count){
	int i;
	
	for(i = 0; i < bit_count; i++){
		if(rand_between(0, 225) == 0){
			crms[i] ^= 1;
		}
	}
}

individual* select_individual(population *pop){
	unsigned int index1, index2;
	int i, count = 0;
	
	do{
		count++;
		index1 = rand_between(0, pop->pop_size-1);
		index2 = rand_between(0, pop->pop_size-1);
		
		if(pop->ivd[index1].fitness == 0){
			break;			
		}
		
		if(count > 3){
			for(i = 0; i < pop->pop_size; i++){
				mutate(pop->ivd[i].crms, pop->bit_count);
			}
			break;
		}
	}while(pop->ivd[index1].fitness == pop->ivd[index2].fitness);
	
	if(pop->ivd[index1].fitness > pop->ivd[index2].fitness)
	   return &pop->ivd[index1];
	else
	   return &pop->ivd[index2];
}

void crossover(chromosome *old_c1, chromosome *old_c2, chromosome *new_c1, chromosome *new_c2)
{
	int i;
	int pos;
	//염색체의 데이터 복제
	for(i=0;i<bit_count;i++)
	{
		new_c1[i] = old_c2[i];
		new_c2[i] = old_c1[i];
	}
	//교배할 위치를 얻어낸다. 
	pos = rand_between(0, bit_count - 1);
	// 특정 위치의 데이터를 교배한다.
	 new_c1[pos] = old_c1[pos];
	 new_c2[pos] = old_c2[pos];
}

void breed(individual *old_v1, individual *old_v2, individual *new_v1, individual *new_v2, int bit_count)
{
	//교배시킨다.
	crossover(old_v1->crms, old_v2->crms, new_v1->crms, new_v2->crms, bit_count);
	//돌연변이를 가한다.
	mutate(new_v1->crms, bit_count);
	mutate(new_v2->crms, bit_count);
}
void new_generate(population *old_pop, population *new_pop)
{
	int i;
	individual *v1, *v2;
	//랜덤하게 2개의 개체를 pop_size/2번
	for(i=0;i<old_pop->pop_size;i+=2)
	{
		//배양한 개체쌍 선택
		v1 = select_individual(old_pop);
		v2 = select_individual(old_pop);
		//배양해서 개체군의 개체를 만들고 새로운 세대를 만든다.
		breed(v1, v2, &new_pop->ivd[i], &new_pop->ivd[i+1], old_pop->bit_count); 
		 
	} 
}
