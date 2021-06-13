#include "stdio.h"
int main()
{
	char judge[100];
	char a;
	int i,k=0; 
	while((a=getchar())!=0)
	{
		for(i=0;i<k;i++)
		{
			if(a==judge[i])
			{
				break;
			}
			
		}
		
		if(i==k)
			{
				printf("%c",a);
				judge[k]=a;
				k++;
			}
		if(a=='\n')
		{
			for(i=0;i<k;i++)
			{
				judge[i]=' ';
			}
			k=0;
		}
	}
} 
