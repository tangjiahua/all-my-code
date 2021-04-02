#include "stdio.h"
#include "string.h"
int main()
{
	char s[81],t[81],u[81];
	int ls,lt,k,i,j,x;
	while(gets(s)!=NULL)
	{
		k=0;
		gets(t);
		ls=strlen(s);
		lt=strlen(t);
		for(i=0;i<ls;i++)
		{
			for(j=0;j<lt;j++)
			{
				if(s[i]==t[j])
				{
					break;
				}
			}
			if(j==lt)
			{
				u[k]=s[i];
				k++;
			}
		}
		for(i=0;i<k;i++)
		putchar(u[i]);
		printf("\n");
	}
}
