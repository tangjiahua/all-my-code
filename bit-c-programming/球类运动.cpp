#include "stdio.h"
#include "math.h"
#include "stdlib.h"
void quick_sort(double s[], long l, long r);
int cmp(const void*a, const void *b)
{
	double x = *(double*)a, y = *(double*)b;
	return x-y;
}
int main(int argc, char const *argv[])
{
	long T;
	scanf("%ld",&T);
	for(long i = 0; i < T; i++)//i
	{
		long n, x;
		double c;
		scanf("%ld %lf", &n, &c);
		
		int d;
		

		double v[n];
	
		for(long ii = 0; ii < n; ii++)
		{
			scanf("%lf %ld %d", &v[ii], &x, &d);
		
		}
		
		
		qsort(v, n, sizeof(v[0]), cmp);
		
		long q;
		scanf("%ld", &q);
		double vmin;
		for(long z = 0; z < q; z++)
		{
			long t, k = 0, count = 0;
			scanf("%ld %ld",&t, &k);
			

			vmin = (double)sqrt(v[k-1]*v[k-1] + 2*c*t);
			
	
			printf("%.3lf\n", vmin);	
		}

	}
	return 0;
}
