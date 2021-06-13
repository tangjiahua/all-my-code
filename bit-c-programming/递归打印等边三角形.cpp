#include "stdio.h"
void f(char ch, int n);
int main()
{
  int n;
  while(scanf("%d",&n)!=EOF)
  {
    for(int i=0; i<=n; i++){
      f(' ', n-i);
      f('*', 2*i-1);
      printf("\n"); //完全没必要递归啊，算式都想得这么复杂了!
    }
  }
}

void f(char ch, int n){
  if(n>0){
    printf("%c",ch);
    f(ch, n-1);
  }
}
