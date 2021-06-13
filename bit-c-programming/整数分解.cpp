#include "stdio.h"
int fuck(int i, int n)
{
  int x = 0, j = i;
  while(x <= n)
  {
    if(x == n)
    {
      printf("%d~%d\n", i+1, j);
      return 0; 
    }
    else
    {
      x+=++j;
    }
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 0; i<n/2; i++)
  {
    fuck(i, n);
  }

}
