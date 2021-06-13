#include "stdio.h"
#include "stdlib.h"
struct _shop
{
    long open;
    long close;
    long num;
}shop[200005];
int comp(const void*p1, const void*p2)
{
    struct _shop *c = (struct _shop*)p1;
    struct _shop *d = (struct _shop*)p2;
    if(c->open != d->open)
        return c->open - d->open;
    else
        return c->close - d->close;
}

int main(int argc, char const *argv[])
{
    int flag = 0;
    long n;
    scanf("%ld", &n);
    for (long i = 0; i < n; i++)
    {
        scanf("%ld %ld", &shop[i].open, &shop[i].close);
        shop[i].num = i+1;
    }
    if(n == 1)
    {
        printf("-1\n");
        flag = 1;
        return 0;
    }
    qsort(shop, n, sizeof(struct _shop), comp);
    for (long i = 0; i < n; i++)
    {
        if(shop[i].open == shop[i+1].open)
        {
            printf("%ld\n", shop[i].num);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        for (long i = 0; i < n - 2; i++)
        {
            if(shop[i+2].close > shop[i+1].close && shop[i].close+1 >= shop[i+2].open)
            {
                printf("%ld\n",shop[i+1].num);
                flag = 1;
                break;
            }
            if(shop[i].close >= shop[i+1].close)
            {
                printf("%ld\n",shop[i+1].num);
                flag = 1;
                break;
            }
            if(shop[i+1].close >= shop[i+2].close)
            {
                printf("%ld\n",shop[i+2].num);
                flag = 1;
                break;
            }
            if(shop[i].close >= shop[i+2].close)
            {
                printf("%ld\n",shop[i+2].num);
                flag = 1;
                break;
            }
            
        }
    }
    if(flag == 0)
        printf("-1\n");
        return 0;
}
