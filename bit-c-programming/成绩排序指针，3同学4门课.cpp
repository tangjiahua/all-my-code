#include "stdio.h"
int main()
{
  int a[3][4];
  for(int i = 0; i<3; i++)
    for(int j = 0; j<4; j++)
      scanf("%d",&a[i][j]);
  int total[3] = {0}, p = 0;
  for(int i = 0; i<3; i++)
  {
    for(int j = 0; j<4; j++)
    {
      total[p] += a[i][j];
    }
    p++;
  }
  int i;
int z[3], max = 0, k = 0;
for(int j = 0; j<3; j++)
{
  for(i = 0; i<3; i++)
  {
    if(total[i]>max)
    {
      z[k] = i;
      max = total[i];
    }

  }

      
    total[z[k]] = 0;
    k++;
    max = 1;
    i = 0;
}
k = 0;
for(int m = 0; m<3; m++)
{


  for(int j = 0; j<4; j++){
    if(j<3)  printf("%d,",a[z[k]][j]);
    else printf("%d\n",a[z[k]][j]);
  }
  k++;
}


}
