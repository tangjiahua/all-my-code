#include "stdio.h"
int f(int x, int y);
int main()
{
  int n;
  while(scanf("%d",&n)!=EOF)
  {
    for(int i=1; i<n+1; i++){
      for(int space=0; space < n-i; space++) printf("   ");
      for(int j=1; j<i+1; j++){
        if(j == 1)  printf("%3d",f(i,j));
        else printf("   %3d",f(i,j));
      }
      printf("\n");
    }
  }
}

int f(int x, int y)
{
  if(y == 0 || y > x) return 0;
  if(y == x || x == 1) return 1;
  return f(x-1, y-1)+f(x-1, y);
}
