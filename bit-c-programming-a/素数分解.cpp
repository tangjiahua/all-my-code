#include "stdio.h"
int main()
{	
	long n,su,chu=2;
	long answer[999],q=0,p=0;
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
	printf("%ld",answer[p]);
	for(p=1;p<q;p++)
	{
		printf("*%ld",answer[p]);
	}

}
