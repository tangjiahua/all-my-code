#include "stdio.h"
int main()
{
  char str1[10], str2[10] = {'\0'};
  char *p, *q, ch;
  gets(str1);
  p = str1;
  q = str2;
  while(*p) p++;
  p--;
  while(p >= str1){
    *q++ = *p--;
  }
  puts(str2);
}
