#include "stdio.h"
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		char ch[n][n],w='A';
		int p=0,q=0,i,j;
		while(q<(n+1)/2)
		{
		
			for(i=p;i<n-p-1;i++)					/*1*/
			{
					ch[p][i]=w;
					w++;
					if(w=='Z'+1) w='A'; 		
			}
			for(j=q;j<n-p-1;j++)					/*2*/
			{
				ch[j][n-p-1]=w;
				w++;
				if(w=='Z'+1) w='A';	
			}
			for(i=n-p-1;i>p;i--)   					/*3*/
			{
					ch[n-1-p][i]=w;
					w++;
					if(w=='Z'+1) w='A'; 
			}
			for(j=n-p-1;j>q;j--)				/*4*/
			{
				ch[j][q]=w;
				w++;
				if(w=='Z'+1) w='A';	
			}
			q++;
			p++;
		}
		if(n%2!=0) ch[(n-1)/2][(n-1)/2]=w;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%c",ch[i][j]);
				
			}
			printf("\n");
		}
	}
}
