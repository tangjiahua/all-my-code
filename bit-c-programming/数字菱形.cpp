#include "stdio.h"
#include "math.h"
int main()
{
	int n,i,j,size,x,y;
	while(scanf("%d",&n)!=EOF)
	{
		size=2*n-1;
		for(i=1;i<size+1;i++)
		{
			x=n;
			for(j=1;j<size+1;j++)
			{
				y=fabs(n-i)+1;
				
				if(j<y) printf("  ");
				else {
					printf("%-2d",x);
					if(x==n&&j>=n) break;
					if(n>j) x--;
					else x++;
			
				}
				
				
			}
			printf("\n");
		}
	}
} 
