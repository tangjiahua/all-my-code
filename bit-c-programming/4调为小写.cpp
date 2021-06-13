#include "stdio.h"
int main()
{
	char ch;
	while((ch=getchar())!=EOF)
	{

	while(ch!='\n')
	{
		if(ch>=65&&ch<=90) 
		{
		ch=ch+32;
		putchar(ch);
	    }
	    else putchar(ch);
		ch=getchar();
	}
	printf("\n");
	}
}
