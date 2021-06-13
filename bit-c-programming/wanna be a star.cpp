#include "stdio.h"
int main()
{
	int score[10], i1, i2;
	int max=0, min=100, total=0;
	while(scanf("%d",&score[0])!=EOF)
	{
		for(int i=1;i<10;i++)
			scanf("%d",&score[i]);
			
		for(int i=0;i<10;i++)
		{
			if(score[i]>max)
			{
				max=score[i];
				i1=i;
			}
			if(score[i]<min)
			{
				min=score[i];
				i2=i;
			}
		}
		
		for(int i=0;i<10;i++)
			total+=score[i];
		total=(total-score[i1]-score[i2])/8;
		
		printf("Canceled Max Score:%d\n",max);
		printf("Canceled Min Score:%d\n",min);
		printf("Average Score:%d\n",total);
	}
}
