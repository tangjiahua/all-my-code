#include "stdio.h"
int main()
{
	long int a,b;
	while(scanf("%ld,%ld",&a,&b)!=EOF)
	{
		long int c=1;
		long int x;
		if(a==b)
		{
			printf("%ld\n",a);
			continue;
		}
		while(c)
		{
			c=b%a;
			if(c==0) break;
			x=c;b=a;a=x;
			c=b%a;
		}
			printf("%ld\n",a);	
	}
	
}

