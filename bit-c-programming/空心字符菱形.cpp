#include "stdio.h"
#include "math.h"
int main()
{
	char ch;
	int n,i,j,size;
	while(scanf("%c %d",&ch,&n)!=EOF)
	{
		size=2*n-1;
		for(i=1;i<size+1;i++)
		{
			
			for(j=1;j<size+1;j++)
			{
				if(j==fabs(n-i)+1||j==size-fabs(n-i))
				{
					printf("%c",ch);
						if(j>=n)
						{
							printf("\n");
							break;
						}
				}
			
				else printf(" ");
			
			}
			if(i<n)
			{
				ch++;
			}
			else
			{
				ch--;
			}
		}
		getchar();
		
	}
}
