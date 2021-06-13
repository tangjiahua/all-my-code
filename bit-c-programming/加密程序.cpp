#include "stdio.h"
struct table
{
  char input;
  char output;
};
struct table translate[ ] = {'a','d','b','w','c','k','d',';','e','i','i','a','k','b',';','c','w','e'};

int main()
{
  char ch;
  int str_long, i;
  str_long = sizeof(translate)/sizeof(struct table);
  while((ch = getchar())!= '\n')
  {
    for (i = 0; translate[i].input!=ch && i<str_long; i++);
    if(i<str_long)
      putchar (translate[i].output);
      else putchar(ch);
  }
}
