#include "stdio.h"
int main()
{
	long n,q,i,j=0;
	long num[100000]={0};
	long k[100000]={0};
	long result[100000]={0};
	long d=0,p=0;
	while(scanf("%ld",&n)!=EOF)
	{ 
		
		i=0; 
		while(i<n)
		{
			scanf("%d",&num[i]);
			i++;
		}
		
		scanf("%ld",&q);
		i=0;
		
		while(i<q)
		{
			scanf("%d",&k[i]);
			i++;
		}
	
			d=0,p=0,i=1;
			result[0]=num[0];
			while(i<n)
			{
				
				result[i]=result[i-1]+num[i];
				i++;
			}
		
		i=0;
		while(i<q)
		{
			
			if(i==0) printf("%ld",result[k[i]-1]);
			else printf(" %ld",result[(k[i])-1]);
			i++;
		}
		printf("\n");

	}
		
} 
