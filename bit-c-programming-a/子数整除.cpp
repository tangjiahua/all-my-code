#include "stdio.h"
int main()
{
	int k;
	int sub[3];
	while(scanf("%d",&k)!=EOF)
	{
		for(int i=10000;i<=30000;i++)
		{
			sub[0]=i/100;
			sub[1]=i/1000%10*100+i/100%10*10+i/10%10;
			sub[2]=i%10+i/10%10*10+i/100%10*100;
			if(sub[0]%k==0&&sub[1]%k==0&&sub[2]%k==0)
			{
				printf("%d\n",i);
			}
		}
	}
}
