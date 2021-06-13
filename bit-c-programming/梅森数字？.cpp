#include "stdio.h"
long meisen(int x);
int main()
{
	long n,i;
	while((scanf("%ld",&n))!=EOF)
	{
		for(i=0;i<30;i++)
		{
			if(n==meisen(i))
			{
				printf("YES\n");
				break;
			}
		
		}
		if(i==30) printf("NO\n");
	}
}
long meisen(int x)
{
	int i;
	long p=1;
	for(i=0;i<x;i++)
	{
		p=p*2;
	}
	p=p-1;
	return p;
}
