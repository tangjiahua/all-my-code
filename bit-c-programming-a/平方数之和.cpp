#include "stdio.h"
#include "math.h"
int power(int x,int y)
{
		double d=sqrt(y);
		for(int a=0;a<=d;a++)
		{
			if(a*a==x) return 1;
			else ;
		}
	return 0;
}
int main()
{
	int a,b;
	int c;
	while(scanf("%d,%d",&a,&b)!=EOF)
	{
		c=0;
		while(a<=b)
		{
			if(power(a,b)) c=c+a;
			else ;
			a++;
		}
		printf("%d\n",c);
	}
}

