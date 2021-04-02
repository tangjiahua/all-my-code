#include "stdio.h"
#include "string.h"
int main()
{
  int n, i = 0;
  char str[100];
  gets(str);
  n = strlen(str);
  for(int i = 0; i<n; i++){
    if(str[i] == 'n') printf("\n");
    else putchar(str[i]);
	}
}
