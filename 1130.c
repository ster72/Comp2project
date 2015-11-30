# Comp2project
#include "comp2.h"

int main()
{
	int x, y, i, j;
	int check = 0;
	int pop_size = 10;
	int bit_count = 2;
	int data_count = 2;
	int param[2];
	individual *ivd1, *ivd2;
	

	population *pop = create_population(pop_size, bit_count, data_count);
	
	while(1)
	{			 	
		printf("x : ");
		scanf("%d", &x);
		printf("y : ");
		scanf("%d", &y);
	
	    if(x<0 || x>14)// 오목판을 넘어가는 숫자를 입력시 다시 입력 
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
		
		if(board[x][y] == 1)// 중복을막음 
		{
		printf("중복된 곳입니다.\n");
		continue;
  		}
    	board[x][y] = 1;
	
		rand_population(pop);//랜덤수 추출 
		
		ivd1 = select_individual(pop);
		ivd2 = select_individual(pop);
		
		decode(ivd1->crms, param, bit_count, data_count);		
		decode(ivd2->crms, param, bit_count, data_count);	
		
		printf("%d %d\n", param[0], param[1]);

		/*if(param[0] == 1 && param[1] == 1)
		{
			check = 2;
		}
			if(check = 2)
			{
				printf("중복\n");
				continue;
			}
			param[0] = 1;
			param[1] = 1;*/
		
		
	}	
	
	free_population(pop);
	printf("아무키나 누르십시오...");getchar();
	return 0; 
}
