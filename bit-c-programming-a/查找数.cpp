#include "stdio.h"
int main()
{
  int a[10];
  for(int i = 0; i<10; i++)
  {
    scanf("%d",&a[i]);
  }
  int x;
  scanf("%d",&x);
  int *p = a, count = 0;
  for(int i = 0; i<10; i++)
  {
    if(*p  == x)
    {
      printf("%d\n",x);
      count = 1;
      break;
    }
    else p++;
  }
  if(count == 0) printf("No\n");
}
