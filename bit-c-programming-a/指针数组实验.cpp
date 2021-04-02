#include "stdio.h"
char *strcat( char *str1, char *str2 )
{
    char *p = str1;
    while(*p != '\0')
      p++;
      while(*p++ = *str2 ++) ;
      return (str1);
  }

  int main()
  {
    char a[10], b[10];
    gets(a);
    gets(b);
    printf("%s", strcat(a, b));
  }
