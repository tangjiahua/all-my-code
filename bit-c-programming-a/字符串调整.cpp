#include "stdio.h"
#include "string.h"
#include "ctype.h"
int main()
{
  char ch[100];
  gets(ch);
  int d = strlen(ch);
  int a = 0, b = d-1;

  while(a < b)
  {
    if(isalpha(ch[a]) == 0)
    {
      a++;
      continue;
    }
    if(isalpha(ch[b]) == 0)
    {
      b--;
      continue;
    }

    if(ch[a] > ch[b])
    {
      char change;
      change = ch[a];
      ch[a] = ch[b];
      ch[b] = change;
      a++;
      b--;
      continue;
    }
    a++;
    b--;

  }

  puts(ch);
}
