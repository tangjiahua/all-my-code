#include <stdio.h>

int countsub( char *str, char *ss );

main( )
{
    char s1[1000] = {0}, s2[100] = {0};
    gets(s1);
    gets(s2);
    printf("%d\n", countsub( s1, s2 ) );
}
int countsub( char *str, char *subs )
{
  char *str1 = str;
  int i = 0, m = 0, count = 0, p = 0;
  while(*(str + i) != '\0'){
    i++;
  }

  int j = 0;
  while(*(subs + j) != '\0')
    j++;

  int k = 0;
    while(*str != '\0')
    {
      if(k == 1 && (*str != *subs)) break;
      if(*str == *subs)
      {
        k = 1;
        for(int q = 0; q<j; q++)
        {
          if(*(str+q) == *(subs+q)) p++;
          else break;
        }
        if(p == j) count++;
        str+=j;
      }
      if(p != j) str++;
      p = 0;
    }

  return count;
}
