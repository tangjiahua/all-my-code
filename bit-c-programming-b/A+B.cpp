#include "stdio.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i = 0; i < n; i++)
	{
		char a[100005] = {'\0'}, b[100005] = {'\0'}, c[100005] = {'\0'};
		scanf("%s",a);
		scanf("%s",b);
		long la = strlen(a), lb = strlen(b), p = 0, jinwei = 0;
		do
		{
			if(a[la - p - 1] == '1' && b[lb - p - 1] == '1')
			{
				if(jinwei == 1)
				{
					c[100004 - p] = '1';
					jinwei = 1;
				}
				else
				{
					c[100004 - p] = '0';
					jinwei = 1;
				}
			}
			else if(a[la - p - 1] != b[lb - p - 1])
			{
				if(jinwei == 0)
				{
					c[100004 - p] = '1';
					jinwei = 0;
				}
				else 
				{
					c[100004 - p] = '0';
					jinwei = 1;
				}
			}
			else
			{
				if(jinwei == 0)
				{
					c[100004 - p] = '0';
					jinwei = 0;
				}
				else
				{
					c[100004 - p] = '1';
					jinwei = 0;
				}
			}
			p++;

		}while(la-p-1>=0 && lb-p-1>=0);
		
		if(la-p-1 < 0 && lb-p-1 >= 0)
		{
			do
			{
				if(b[lb - p - 1] == '0')
				{
					if(jinwei == 1)
					{
						c[100004 - p] = '1';
						jinwei = 0;
					}
					else
					{
						c[100004 - p] = '0';
						jinwei = 0;
					}
				}
				else if(b[lb - p - 1] == '1')
				{
					if(jinwei == 1)
					{
						c[100004 - p] = '0';
						jinwei = 1;
					}
					else
					{
						c[100004 - p] = '1';
						jinwei = 0;
					}

				}
				p++;
			}while(lb-p-1 >= 0);
			if(jinwei == 1) c[100004 - p] = '1';
		}


		else if(lb-p-1 < 0 && la-p-1 >= 0)
		{
			do
			{
				if(a[la - p - 1] == '0')
				{
					if(jinwei == 1)
					{
						c[100004 - p] = '1';
						jinwei = 0;
					}
					else
					{
						c[100004 - p] = '0';
						jinwei = 0;
					}
				}
				else if(a[la - p - 1] == '1')
				{
					if(jinwei == 1)
					{
						c[100004 - p] = '0';
						jinwei = 1;
					}
					else
					{
						c[100004 - p] = '1';
						jinwei = 0;
					}

				}
				p++;
			}while(la-p-1 >= 0);
			if(jinwei == 1) c[100004 - p] = '1';
		}
		
		else
		{
			if(jinwei == 1)
			{
				c[100004 - p] = '1';
			}
		}
	
		
		long f = 0; //╣зр╩ее 
		for(long k = 0; k < 100005; k++)
		{
			if(c[k] != '\0') f++;
		}
		
		long t = f + 2;//1
		for(long i = 0; i < t-la; i++)
		{
			putchar(' ');
		}
		puts(a);
		
		putchar('+');//2
		for(long i = 0; i < t-lb-1; i++)
		{
			putchar(' ');
		}
		puts(b);
		
		for(long n = 0; n < t; n++) putchar('-');//3
		putchar('\n');
		
		for(long n = 0; n<2; n++)	putchar(' ');
		for(long k = 0; k < 100005; k++)
		{
			if(c[k] != '\0') putchar(c[k]);
		}
		putchar('\n');
	}
	return 0;
}
