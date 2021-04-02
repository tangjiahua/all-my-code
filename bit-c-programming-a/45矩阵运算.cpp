#include "stdio.h"
int main()
{
	int m,n,i,j,p=0,q=0,x,y;
	int k;
	int a[100][100];
	int b[100][100];
	int result[100][100];
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		i=0;j=0;
		
		while(i<m)
		{
			while(j<n)
			{
				scanf("%d",&a[i][j]);
				j++;
			}
			i++;
			j=0;
		}
		
		scanf("%d%d",&p,&q);
	
		i=0;j=0;
		while(i<p)
		{
			while(j<q)
			{
				scanf("%d",&b[i][j]);
				j++;
			}
			i++;
			j=0;
		}
		
		if(n!=p) 
		{
			printf("error\n");
			continue;
		}
		for(i=0;i<m;i++)
			for(k<0;j<q;j++)
				result[i][j]=0;

		x=0,y=0;
		for(i=0;i<m;i++)
         for(j=0;j<q;j++)
             for(k=0;k<n;k++){
                 result[i][j] += a[i][k]*b[k][j];
             }
		
		x=0;y=0;
		printf("%d %d\n",q,m);
		
		for(i=0;i<q;i++)
			{
				for(j=0;j<m;j++)
				{
					if(j==0)
					printf("%d",result[j][i]);
					else
					printf(" %d",result[j][i]);
				}
				printf("\n");
			}
	}	
}
