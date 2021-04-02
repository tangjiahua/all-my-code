#include <stdio.h>  
#include <stdlib.h> 
void reverse(char str[], int start, int end); 
int main( )  
{   char str[100];  
    int start, end;  
    gets(str);  
    scanf("%d%d", &start, &end);  
    reverse( str, start, end );  
    printf("%s\n", str);  
    return 0;  
}  


void reverse(char str[], int start, int end ) 
{
	int d = sizeof(str);
	if(start < end)
	{
		if(str[end] > d)	reverse(str, start, end-1);
		else if(str[start + 1]=='\0') ;
		else
		{
			char change;
			change = str[start];
			str[start] = str[end];
			str[end] = change;
			reverse(str, start + 1, end - 1);
		}
		
	}
}
