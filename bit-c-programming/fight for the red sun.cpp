#include "stdio.h"
int main()
{
  int n = 1000, d = 1;
  int ch[1000];
  for(int i = 0; i<n; i++)
  {
    int Count =0;
    int m = d;
	while(m)
	{
		m = m/10;
		Count++;
	}
	m = d;
	for(int j = Count; j>0; j--)
	{
		ch[i+j-1] = m%10;
		m /= 10;
	}
	i = i+Count-1;
	d++;
  }
  int x;
  while(scanf("%d",&x)!=EOF)
  {
    printf("%d\n",ch[x-1]);
  }
}
