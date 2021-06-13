#include "stdio.h"
int main()
{
  int a[3][4];
  for(int i = 0; i<3; i++)
    for(int j = 0; j<4; j++)
      scanf("%d",&a[i][j]);
  int x;
  scanf("%d",&x);
  for(int i = 0; i<4; i++)
    { if(i<3)
      printf("%d ",a[x-1][i]);
      else printf("%d\n",a[x-1][i]);
    }

  double y = 0;
  for(int i = 0; i<4; i++)
    {
      y += a[x-1][i];
    }
  y = y/4.0;
  printf("%.2lf\n",y);
}
