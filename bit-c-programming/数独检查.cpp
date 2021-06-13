#include "stdio.h"
int main()
{
	int T,count;
	char b[9][9];
	char ch[9];
	int q;
	while(scanf("%d",&T)!=EOF)
	{
		for(int i=0;i<T;i++)
		{
		count=0;q=0;
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
			{
				b[i][j]=getchar();
				if(b[i][j]=='\n') b[i][j]=getchar();
			}
			
		for(int i=0;i<9;i+=3)
			{
				for(int j=0;j<9;j+=3)
				{
					int i2=i+3,j2=j+3;
					for(int i1=i;i1<i2;i1++)
						{
							for(int j1=j;j1<j2;j1++)
							{
								ch[q]=b[i1][j1];
								q++;
							}
						}
					
					for(i=0;i<9-1;i++)
					for(j=0;j<9-i-1;j++)
					{
						if(ch[j]==ch[j+1])
						{
							count=1;
						}
					}

				}
			}
		if(count==0) printf("Accepted\n");
		else printf("Rejected\n");
	}
}
}
