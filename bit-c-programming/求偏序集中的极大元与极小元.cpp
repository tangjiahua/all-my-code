#include "stdio.h"
#include "string.h"
int main()
{
	char ch1[10], ch0;
	char puts1[10] = {'0','0','0','0','0','0','0','0','0','\0'}, puts2[10] = {'0','0','0','0','0','0','0','0','0','\0'};
	int i = 0, m = 0;
	while(ch0 = getchar() )
	{
		if(ch0 == ',') continue;
		else if(ch0 == '\n') break;
		else ch1[i++] = ch0;
	}
	char ch2[50];
	gets(ch2);

	for(int j = 0; j < i; j++)
	{
		char y = ch1[j];
		int c = 0;
		for(int k = 0; k < i; k++)
		{
			char x = ch1[k];
			int a = 0, b = 0;
			for(int p  = 0; p < strlen(ch2); p++)
			{
				if(ch2[p] == '<')
				{
					if(x == ch2[p+1] && y == ch2[p+3])
					{
						a = 1;
					}
				}

			}
			if(x == y) b = 1;
			else b = 0;

			c = (!a||b) + c;

		}
		if(c == i) puts1[m++] = ch1[j];
	}

	m = 0;

	for(int j = 0; j < i; j++)
	{
		char y = ch1[j];
		int c = 0;
		for(int k = 0; k < i; k++)
		{
			char x = ch1[k];
			int a = 0, b = 0;
			for(int p  = 0; p < strlen(ch2); p++)
			{
				if(ch2[p]== '<')
				{
					if(x == ch2[p+3] && y == ch2[p+1])
					{
						a = 1;
						break;
					}
				}

			}
			if(x == y) b = 1;
			else b = 0;

			c = (!a||b) + c;

		}
		if(c == i) puts2[m++] = ch1[j];
		
	}
	m = 0;
	while(puts1[m] != '0' && puts1[m+1] != '0')
	{
		putchar(puts1[m]);
		putchar(',');
		m++;
	}
	putchar(puts1[m]);
	putchar('\n');

	m = 0;
	while(puts2[m] != '0' && puts2[m+1] != '0')
	{
		putchar(puts2[m]);
		putchar(',');
		m++;
	}
	putchar(puts2[m]);
	putchar('\n');
}
