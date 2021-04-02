#include "stdio.h"
int main()
{
	int T,count;
	while(scanf("%d",&T)!=EOF)
	{
		for(int i=0;i<T;i++)
		{
			long long int a,b;
			scanf("%lld%lld",&a,&b);
			if(a>b) printf("a>b\n");
			if(a==b) printf("a=b\n");
			if(a<b) printf("a<b\n");
			
		}
	}
}
