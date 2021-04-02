#include "stdio.h"
int f(int x, int n);
int main()
{
  int n,x;
  while(scanf("%d%d", &x, &n)!=EOF)
  {
    printf("answer is %d",f(x, n));
  }
}
int all;
int f(int x, int n){
  if(n == 1) return x;
  else{
     return x*(1-f(x, n-1));
  }
}
