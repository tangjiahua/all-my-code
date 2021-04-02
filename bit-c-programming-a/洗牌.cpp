#include "stdio.h"
int main()
{
	int n,i,p;
	while(scanf("%d",&n)!=EOF)
	{
		p=0;
		int card1[2*n],card2[2*n],card3[2*n];
		int ok=1;
		for(i=0;i<2*n;i++)
		{
			card1[i]=i;
			card2[i]=i;
			card3[i]=i;
		}
		while(ok)
		{
		ok=0;
		for(i=0;i<n;i++)
			card3[i*2+1]=card2[i];
		for(i=0;i<n;i++)
			card3[i*2]=card2[i+n];
		for(i=0;i<2*n;i++)
			card2[i]=card3[i];
		
		for(i=0;i<2*n;i++)
		{
			if(card1[i]!=card2[i]) ok=1;
		}
		p++;
		}
		printf("%d\n",p);
	}
}
