#include "stdio.h"
int power(int n);
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		power(n);
	}
}

int power(int n)
{
	if(n/10==0) printf("%d",n);
	else 
	{
		printf("%d",n%10);
		power(n/10);
	}
}
