#include "stdio.h"
#include "string.h"
int main()

/*abe,4egwegFWG859Fwg_$8120egw2_*/

{
	char ch[1001];
	int i=0,l,judge=0;
	while(gets(ch)!=NULL)
	{
		l=strlen(ch);
		while(i<l)
		{
			if(ch[i]<'0'||ch[i]>'9')
			{
				i++;
				continue;
			}
			
			
			if(ch[i]>='1'&&ch[i]<='9')
			{
				if(judge==1)
				printf(" ");
				while(ch[i+1]>='0'&&ch[i+1]<='9')
				{
					putchar(ch[i]);
					judge=1;
					i++;
					continue;
				}
				putchar(ch[i]);
				judge=1;
			
				i++;
				continue;
			} 
			
			if(ch[i]=='0')
			{
				if(judge==1)
				printf(" ");
				while(ch[i+1]=='0')
				{
					i++;
				}
				if(ch[i+1]<'0'||ch[i+1]>'9')
				{
					i++;
					judge=1;
					printf("0");
			
					continue;
				}
				if(ch[i+1]>='1'&&ch[i+1]<='9')
				{
					i++;
					while(ch[i+1]>='0'&&ch[i+1]<='9')
					{
						putchar(ch[i]);
						judge=1;
						i++;
					}
					putchar(ch[i]);
					judge=1;
					i++;

			
					continue;
					
				}
				
			}
			
		}
		printf("\n"); 
		i=0;
		judge=0;
 	}
}
