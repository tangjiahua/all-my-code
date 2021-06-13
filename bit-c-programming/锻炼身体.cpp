#include "stdio.h"
#include "math.h"
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a,b,max,i=0;
		for(;n;n--){
		for(a=1;a<n;a++)
		{
			for(b=a;b<n;b++)
			{
				if(a*a+b*b==n*n&&a<=b&&b<=n)
					i++;
			}
		}
	}
		printf("%d\n",i);
	}
}
