#include "comp2.h"

int main(){
	int i, j, x, y, z;
	int check;
	int pop_size = 1;
	int bit_count = 2;
	int data_count = 2;
	
	population *pop = create_population(pop_size, bit_count, data_count);
	
	individual *ivd1, *ivd2;
	int param[2];
	
	for(z=0;z<255;z++)
	{		 	
		
		printf("x : ");
		scanf("%d", &x);
		printf("y : ");
		scanf("%d", &y);
		
		for(i=0;i<15;i++){
			check = 0;
			for(j=0;j<15;j++){
				if(board[x][y] == 'X' || board[x][y] == 'O')
				{
					check = 2;
					break;
				}
			}
			if(check == 2){
				break;
			}
			if(check == 2){
				continue;
			}
		}
		
		
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
		printf("다시 입력하십시오\n");	    
			check--;
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


