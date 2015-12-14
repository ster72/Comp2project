# Comp2project
#include "comp2.h"


int main()
{
	int x, y, i, j, z;
	int check = 0;
	int pop_size = 1;
	int bit_count = 2;
	int data_count = 2;
	int fitness[15][15];
	int select = 0;
	int save_x[15];
	int save_y[15];
	int board[15][15];
	int com_x = 0;
	int com_y = 0;

	
	
	
	printf("교배하시겠습니까?\n");
    	printf("(1)적응도 (2)진행\n");
    	scanf("%d", &z);
    	
    	srand((unsigned)time(NULL));
    
    
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
    	
    	if(z == 1)
    	{
    		for(i=0;i<15;i++)
    		{
    			for(j=0;j<15;j++)
    			{
    				fitness[i][j] = 0;	
					save_x[i] = 0;
					save_y[j] = 0;	
				}
			}
			
			for(i=x-1;i<=x+1;i++)
			{
				for(j=y-1;j<=y+1;j++)
				{
					fitness[i][j] = fitness[i][j]+3;
				}
				fitness[x][y] = fitness[x][y] - 1;
			}
			
    		for(i=0;i<15;i++)// 적응도 값이 높은 곳을 save배열에 저장 
			{
				for(j=0;j<15;j++)
				{
					select = (select < fitness[i][j]) ? fitness[i][j]:select;
					if(select == fitness[i][j])
					{
						save_x[i] = i;
						save_y[j] = j;
					}
				}
			}
		
			printf("컴퓨터의 출력\n");
			for(i=0;i<15;i++)// 적응도 값에 따른 출력 
			{
				for(j=0;j<15;j++)
				{
					if(fitness[i][j] >= 3)
					{
						if(fitness[i][j] < fitness[i+1][j+1])
						{	
							com_x = i+1;
							com_y = j+1;
						}
						else
						{
							com_x = i;
							com_y = j;
						}
					}
				}
			}
			printf("%d %d\n", com_x, com_y);
		}
    	
    	if(z == 2)
		{
			population *pop = create_population(pop_size, bit_count, data_count);
			rand_population(pop);
			
			for(i=0;i<pop_size;i++)
			{
				printf("컴퓨터의 출력\n");
				for(j=0;j<bit_count;j++)
				{
					printf("%d ", pop->ivd[i].crms[j]);
				}
				printf("\n");
			}
		}
		
	}	

	printf("아무키나 누르십시오...");getchar();
	return 0; 
}
