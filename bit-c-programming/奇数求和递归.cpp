#include "stdio.h"
int power(int y)
{
  if(y>0) return y + power(y-2);
  else return 0;
}
int main()
{
  int n;
  scanf("%d",&n);
  printf("%d\n",power(2*n-1));
}
