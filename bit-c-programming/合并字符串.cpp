#include "stdio.h"
#include "string.h"
int main()
{
	char ch1[50],ch2[50],ch3;
	int i,j,l,l1,l2;
	while(gets(ch1)!=NULL)
	{
		gets(ch2);
		l1=strlen(ch1);
		l2=strlen(ch2);
		
		strcat (ch1,ch2);
		l=strlen(ch1);
		if(l==l1)
		{
			printf("%s",ch1);
			continue;
		} 
		
		for(i=0;i<l-1;i++)
		{
			for(j=0;j<l-i-1;j++)
			{
				if(ch1[j]>ch1[j+1])
				{
					ch3=ch1[j];
					ch1[j]=ch1[j+1];
					ch1[j+1]=ch3;
				}
			}
		}
	for(i=0;i<l;i++)
	putchar(ch1[i]);
	printf("\n");
	}
} 
