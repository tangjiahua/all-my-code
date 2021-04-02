#include "stdio.h"
#include "stdlib.h"
struct _ball
{
    long long a;
    long long b;
    long long c;
    long number;
} ball[100005];
int cmp(const void *a, const void *b)
{
    struct _ball x = *(struct _ball *)a;
    struct _ball y = *(struct _ball *)b;
    if(x.a != y.a)
    {
        return x.a - y.a;
    }
    
    else
    {
        if(x.b!=y.b)
            return x.b - y.b;
        
        else
        {
            return x.c - y.c;
        }
        
    }
}
int main()
{
    long n;
    scanf("%ld", &n);
    for (long i = 0; i < n; i++)
    {
        long long t;
        scanf("%lld %lld %lld", &ball[i].a, &ball[i].b, &ball[i].c);
        ball[i].number = i;
        if(ball[i].a < ball[i].b) //改成>
        {
            t = ball[i].a;
            ball[i].a = ball[i].b;
            ball[i].b = t;
        }
        if(ball[i].b < ball[i].c)
        {
            t = ball[i].b;
            ball[i].b = ball[i].c;
            ball[i].c = t;
        }
        if(ball[i].a < ball[i].b)
        {
            t = ball[i].b;
            ball[i].b = ball[i].a;
            ball[i].a = t;
        }
    }
    qsort(ball, n, sizeof(struct _ball), cmp);
    long long max = 0, max1 = 0, max2 = 0;
    long p1, p0, p2;
    for (long i = 0; i < n; i++)
    {
        if(ball[i].c > max)
        {
            max = ball[i].c;
            p0 = ball[i].number;
        }
            
    }
    for (long i = 0; i < n-1; i++)
    {
        if(ball[i].a == ball[i+1].a && ball[i].b == ball[i+1].b)
        {
            max2 = ball[i].c + ball[i + 1].c;
            if(ball[i].b < max2)
            {
                max2 = ball[i].b;
            }
            if(max2 > max1)
            {
                p1 = ball[i].number;
                p2 = ball[i+1].number;
                max1 = max2;
            }
            else
                continue;
        }
    }
    if(max >= max1)
    {
        printf("1\n%ld\n", p0 + 1);
    }
    
    else
    {
        printf("2\n%ld %ld\n", p2 + 1, p1 + 1);
    }
    
}