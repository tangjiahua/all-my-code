#include "stdio.h"
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int i,j;
		int mat[n][m],q=0;
		for(i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&mat[i][j]);
		int row[n],col[m],max,min;
		for(i=0;i<n;i++)
			{max=-999,min=999;
			for(j=0;j<m;j++)
				if(mat[i][j]>max)
				{
					max=mat[i][j];
					row[i]=j;
				}}
		for(j=0;j<m;j++)
			{max=-999,min=999;
			for(i=0;i<n;i++)
				if(mat[i][j]<min)
				{
					min=mat[i][j];
					col[j]=i;
				}}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				{
					if(row[i]==j&&col[j]==i)
					{
						printf("Point:a[%d][%d]==%d\n",i,j,mat[i][j]);
						q=1;
					}
				}
		if(q==0) printf("No Point\n");
	}
}
