#include "stdio.h"
int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		draw(0,0,1,1);
		for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(j<(n-1)) printf("%2d ",ans[i][j]);
					else printf("%2d\n",ans[i][j]);
				}	
			}
	}
} 


void draw(int x,int y,int direct,int step)
{
	if(step>n*n) return 0;
	
}
