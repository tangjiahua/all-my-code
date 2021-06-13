#include "stdio.h"
#define N 10
int main()
{
  int a[N], top = 0, b[N], j, i, k = 0;
  for(int i = 0; i<N; i++)
  {
    scanf("%d",&a[i]);
  }

  for(i = 0; i<N; i++)
  {
    if(a[i] >= top)
    {
      top = a[i];
      j = i;
    }
  }

  for(i = 0; i<N; i++)
  {
    if(a[i] == top)
    {
      b[k] = i;
      k++;
    }
  }

  for(int l = 0; l<k; l++)
  {
    printf("%d\n",b[l]+1);
  }
}
