#include "stdio.h"
int main()
{
  int n, j = 2, m, d = 2;
  char ch;
  scanf("%d,%c",&n,&ch);
  char a[n][2*n-1];

  for(int i = 0; i<n; i++)
    for(int l = 0; l<2*n-1; l++)
      a[i][l] = ' ';
	m = n-1;
  for(int i = 0; i<n; i++)
  {
    if(i == 0)
    {
      a[0][m--] = ch++;
      if(ch>'z') ch = 'a';
      continue;
    }
    if(i < n-1)
    {
      a[i][m] = ch++;
      if(ch>'z') ch = 'a';
      a[i][m+d] = ch++;
      m--;
      d+=2;
      if(ch>'z') ch = 'a';
      j+=2;
      continue;
    }
    if(i == n-1)
    {
      for(int k = 0; k<2*n-1; k++)
      {
        a[i][k] = ch++;
        if(ch>'z') ch = 'a';
      }
    }
  }

  for(int i = 0; i<n; i++)
    for(int l = 0; l<2*n-1; l++)
    {
      if(l == i+n)
      {
      	printf("\n");
      	break;
      }
      else printf("%c",a[i][l]);
    }
  printf("\n");
}
