#include  "stdio.h"
#include "math.h"
int main()
{
	int n,i,j,q;
	while(scanf("%d",&n)!=EOF)
	{
		j=(int)sqrt(n);
		for(i=n;i>1;i--)
		{
			for(q=2;q<j;q++)
			{
				if(i%q==0){
					break;
				}
				
			}
			if(q==j) {
				printf("The max prime number is %d.\n",i);
				break;
			}
			else continue;
		
		}
	}
}
