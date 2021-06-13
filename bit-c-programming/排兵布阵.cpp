#include "stdio.h"
#include "stdlib.h"
#include "math.h"

long x[100005], y[100005];
long x1[100005];
int comp(const void*a, const void*b)
{
     return *(int *)a - *(int *)b;
}
int main()
{
    long n = 0;
    scanf("%ld",&n);
    long kx, ky;
    long long steps = 0;

    for (long i = 0; i < n; i++)
    {
        x[i] = 0;
        y[i] = 0;
        x1[i] = 0;
    }
    for (long i = 0; i < n; i++)
    {
        scanf("%ld %ld", &x[i], &y[i]);
    }
    qsort(x, n, sizeof(long), comp);
    qsort(y, n, sizeof(long), comp);
    ky = y[n / 2];//ky即为y轴数据中位数

    for (long i = 0; i < n; i++)
    {
        x1[i] = x[i] - i;
    }
    qsort(x1, n, sizeof(long long),comp);
    kx = x1[n / 2];

    for (long i = 0; i < n; i++)
    {
        steps = steps + abs(y[i] - ky);
        steps = steps + abs(x[i] - i - kx);
    }    
    printf("%lld\n", steps);

    return 0;
}
