#include "stdio.h"
double f(double x, double n);
int main()
{
	double n;
	double x=1;
	scanf("%lf",&n);
	if(n==1) printf("1\n");
	else printf("%.6lf\n",f(x,n-1));
}

double f(double x, double n)
{
	if(n==0) ;
	else if((int)n%2==0)
	{
		x=x-1/(n+1);
		x=f(x, n-1);
	}
	else
	{
		x=x+1/(n+1);
		x=f(x, n-1);
	}
	return x;
} 
