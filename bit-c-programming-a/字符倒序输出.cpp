#include "stdio.h"
#include "string.h"
int main()
{
	char ch[100];
	int l,i;
	while(scanf("%s",&ch)!=EOF)
	{
		l=strlen(ch);
		for(i=l;i>0;i--)
		{
			putchar(ch[i-1]);
		}
		printf("\n");
	}
} 
