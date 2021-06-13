#include "stdio.h"
int gcd(int x, int y);
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF){
		printf("%d\n",gcd(a,b));	
	}

}

int gcd(int x,int y)
{
	if(x>y) return gcd(y, x);
	else if(x<=y && y%x==0)	return x;
	else
	{
		int d = y%x;
		y = x;
		x=d;
	}
	return gcd(x, y);
}
