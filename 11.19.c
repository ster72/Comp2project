#include "comp2.h"

int main()
{
	int i, j, x, y, z;
	int check = 0;
	int pop_size = 1;
	int bit_count = 2;
	int data_count = 2;
	
	population *pop = create_population(pop_size, bit_count, data_count);
	
	while(1)
	{			 	
		printf("x : ");
		scanf("%d", &x);
		printf("y : ");
		scanf("%d", &y);
	
	    if(x<0 || x>14)
	    {
			check = 1;
		}
		
		else if(y<0 || y>14)	
		{
			check = 1;
		}
		
		if(check == 1)
		{
			printf("다시 입력 하세요\n");
			check = 0;
			continue;
		}
	
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
