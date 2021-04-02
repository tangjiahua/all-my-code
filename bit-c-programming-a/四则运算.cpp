#include "stdio.h"
#include "string.h"
#include "math.h"
int jiajian(char ch[]);
int chengchu(char ch[]);
int n;

int main()
{
  char ch[100];
  gets(ch);
  n = strlen(ch);
  chengchu(ch);
  jiajian(ch);
  printf("%c\n",ch[0]);
}

int jiajian(char ch[])
{
  for(int i = 0; i<n; i++)
  {
    if(ch[i] == '+')
    {
      ch[i-1] = (ch[i-1]-48) + (ch[i+1]-48) +48;
      for(int j = i; j<n-2; j++)
      {
        ch[j] = ch[j+2];
      }
    }
    if(ch[i] == '-')
    {
      ch[i-1] = (ch[i-1]-48) - (ch[i+1]-48) +48;
      for(int j = i; j<n-2; j++)
      {
        ch[j] = ch[j+2];
      }
    }
  }
}

int chengchu(char ch[])
{
  for(int i = 0; i<n; i++)
  {
    if(ch[i] == '*')
    {
      ch[i-1] = (ch[i-1]-48) * (ch[i+1]-48) +48;
      for(int j = i; j<n-2; j++)
      {
        ch[j] = ch[j+2];
      }

    }
    if(ch[i] == '/')
    {
      ch[i-1] = (ch[i-1]-48) / (ch[i+1]-48) + 48;
      for(int j = i; j<n-2; j++)
      {
        ch[j] = ch[j+2];
      }

    }
  }
}
