#include "stdio.h"
#include "math.h"
#include "string.h"
long k = 0;
int n;
long h(char s[][1000], long b, long m);
int main()
{
  int T;
  scanf("%d",&T);
	getchar();
	for(int o = 0; o<T; o++)
	{

    scanf("%d",&n);
    getchar();
    long b, m;
    scanf("%d %d",&b,&m);
    getchar();
    char s[n][1000];
    for(int i = 0; i<n; i++)
      gets(s[i]);

	h(s,b,m);
}
}

long h(char s[][1000], long b, long m)
{
  long power = 0;
for(int q = 0; q<n; q++)
{
	power = 0;
    int ll = strlen(s[q]);
  for(int j = 0; j<ll; j++)
  {
    power += s[q][j]*pow(b, ll-j);
  }
  power = power % m;
printf("%ld ",power/2);
  }
  return 0;
}
