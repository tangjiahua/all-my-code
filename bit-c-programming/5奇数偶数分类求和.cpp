#include "stdio.h"
int main()
{
	long m[999],n[999],min,max,i,j=0; 
	long numou[999],numji[999];
	while(scanf("%ld %ld",&m[j],&n[j])!=EOF)
	{
		numou[j]=0; numji[j]=0;
	max=(m[j]>n[j])?m[j]:n[j];
	min=(m[j]<n[j])?m[j]:n[j];
		for(i=min;i<=max;i++)
		{
			if(i%2==0) 
			{
				numou[j]=numou[j]+i*i;
			}
			else
			{
				numji[j]=numji[j]+i*i*i;
			}
		} printf("%ld %ld\n",numou[j],numji[j]); 
			j++;
		
	}
		
	
} 
