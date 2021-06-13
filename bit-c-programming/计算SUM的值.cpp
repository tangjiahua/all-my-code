#include "stdio.h"
double fuck(int n)
{
  if(n == 1) return 1;
  else {
    return 1.0/n + fuck(n-1);
  }
}
int main()
{
  double sum;
  int n;
  scanf("%d",&n);
  printf("sum=%.6lf\n",fuck(n));
}
