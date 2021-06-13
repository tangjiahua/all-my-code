#include "stdio.h"
int power(int x);
int main()
{
  int n;
  scanf("%d",&n);
  printf("%d\n",power(n));
}

int power(int x){
  if(x/10 != 0) return x%10 + power(x/10);
  else return x;
}
