#include "stdio.h"
#define PI 3.1415927
int main(void)
{
	float r,v;
	int i=0,n;
	while(scanf("%f",&r)!=EOF)
	{
		v=4*PI*r*r*r/3;
		printf("%.3f\n",v);
	}

}
