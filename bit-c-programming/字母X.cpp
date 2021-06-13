#include "stdio.h"
int main()
{
	int n,i,j;
	char ch;
	scanf("%d %c",&n, &ch);
	if(ch<'A'||ch>'Z') 
	{
		printf("input error.\n");
		return 0;
	}
	for(i=1;i<=n;i++,printf("\n"))
	{
		int x = ch+n-i;
		for(j=1;j<=2*n-1;j++)
		{
			if(j==i||j==2*n-i)
				printf("%c",x>90?x-26:x);
			else if(j>2*n-i)	continue;
			else	printf(" ");
		}
	}
	for(i=1;i<n;i++,printf("\n"))
	{
		int x = ch - (i);
		for(j=1;j<=2*n-1;j++)
		{
			if(j==n-i||j==i+n)
				
				printf("%c",x<65?x+26:x);
			else if(j>i+n) continue;
			else 	printf(" ");
		}
	}
} 


