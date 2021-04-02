#include "stdio.h"
int main()
{
  int a[50];
  int n, d = 0, max = 0, first, end;
  int *p;
  int judge = 0;
  scanf("%d",&n);
  for(int k = 0; k<n; k++)
    scanf("%d",&a[k]);
  for(int k = 0; k<n; k++)
  {
    d = 0;
    int l = k;
    p = &a[k];
    while(*(++p) == a[k])
    {
      judge = 1;
      l++;
      d++;
    }
    if(d > max)
    {
      max = d;
      first = k;
      end = l;
    }
  }
  if(judge == 1)
    printf("The longest equal number list is from %d to %d.\n", first, end);
  else
    printf("No equal number list.\n");
}
