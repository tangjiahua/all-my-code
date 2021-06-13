#include <stdio.h>  
#include <stdlib.h>  
void reverse(char,int,int  );  
int main( )  
{   char str[100];  
    int start, end;  
    gets(str);  
    scanf("%d%d", &start, &end);  
    reverse( str, start, end );  
    printf("%s\n", str);  
    return 0;  
}  

void reverse( char *str, int a, int b)
{
	int i=0;
	while(str[i]!='\0')
		i++;
	i--;
	char ch;
	if(a>=b) ;
	else 
	{
		if(b>i) b=i;
		ch=str[a];
		str[a]=str[b];
		str[b]=ch;
		reverse(str,a+1,b-1);
	}
}
