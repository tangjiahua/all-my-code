#include <stdio.h>  
  
int is_palindrome(int value);  
  
int main(int argc, char* argv[]) {  
    int n;  
    scanf("%d", &n);  
  
    if (is_palindrome(n))  
        puts("YES");  
    else  
        puts("NO");  
      
    return 0;  
}  
#include "string.h"
# include <stdlib.h>
int is_palindrome(int value)
{
	int l=0,i=0,q=value;

	while (q>0)
    {
        i = i * 10 + q % 10;
        q /= 10;
    }
	
	if (i == value) return 1;
	else return 0;
	
}
