#include "stdio.h"
#include "math.h"
double f(double x);
int main()
{
	int n,t;
	double sol=50;
	scanf("%d",&n);
	for(t=0;t<n;t++)
	{
		double y,a=0,b=100;
		scanf("%lf",&y);
		if((y<6)||(y>(8*100000000+7*1000000+2*10000+300+6)))
		{
			printf("No solution!\n");
		}
		else
		{
			while(fabs(y-f(sol))>0.0001)
			{
				if(y>f(sol))	a=sol;
				else b=sol;
				sol=(a+b)/2;
			}
			while(fabs(y-f(sol))<=0.0001)
			{
				printf("%.4lf\n",sol);
				break;
			}
		}
	} 
}
double f(double x)
{
	double y;
	y=8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
	return y;
}
