#include<stdio.h>

int main()
{
  int m,n;
  scanf("%d%d",&m,&n);
  printf("%d\n",f(m,n));
}

int f(int m,int n)
{
  if(n>m) n=m;
  if(m==0&&n!=0) return (1);
  if(m!=0&&n==0) return (0);
  else if(m>=n)
    return(f(m,n-1)+f(m-n,n));
}
