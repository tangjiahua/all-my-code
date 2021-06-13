#include "stdio.h"
int main()
{
  int t, n;
  scanf("%d",&t);
  while(t-- > 0)
  {
    scanf("%d", &n);
    int a[n][2];
    double s = 0, y;
    for(int i = 0; i<n; i++)
    {
      scanf("%d %d", &a[i][0], &a[i][1]);
    }

    for(int i = 0; i<n; i++)
      for(int j = 0; j<n; j++)
        for(int k = 0; k<n; k++)
        {
          y = ( a[i][0]*a[j][1]+a[j][0]*a[k][1]+a[i][1]*a[k][0]-a[k][1]*a[i][0]-a[j][0]*a[i][1]-a[k][0]*a[j][1] )/2.0;
          if(y<0) y = -y;
          if(y > s)
          {
            s = y;
          }
        }
    printf("%.1lf\n",s);
  }
}
