#include "stdio.h"
#include "string.h"
int main()
{
	char ch[5][50],change[50];
	int i,j;
	while(scanf("%s",ch[0])!=EOF)
	{
		scanf("%s",ch[1]);scanf("%s",ch[2]);scanf("%s",ch[3]);scanf("%s",ch[4]);
		for(i=0;i<4;i++)
			for(j=0;j<4-i;j++)
			{
				if(*ch[j]<*ch[j+1])
				{
					strcpy(change,ch[j]);
					strcpy(ch[j],ch[j+1]);
					strcpy(ch[j+1],change);
				}
			}
		for(i=0;i<5;i++)
		{
			puts(ch[i]);
		}
	}
}
