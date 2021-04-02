#include "stdio.h"
#include "math.h"
int main()
{
	int n,char ch;
	while(scanf("%d %c",&n,&ch)!=EOF); 
	{
		if(ch<'A'||ch>'Z')
		{
			printf("input error.\n");
			continue;
		}

		for(int i=0;i<2*n-1;i++)
		{
			if(i==n)
			{
				for(int p=0;p<n-1;p++)
					putchar(' ');
				putchar(ch);
				printf("\n");
				contnue;
			}
			int j=2*n-2-i;
			

			}
		}
	}
}