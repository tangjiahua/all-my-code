#include "stdio.h"
int main()
{	
	int a,n,y,i;
	int x;
	while(scanf("%d %d",&a,&n)!=EOF)
	{
		x=1;
		if(n==0)
		{
			printf("The last 3 numbers is 1.\n");
			continue;
		}
		
		for(i=0;i<n;i++)
		{
			x*=a;
			x=x%10+x/10%10*10+x/100%10*100; 
		}
		printf("The last 3 numbers is %03d.\n",x);
	}
}
