#include "stdio.h"
int main()
{
	int n,i,x,q;
	while(scanf("%d",&n)!=EOF)
	{
	
	x=1;
	q=n-1;
	for(i=0;i<n-1;i++)
	{
		x=(x+q)*2;
		q--;
	}
	if(x==1)
	{
		printf("The monkey got %d peach in first day.\n",x);
	}
	else
	printf("The monkey got %d peaches in first day.\n",x);
}
}
