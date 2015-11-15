#include "comp2.h"

population* create_population(int pop_size, int bit_count, int data_count);
void free_population(population *pop);
int rand_between(int a, int b);
void rand_population(population *pop);
void evalutate(population *pop, double (*function)(int[], int));
double fitness_func(int *param, int data_count);
void mutate(chromosome *crms, int bit_count);
individual* select_individual(population *pop);

int main(){
	int i, j, x, y, z;
	int cheak = 0;
	int pop_size = 1;
	int bit_count = 2;
	int data_count = 2;
	int board [X][Y];
	population *pop = create_population(pop_size, bit_count, data_count);
	individual *ivd1, *ivd2;
	int param[2];
	
	for(z=0;z<255;z++)
	{		 	
		printf("x: ");
		scanf("%d", &x);
		printf("y: ");
		scanf("%d", &y);
		
		if(x == board[z][0] && y == board[0][z])
		{
			cheak = 1;
		}	
			
	    if(x<0 || x>14)
	    {
			cheak = 1;
		}
		
		else if(y<0 || y>14)	
		{
			cheak = 1;
		}
		
		
	    if(cheak == 1)
	    {
			printf("다시 입력하십시오\n");	    
			cheak--;
			continue;	
		}
	
			x = board[z][0];
			y = board[0][z];
		
		
		rand_population(pop);//랜덤수 추출 

		for(i = 0; i < pop->pop_size; i++){
			printf("컴퓨터의 출력\n");
		 for(j = 0; j < bit_count; j++){
			printf("%d ", pop->ivd[i].crms[j]);//랜덤한 좌표출력 
			}
		printf("\n");
		}
	}	
	
	free_population(pop);
	printf("아무키나 누르십시오...");getchar();
	return 0; 
}


