#include "stdio.h"
#include "string.h"
int main()
{
	char ch[50],p;
	int l,i,j;
	while(scanf("%s",ch)!=EOF)
	{
		l=strlen(ch);
		for(i=0;i<l-1;i++)
			for(j=0;j<l-i-1;j++)
			{
				if(ch[j]<ch[j+1])
				{
					p=ch[j];
					ch[j]=ch[j+1];
					ch[j+1]=p;
				}
			}
		for(i=0;i<l;i++)
		putchar(ch[i]);
		printf("\n");
	}	
} 
