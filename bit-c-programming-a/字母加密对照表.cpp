#include "stdio.h"
#include "string.h"
int main()
{
  char list[9][2] = {{'a','d'}, {'b','w'}, {'c','k'}, {'d',';'}, {'e','i'}, {'i','a'}, {'k','b'}, {';','c'}, {'w','e'}};
  char ch[100];
  gets(ch);
  int d = strlen(ch);
  int count = 0;
  for(int i = 0; i<d; i++)
  {
    for(int j = 0; j<9; j++)
    {
      if(ch[i] == list[j][0])
      {
        count = 1;
        putchar(list[j][1]);
        break;
      }
    }
    if(count == 0) putchar(ch[i]);
    else count = 0;
  }
  printf("\n");
}
