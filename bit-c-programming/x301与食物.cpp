#include "stdio.h"
int main()
{

  long n;
while(scanf("%ld",&n)!=EOF)
{
  long a[n];
  for(long i = 0; i<n; i++)
    scanf("%d",&a[i]);
  long x[n], k = 1; //x为有多少种食物,k为数量
  x[0] = a[0];
  for(long i = 1; i<n; i++)
  {
    for(long p = 0; p<k; p++)
    {
      if(a[i] != x[p])
      {
        x[k] = a[i];
        k++;
        break;
      }
    }
  }

  long location[k];
  long ee = 0;
  for(long i = 0; i<k; i++)
  {
      for(long j = n-1; j>-1; j--)
      {
        if(a[j] == x[i])
        {
          location[i] = ee;
          break;
        }
        else ee++;
      }
      ee = 0;
  }
  
  
  long power = 0, ss;
  for(long i = 0; i<k; i++)
  {
    if(location[i]>power)
    {
      power = location[i];
      ss = i;
    }
  }

  printf("%ld\n",x[ss]);
}
}
