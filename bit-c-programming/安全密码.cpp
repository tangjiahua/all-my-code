#include "stdio.h"
#include "string.h"
int main()
{
	int o,a,b,c,d,i;
	long n;
	char pas[20];
	while(scanf("%ld",&n)!=EOF)
	{
		getchar();
		for(int q=0;q<n;q++)
			{
				gets(pas);
				a=0,b=0,c=0,d=0;
				for(int j=0;j<strlen(pas);j++)
					{
							if(pas[j]>='0'&&pas[j]<='9') a=1;
						else if(pas[j]>='a'&&pas[j]<='z') b=1;
						else if(pas[j]>='A'&&pas[j]<='Z')	c=1;
						else d=1;
					}
					o=a+b+c+d;
				if((strlen(pas)>=6)&&o>=3)	printf("Safe\n");
				else if((strlen(pas))<6||o==1) printf("Not Safe\n");
				else if((strlen(pas))>=6&&o==2) printf("Medium Safe\n");
			}
		}
	}


