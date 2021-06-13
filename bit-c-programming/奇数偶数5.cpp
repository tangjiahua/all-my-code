#include "stdio.h"
int main()
{
	long m,n,min,max,i;
	long ou[999],ji[999];
	long numou=0,numji=0;
	scanf("%ld %ld",&m,&n);
	max=(m>n)?m:n;
	min=(m<n)?m:n;
		for(i=min;i<=max;i++)
		{
			if(i%2==0) 
			{
				numou=numou+i*i;
			}
			else
			{
				numji=numji+i*i*i;
			}
		} 
		
		
	printf("%ld %ld",numou,numji);
} 
