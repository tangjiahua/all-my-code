#include "stdio.h"
int main()
{
	int t,i,n,j;
	int a,b,c,all,max;
	while(scanf("%d",&t)!=EOF)
	{
		for(i=0;i<t;i++)
		{
			max=-9999;
			scanf("%d",&n);
			int si[n];
			for(j=0;j<n;j++)
			{
				scanf("%d",&si[j]);
			}
			
			for(a=1;a<=n;a++)
			{
				for(b=0;b<n-a;b++)
				{
					all=0;
					for(c=b;c<a+b;c++)
					{
						all=all+si[c];
					}
					if(all>max) max=all;
				}
			}
			
			printf("%d\n",max);
		}
	}
} 
