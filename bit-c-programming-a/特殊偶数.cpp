#include "stdio.h"
int main()
{
	int a,b,i,num[4],counter=0,j;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		counter=0;
		if (a>b) {printf("Error\n"); continue;
		}
		else if(a==0 && b==0) { break;
		}
		else if (a<1000||b<1000||a>9999||b>9999) {printf("Error\n"); continue;
		}
		
		
		for(i=a;i<b;i++)
		{
			if(i%2!=0) continue;
			num[0]=i/1000;
			num[1]=i/100%10;
			num[2]=i/10%10;
			num[3]=i%10;
			if(num[0]==num[1]||num[0]==num[2]||num[0]==num[3]||num[1]==num[2]||num[1]==num[3]||num[2]==num[3]) continue;
			else {
				for(j=0;j<=3;j++)
				{
					printf("%d",num[j]);
				}
				printf("  ");
				counter++;
			}
		}
		printf("\ncounter=%d\n",counter);
	
	}
	return 0;
}
