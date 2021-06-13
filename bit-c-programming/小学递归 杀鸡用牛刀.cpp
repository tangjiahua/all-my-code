#include "stdio.h"
int power(int x, int y)
{
	if(x>y)	return 0;
	else x=x+power(x+1,y);
	return x;
}
int main()
{
	int m,n;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		
		printf("The sum from %d to %d is %d.\n",n,m,power(n,m));
	}
}
