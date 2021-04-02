#include "stdio.h"
int f(int x)
{
  if(x <= 2) return 1;
  if(x > 2){
    return f(x-1)+f(x-2);
  }
  else return -1;
}

int main()
{
  int n,x;
  while(scanf("%d",&n)!=EOF)
  {
    x=0;
    int p = n;
    for(int i=0; i<n; i++, p--)
      x+=f(p);
    printf("the answer is %d\n",x);
  }
}
