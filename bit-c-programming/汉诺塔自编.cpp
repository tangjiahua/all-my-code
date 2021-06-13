#include "stdio.h"
int main()
{
  int n;       //A柱子上の圆盘数
  while(scanf("%d",&n)!=EOF)
  {
    f(n, 'A', 'B', 'C');
  }
}

void f(int n, char from, char zhong, char to){
  if(n==1){
    printf("move from %c to %c\n",from, to);
  }
  else{
    f(n-1,from, zhong, to);
    printf("move from %c to %c\n",from, to);
    f(n-1, zhong, to, from);
  }
}
