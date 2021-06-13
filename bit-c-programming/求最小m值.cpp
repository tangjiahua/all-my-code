#include "stdio.h"
int power(int n)
{
	int i,all=0;
	for(i=1;;i++)
	{
		all+=i;
		if(all<n&&all+i+1>n)
			break;
	}
	return i;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d",power(n)+1);
	}
}
