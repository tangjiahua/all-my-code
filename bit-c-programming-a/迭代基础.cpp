#include "stdio.h"
int power(int x,int n);
int main()
{
	int a,b,y;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		y=power(a,b);
		printf("answer is %d\n",y);
	}
}

int power(int x,int n)
{
	if(n==0) return 1;
	else 
	{
		return (x*power(x,n-1));
	}
}

