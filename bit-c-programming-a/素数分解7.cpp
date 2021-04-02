#include "stdio.h"
int main()
{
	int k,i,chu=2,answer[999],q=0,p=0;
	long su;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		p=0;q=0;
		scanf("%ld",&su);
		while(su!=1)
		{
	
			while((su%chu)!=0)
			{	
				chu++;
			}
			while((su%chu)==0)
			{
				su=su/chu;
				answer[q]=chu;
				q++;
				chu=2;
				continue;
			}
		}
		printf("%ld",answer[0]);
		if(q==1) printf("\n");
		for(p=1;p<q;p++)
		{
			printf("*%ld",answer[p]);
			if(p==(q-1)) printf("\n");
		}
	}
	
	
}
