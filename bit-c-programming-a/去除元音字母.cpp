#include "stdio.h"
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		char ch[n][20];
		for(int i=0;i<n;i++)
			gets(ch[i]);
		for(int i=0;i<n;i++)
		{
			int j=0;
			while(ch[i][j]!='\0')
			{
				if(ch[i][j]=='a'||ch[i][j]=='e'||ch[i][j]=='i'||ch[i][j]=='o'||ch[i][j]=='u'||ch[i][j]=='A'||ch[i][j]=='E'||ch[i][j]=='I'||ch[i][j]=='O'||ch[i][j]=='U')
					;
				else putchar(ch[i][j]);
				j++;
			}
			printf("\n");
		}
	}
}
