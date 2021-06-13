#include "stdio.h"
#define MAX 10000
int main()
{
	int n,m,i,j,judge,q,p,count;
	int a[100],b[100];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		count=0;
		judge=MAX;
		p=0;
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(j=0;j<m;j++)
		scanf("%d",&b[j]);
		
		if(n>m)
		{
			printf("bit is doomed!\n");
			continue;
		}
		
		for(i=0;i<n;i++)
			{
			
				for(j=0;j<m;j++)
				{
					if(b[j]<a[i])	continue;
					else if((b[j]>=a[i])&&(b[j]<judge))
					{
						if(judge == MAX)
							{
								p=p+b[j];
								judge=b[j];
								q=j;
								count++;
							}
						else{
						p=p-judge+b[j];
						judge=b[j];
						q=j;
						count++;}
					}
				}
				judge=MAX;
				b[q]=MAX;
			}
			if(count<n)
			{
				printf("bit is doomed!\n");
				continue;
			}	
		printf("%d\n",p);
	}
}
