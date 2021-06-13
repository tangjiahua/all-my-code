#include "stdio.h"
#include "string.h"
int check(char *p, char *q);
int main()
{
  char ch[100];
  while(gets(ch) != NULL)
  {
    int d = strlen(ch);
    int i = check(ch, &ch[d-1]);
    i == 1?printf("Yes\n"):printf("No\n");
  }
}

int check(char *p, char *q)
{
  if(p < q)
  {
    if(*p != *q) return 0;
    else return check(++p, --q);
  }
  else return 1;
}
